from typing import List, Dict, Set, Union
from copy import copy
from collections import defaultdict

from vnpy.event import Event
from vnpy.trader.ui import QtWidgets, QtCore, QtGui
from vnpy.trader.ui.widget import COLOR_BID, COLOR_ASK, COLOR_BLACK
from vnpy.trader.event import (
    EVENT_TICK, EVENT_TRADE, EVENT_POSITION, EVENT_TIMER
)
from vnpy.trader.utility import round_to
from ..engine import OptionEngine
from ..base import UnderlyingData, OptionData, ChainData, PortfolioData


COLOR_WHITE = QtGui.QColor("white")
COLOR_POS = QtGui.QColor("yellow")
COLOR_GREEKS = QtGui.QColor("cyan")


class MonitorCell(QtWidgets.QTableWidgetItem):
    """"""

    def __init__(self, text: str = "", vt_symbol: str = ""):
        """"""
        super().__init__(text)

        self.vt_symbol = vt_symbol

        self.setTextAlignment(QtCore.Qt.AlignCenter)


class StrikeCell(MonitorCell):
    """"""

    def __init__(self, text: str = "", vt_symbol: str = ""):
        """"""
        super().__init__(text, vt_symbol)

        self.setForeground(COLOR_BLACK)
        self.setBackground(COLOR_WHITE)


class BidCell(MonitorCell):
    """"""

    def __init__(self, text: str = "", vt_symbol: str = ""):
        """"""
        super().__init__(text, vt_symbol)

        self.setForeground(COLOR_BID)


class AskCell(MonitorCell):
    """"""

    def __init__(self, text: str = "", vt_symbol: str = ""):
        """"""
        super().__init__(text, vt_symbol)

        self.setForeground(COLOR_ASK)


class PosCell(MonitorCell):
    """"""

    def __init__(self, text: str = "", vt_symbol: str = ""):
        """"""
        super().__init__(text, vt_symbol)

        self.setForeground(COLOR_POS)


class GreeksCell(MonitorCell):
    """"""

    def __init__(self, text: str = "", vt_symbol: str = ""):
        """"""
        super().__init__(text, vt_symbol)

        self.setForeground(COLOR_GREEKS)


class MonitorTable(QtWidgets.QTableWidget):
    """"""

    def __init__(self):
        """"""
        super().__init__()


class OptionMarketMonitor(MonitorTable):
    """"""
    signal_tick = QtCore.pyqtSignal(Event)
    signal_trade = QtCore.pyqtSignal(Event)
    signal_position = QtCore.pyqtSignal(Event)

    headers: List[Dict] = [
        {"name": "vt_symbol", "display": "代码", "cell": MonitorCell},
        {"name": "theo_vega", "display": "Vega", "cell": GreeksCell},
        {"name": "theo_theta", "display": "Theta", "cell": GreeksCell},
        {"name": "theo_gamma", "display": "Gamma", "cell": GreeksCell},
        {"name": "theo_delta", "display": "Delta", "cell": GreeksCell},
        {"name": "bid_impv", "display": "买隐波", "cell": BidCell},
        {"name": "bid_volume", "display": "买量", "cell": BidCell},
        {"name": "bid_price", "display": "买价", "cell": BidCell},
        {"name": "ask_price", "display": "卖价", "cell": AskCell},
        {"name": "ask_volume", "display": "卖量", "cell": AskCell},
        {"name": "ask_impv", "display": "卖隐波", "cell": AskCell},
        {"name": "net_pos", "display": "净持仓", "cell": PosCell},
    ]

    def __init__(self, option_engine: OptionEngine, portfolio_name: str):
        """"""
        super().__init__()

        self.option_engine = option_engine
        self.event_engine = option_engine.event_engine
        self.portfolio_name = portfolio_name

        self.cells: Dict[str, Dict] = {}
        self.option_symbols: Set[str] = set()
        self.underlying_option_map: Dict[str, List] = defaultdict(list)

        self.init_ui()
        self.register_event()

    def init_ui(self):
        """"""
        self.setWindowTitle("T型报价")
        self.verticalHeader().setVisible(False)
        self.setEditTriggers(self.NoEditTriggers)

        # Store option and underlying symbols
        portfolio = self.option_engine.get_portfolio(self.portfolio_name)

        for option in portfolio.options.values():
            self.option_symbols.add(option.vt_symbol)
            self.underlying_option_map[option.underlying.vt_symbol].append(option.vt_symbol)

        # Set table row and column numbers
        row_count = 0
        for chain in portfolio.chains.values():
            row_count += (1 + len(chain.strike_prices))
        self.setRowCount(row_count)

        column_count = len(self.headers) * 2 + 1
        self.setColumnCount(column_count)

        call_labels = [d["display"] for d in self.headers]
        put_labels = copy(call_labels)
        put_labels.reverse()
        labels = call_labels + ["行权价"] + put_labels
        self.setHorizontalHeaderLabels(labels)

        # Init cells
        strike_column = len(self.headers)
        current_row = 0

        chain_symbols = list(portfolio.chains.keys())
        chain_symbols.sort()

        for chain_symbol in chain_symbols:
            chain = portfolio.get_chain(chain_symbol)

            self.setItem(
                current_row,
                strike_column,
                StrikeCell(chain.chain_symbol.split(".")[0])
            )

            for strike_price in chain.strike_prices:
                call = chain.calls[strike_price]
                put = chain.puts[strike_price]

                current_row += 1

                # Call cells
                call_cells = {}

                for column, d in enumerate(self.headers):
                    value = getattr(call, d["name"], "")
                    cell = d["cell"](
                        text=str(value),
                        vt_symbol=call.vt_symbol
                    )
                    self.setItem(current_row, column, cell)
                    call_cells[d["name"]] = cell

                self.cells[call.vt_symbol] = call_cells

                # Put cells
                put_cells = {}
                put_headers = copy(self.headers)
                put_headers.reverse()

                for column, d in enumerate(put_headers):
                    column += (strike_column + 1)
                    value = getattr(put, d["name"], "")
                    cell = d["cell"](
                        text=str(value),
                        vt_symbol=put.vt_symbol
                    )
                    self.setItem(current_row, column, cell)
                    put_cells[d["name"]] = cell

                self.cells[put.vt_symbol] = put_cells

                # Strike cell
                strike_cell = StrikeCell(str(call.strike_price))
                self.setItem(current_row, strike_column, strike_cell)

            # Move to next row
            current_row += 1

        # Additional table adjustment
        horizontal_header = self.horizontalHeader()
        horizontal_header.setSectionResizeMode(horizontal_header.Fixed)
        horizontal_header.setSectionResizeMode(strike_column, horizontal_header.ResizeToContents)
        horizontal_header.setSectionResizeMode(0, horizontal_header.ResizeToContents)
        horizontal_header.setSectionResizeMode(self.columnCount() - 1, horizontal_header.ResizeToContents)

    def register_event(self):
        """"""
        self.signal_tick.connect(self.process_tick_event)
        self.signal_trade.connect(self.process_trade_event)
        self.signal_position.connect(self.process_position_event)

        self.event_engine.register(EVENT_TICK, self.signal_tick.emit)
        self.event_engine.register(EVENT_TRADE, self.signal_trade.emit)
        self.event_engine.register(EVENT_POSITION, self.signal_position.emit)

    def process_tick_event(self, event: Event):
        """"""
        tick = event.data

        if tick.vt_symbol in self.option_symbols:
            self.update_price(tick.vt_symbol)
            self.update_impv(tick.vt_symbol)
        elif tick.vt_symbol in self.underlying_option_map:
            option_symbols = self.underlying_option_map[tick.vt_symbol]

            for vt_symbol in option_symbols:
                self.update_impv(vt_symbol)
                self.update_greeks(vt_symbol)

    def process_trade_event(self, event: Event):
        """"""
        trade = event.data
        self.update_pos(trade.vt_symbol)

    def process_position_event(self, event: Event):
        """"""
        position = event.data
        self.update_pos(position.vt_symbol)

    def update_pos(self, vt_symbol: str):
        """"""
        option_cells = self.cells.get(vt_symbol, None)
        if not option_cells:
            return

        option = self.option_engine.get_instrument(vt_symbol)

        option_cells["net_pos"].setText(str(option.net_pos))

    def update_price(self, vt_symbol: str):
        """"""
        option_cells = self.cells.get(vt_symbol, None)
        if not option_cells:
            return

        option = self.option_engine.get_instrument(vt_symbol)
        tick = option.tick

        option_cells["bid_price"].setText(str(tick.bid_price_1))
        option_cells["bid_volume"].setText(str(tick.bid_volume_1))
        option_cells["ask_price"].setText(str(tick.ask_price_1))
        option_cells["ask_volume"].setText(str(tick.ask_volume_1))

    def update_impv(self, vt_symbol: str):
        """"""
        option_cells = self.cells.get(vt_symbol, None)
        if not option_cells:
            return

        option = self.option_engine.get_instrument(vt_symbol)
        option_cells["bid_impv"].setText(f"{option.bid_impv * 100:.2f}")
        option_cells["ask_impv"].setText(f"{option.ask_impv * 100:.2f}")

    def update_greeks(self, vt_symbol: str):
        """"""
        option_cells = self.cells.get(vt_symbol, None)
        if not option_cells:
            return

        option = self.option_engine.get_instrument(vt_symbol)

        option_cells["theo_delta"].setText(f"{option.theo_delta:.0f}")
        option_cells["theo_gamma"].setText(f"{option.theo_gamma:.0f}")
        option_cells["theo_theta"].setText(f"{option.theo_theta:.0f}")
        option_cells["theo_vega"].setText(f"{option.theo_vega:.0f}")

    def scroll_to_middle(self):
        """"""
        strike_column = len(self.headers)
        item = self.item(0, int(strike_column))
        self.scrollToItem(
            item,
            QtWidgets.QAbstractItemView.PositionAtCenter
        )

    def resizeEvent(self, event: QtGui.QResizeEvent):
        """"""
        self.scroll_to_middle()
        event.accept()


class OptionGreeksMonitor(MonitorTable):
    """"""
    signal_tick = QtCore.pyqtSignal(Event)
    signal_trade = QtCore.pyqtSignal(Event)
    signal_position = QtCore.pyqtSignal(Event)

    headers: List[Dict] = [
        {"name": "long_pos", "display": "多仓", "cell": PosCell},
        {"name": "short_pos", "display": "空仓", "cell": PosCell},
        {"name": "net_pos", "display": "净仓", "cell": PosCell},
        {"name": "pos_delta", "display": "Delta", "cell": GreeksCell},
        {"name": "pos_gamma", "display": "Gamma", "cell": GreeksCell},
        {"name": "pos_theta", "display": "Theta", "cell": GreeksCell},
        {"name": "pos_vega", "display": "Vega", "cell": GreeksCell}
    ]

    ROW_DATA = Union[OptionData, UnderlyingData, ChainData, PortfolioData]

    def __init__(self, option_engine: OptionEngine, portfolio_name: str):
        """"""
        super().__init__()

        self.option_engine = option_engine
        self.event_engine = option_engine.event_engine
        self.portfolio_name = portfolio_name

        self.cells: Dict[str, Dict] = {}
        self.option_symbols: Set[str] = set()
        self.underlying_option_map: Dict[str, List] = defaultdict(list)

        self.init_ui()
        self.register_event()

    def init_ui(self):
        """"""
        self.setWindowTitle("希腊值风险")
        self.verticalHeader().setVisible(False)
        self.setEditTriggers(self.NoEditTriggers)

        # Store option and underlying symbols
        portfolio = self.option_engine.get_portfolio(self.portfolio_name)

        for option in portfolio.options.values():
            self.option_symbols.add(option.vt_symbol)
            self.underlying_option_map[option.underlying.vt_symbol].append(option.vt_symbol)

        # Set table row and column numbers
        row_count = 1
        for chain in portfolio.chains.values():
            row_count += (1 + len(chain.strike_prices) * 2)
        self.setRowCount(row_count)

        column_count = len(self.headers) + 1
        self.setColumnCount(column_count)

        labels = ["代码"] + [d["display"] for d in self.headers]
        self.setHorizontalHeaderLabels(labels)

        # Init cells
        row_names = [self.portfolio_name]
        row_names.append("")

        underlying_symbols = list(portfolio.underlyings.keys())
        underlying_symbols.sort()
        row_names.extend(underlying_symbols)
        row_names.append("")

        chain_symbols = list(portfolio.chains.keys())
        chain_symbols.sort()
        row_names.extend(chain_symbols)
        row_names.append("")

        option_symbols = list(portfolio.options.keys())
        option_symbols.sort()
        row_names.extend(option_symbols)

        for row, row_name in enumerate(row_names):
            if not row_name:
                continue

            row_cells = {}

            name = row_name.split(".")[0]
            name_cell = MonitorCell(name)
            self.setItem(row, 0, name_cell)

            for column, d in enumerate(self.headers):
                cell = d["cell"]()
                self.setItem(row, column + 1, cell)
                row_cells[d["name"]] = cell
            self.cells[row_name] = row_cells

            if row_name != self.portfolio_name:
                self.hideRow(row)

        self.resizeColumnToContents(0)

    def register_event(self):
        """"""
        self.signal_tick.connect(self.process_tick_event)
        self.signal_trade.connect(self.process_trade_event)
        self.signal_position.connect(self.process_position_event)

        self.event_engine.register(EVENT_TICK, self.signal_tick.emit)
        self.event_engine.register(EVENT_TRADE, self.signal_trade.emit)
        self.event_engine.register(EVENT_POSITION, self.signal_position.emit)

    def process_tick_event(self, event: Event):
        """"""
        tick = event.data

        if tick.vt_symbol not in self.underlying_option_map:
            return

        self.update_underlying_tick(tick.vt_symbol)

    def process_trade_event(self, event: Event):
        """"""
        trade = event.data
        if trade.vt_symbol not in self.cells:
            return

        self.update_pos(trade.vt_symbol)

    def process_position_event(self, event: Event):
        """"""
        position = event.data
        if position.vt_symbol not in self.cells:
            return

        self.update_pos(position.vt_symbol)

    def update_underlying_tick(self, vt_symbol: str):
        """"""
        underlying = self.option_engine.get_instrument(vt_symbol)
        self.update_row(vt_symbol, underlying)

        for chain in underlying.chains.values():
            self.update_row(chain.chain_symbol, chain)

            for option in chain.options.values():
                self.update_row(option.vt_symbol, option)

        portfolio = underlying.portfolio
        self.update_row(portfolio.name, portfolio)

    def update_pos(self, vt_symbol: str):
        """"""
        instrument = self.option_engine.get_instrument(vt_symbol)
        self.update_row(vt_symbol, instrument)

        # For option, greeks of chain also needs to be updated.
        if isinstance(instrument, OptionData):
            chain = instrument.chain
            self.update_row(chain.chain_symbol, chain)

        portfolio = instrument.portfolio
        self.update_row(portfolio.name, portfolio)

    def update_row(self, row_name: str, row_data: ROW_DATA):
        """"""
        row_cells = self.cells[row_name]
        row = self.row(row_cells["long_pos"])

        # Hide rows with no existing position
        if not row_data.long_pos and not row_data.short_pos:
            if row_name != self.portfolio_name:
                self.hideRow(row)
            return

        self.showRow(row)

        row_cells["long_pos"].setText(f"{row_data.long_pos}")
        row_cells["short_pos"].setText(f"{row_data.short_pos}")
        row_cells["net_pos"].setText(f"{row_data.net_pos}")
        row_cells["pos_delta"].setText(f"{row_data.pos_delta:.0f}")

        if not isinstance(row_data, UnderlyingData):
            row_cells["pos_gamma"].setText(f"{row_data.pos_gamma:.0f}")
            row_cells["pos_theta"].setText(f"{row_data.pos_theta:.0f}")
            row_cells["pos_vega"].setText(f"{row_data.pos_vega:.0f}")


class OptionChainMonitor(MonitorTable):
    """"""
    signal_timer = QtCore.pyqtSignal(Event)

    def __init__(self, option_engine: OptionEngine, portfolio_name: str):
        """"""
        super().__init__()

        self.option_engine = option_engine
        self.event_engine = option_engine.event_engine
        self.portfolio_name = portfolio_name

        self.cells: Dict[str, Dict] = {}

        self.init_ui()
        self.register_event()

    def init_ui(self):
        """"""
        self.setWindowTitle("期权链跟踪")
        self.verticalHeader().setVisible(False)
        self.setEditTriggers(self.NoEditTriggers)

        # Store option and underlying symbols
        portfolio = self.option_engine.get_portfolio(self.portfolio_name)

        # Set table row and column numbers
        self.setRowCount(len(portfolio.chains))

        labels = ["期权链", "剩余交易日", "标的物", "升贴水"]
        self.setColumnCount(len(labels))
        self.setHorizontalHeaderLabels(labels)

        # Init cells
        chain_symbols = list(portfolio.chains.keys())
        chain_symbols.sort()

        for row, chain_symbol in enumerate(chain_symbols):
            chain = portfolio.chains[chain_symbol]
            adjustment_cell = MonitorCell()
            underlying_cell = MonitorCell()

            self.setItem(row, 0, MonitorCell(chain.chain_symbol.split(".")[0]))
            self.setItem(row, 1, MonitorCell(str(chain.days_to_expiry)))
            self.setItem(row, 2, underlying_cell)
            self.setItem(row, 3, adjustment_cell)

            self.cells[chain.chain_symbol] = {
                "underlying": underlying_cell,
                "adjustment": adjustment_cell
            }

        # Additional table adjustment
        horizontal_header = self.horizontalHeader()
        horizontal_header.setSectionResizeMode(horizontal_header.Stretch)

    def register_event(self):
        """"""
        self.signal_timer.connect(self.process_timer_event)

        self.event_engine.register(EVENT_TIMER, self.signal_timer.emit)

    def process_timer_event(self, event: Event):
        """"""
        portfolio = self.option_engine.get_portfolio(self.portfolio_name)

        for chain in portfolio.chains.values():
            underlying: UnderlyingData = chain.underlying

            underlying_symbol: str = underlying.vt_symbol.split(".")[0]
            adjustment = round_to(
                chain.underlying_adjustment, underlying.pricetick
            )

            chain_cells = self.cells[chain.chain_symbol]
            chain_cells["underlying"].setText(underlying_symbol)
            chain_cells["adjustment"].setText(str(adjustment))
