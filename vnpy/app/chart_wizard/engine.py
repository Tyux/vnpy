""""""
from datetime import datetime
from threading import Thread

from vnpy.event import Event, EventEngine
from vnpy.trader.engine import BaseEngine, MainEngine
from vnpy.trader.constant import Interval
from vnpy.trader.object import HistoryRequest
from vnpy.trader.rqdata import rqdata_client


APP_NAME = "ChartWizard"

EVENT_CHART_HISTORY = "eChartHistory"


class ChartWizardEngine(BaseEngine):
    """"""

    def __init__(self, main_engine: MainEngine, event_engine: EventEngine):
        """"""
        super().__init__(main_engine, event_engine, APP_NAME)

        n = rqdata_client.init()
        print(n)

    def query_history(
        self,
        vt_symbol: str,
        interval: Interval,
        start: datetime,
        end: datetime
    ) -> None:
        """"""
        thread = Thread(
            target=self._query_history,
            args=[vt_symbol, interval, start, end]
        )
        thread.start()

    def _query_history(
        self,
        vt_symbol: str,
        interval: Interval,
        start: datetime,
        end: datetime
    ) -> None:
        """"""
        contract = self.main_engine.get_contract(vt_symbol)

        req = HistoryRequest(
            symbol=contract.symbol,
            exchange=contract.exchange,
            interval=interval,
            start=start,
            end=end
        )

        data = rqdata_client.query_history(req)
        event = Event(EVENT_CHART_HISTORY, data)
        self.event_engine.put(event)
