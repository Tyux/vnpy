from typing import Dict
from vnpy.event.engine import Event
from datetime import datetime

from vnpy.trader.engine import (
    MainEngine,
    EventEngine,
    BaseEngine
)
from vnpy.trader.event import EVENT_ORDER, EVENT_TIMER, EVENT_TRADE
from vnpy.trader.object import OrderData, TradeData
from vnpy.trader.utility import load_json, save_json

from .base import ContractResult, PortfolioResult


APP_NAME = "PortfolioManager"


class PortfolioEngine(BaseEngine):
    """"""
    setting_filename = "portfolio_manager_settting.json"
    data_filename = "portfolio_manager_data.json"

    def __init__(self, main_engine: MainEngine, event_engine: EventEngine):
        """"""
        super().__init__(main_engine, event_engine, APP_NAME)

        self.get_tick = self.main_engine.get_tick
        self.get_contract = self.main_engine.get_contract

        self.order_reference_map: Dict[str, str] = {}
        self.contract_results: Dict[str, ContractResult] = {}
        self.portfolio_results: Dict[str, PortfolioResult] = {}

        self.timer_count: int = 0
        self.timer_interval: int = 5

        self.load_setting()
        self.load_data()
        self.register_event()

    def register_event(self) -> None:
        """"""
        self.event_engine.register(EVENT_ORDER, self.process_order_event)
        self.event_engine.register(EVENT_TRADE, self.process_trade_event)
        self.event_engine.register(EVENT_TIMER, self.process_timer_event)

    def process_order_event(self, event: Event) -> None:
        """"""
        order: OrderData = event.data
        self.order_reference_map[order.vt_orderid] = order.reference

    def process_trade_event(self, event: Event) -> None:
        """"""
        trade: TradeData = event.data

        reference = self.order_reference_map.get(trade.vt_orderid, "")
        if not reference:
            return

        vt_symbol = trade.vt_symbol
        key = (reference, vt_symbol)

        contract_result = self.contract_results.get(key, None)
        if not contract_result:
            contract_result = ContractResult(self, reference, vt_symbol)
            self.contract_results[key] = contract_result

        contract_result.update_trade(trade)

    def process_timer_event(self, event: Event) -> None:
        """"""
        self.timer_count += 1
        if self.timer_count < self.timer_interval:
            return
        self.timer_count = 0

        for portfolio_result in self.portfolio_results.values():
            portfolio_result.clear_pnl()

        for contract_result in self.contract_results.values():
            contract_result.calculate_pnl()

            portfolio_result = self.get_portfolio_result(contract_result.reference)
            portfolio_result.trading_pnl += contract_result.trading_pnl
            portfolio_result.holding_pnl += contract_result.holding_pnl

    def load_data(self) -> None:
        """"""
        data = load_json(self.data_filename)
        today = datetime.now().strftime("%Y-%m-%d")
        date_changed = False

        for key, d in data.items():
            reference, vt_symbol = key.split(",")

            if data["date"] == today:
                pos = d["open_pos"]
            else:
                pos = d["last_pos"]
                date_changed = True

            self.contract_results[(reference, vt_symbol)] = ContractResult(
                self,
                reference,
                vt_symbol,
                pos
            )

        # Re-save latest data if date changed
        if date_changed:
            self.save_data()

    def save_data(self) -> None:
        """"""
        data = {"date": datetime.now().strftime("%Y-%m-%d")}

        for contract_result in self.contract_results.values():
            key = f"{contract_result.reference},{contract_result.vt_symbol}"
            data[key] = {
                "open_pos": contract_result.open_pos,
                "last_pos": contract_result.last_pos
            }

        save_json(self.data_filename, data)

    def load_setting(self) -> None:
        """"""
        setting = load_json(self.setting_filename)
        if "timer_interval" in setting:
            self.timer_interval = setting["timer_interval"]

    def save_setting(self) -> None:
        """"""
        setting = {"timer_interval": self.timer_interval}
        save_json(self.setting_filename, setting)

    def close(self) -> None:
        """"""
        self.save_setting()
        self.save_data()

    def get_portfolio_result(self, reference: str) -> PortfolioResult:
        """"""
        portfolio_result = self.portfolio_results.get(reference, None)
        if not portfolio_result:
            portfolio_result = PortfolioResult(reference)
            self.portfolio_results[reference] = portfolio_result
        return portfolio_result
