# encoding: UTF-8

from datetime import datetime

from pymongo import MongoClient
from collections import OrderedDict, defaultdict

from vnpy.trader.vtObject import VtBarData
from vnpy.trader.vtConstant import DIRECTION_LONG, DIRECTION_SHORT

from turtleStrategy import TurtlePortfolio


DAILY_DB_NAME = 'VnTrader_Daily_Db'



########################################################################
class BacktestingEngine(object):
    """"""

    #----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""
        self.portfolio = None
        self.vtSymbolList = []
        
        self.startDt = None
        self.endDt = None
        self.currentDt = None
        
        self.dataDict = OrderedDict()
        self.tradeDict = OrderedDict()
        
        self.result = None
        self.resultList = []
    
    #----------------------------------------------------------------------
    def setPeriod(self, startDt, endDt):
        """"""
        self.startDt = startDt
        self.endDt = endDt
    
    #----------------------------------------------------------------------
    def initPortfolio(self, vtSymbolList):
        """"""
        self.vtSymbolList = vtSymbolList
        
        self.portfolio = TurtlePortfolio(self)
        self.portfolio.init(vtSymbolList)
    
    #----------------------------------------------------------------------
    def loadData(self):
        """"""
        mc = MongoClient()
        db = mc[DAILY_DB_NAME]
        
        for vtSymbol in self.vtSymbolList:
            flt = {'datetime':{'$gte':self.startDt,
                               '$lte':self.endDt}} 
            
            collection = db[vtSymbol]
            cursor = collection.find(flt).sort('datetime')
            
            for d in cursor:
                bar = VtBarData()
                bar.__dict__ = d
                
                barDict = self.dataDict.setdefault(bar.datetime, OrderedDict())
                barDict[bar.vtSymbol] = bar
            
            self.writeLog(u'%s数据加载完成，总数据量：%s' %(vtSymbol, cursor.count()))
        
        self.writeLog(u'全部数据加载完成')
    
    #----------------------------------------------------------------------
    def runBacktesting(self):
        """"""
        for dt, barDict in self.dataDict.items():
            self.currentDt = dt
            
            result = DailyResult(dt)
            result.updatePos(self.portfolio.posDict)
            
            for bar in barDict.values():
                self.portfolio.onBar(bar)
                result.updateBar(bar)
            
            if self.result:
                result.updatePreviousClose(self.result.closeDict)
            
            self.resultList.append(result)
            self.result = result
    
    #----------------------------------------------------------------------
    def calculateResult(self):
        """"""
        for result in self.resultList:
            result.calculatePnl()
    
    #----------------------------------------------------------------------
    def sendOrder(self, vtSymbol, direction, offset, price, volume):
        """"""
        trade = TradeData(vtSymbol, direction, offset, price, volume)
        l = self.tradeDict.setdefault(self.currentDt, [])        
        l.append(trade)
        
        self.result.updateTrade(trade)

    #----------------------------------------------------------------------
    def writeLog(self, content):
        """"""
        print '%s:%s' %(datetime.now().strftime('%H:%M:%S.%f'), content)
        

########################################################################
class TradeData(object):
    """"""

    #----------------------------------------------------------------------
    def __init__(self, vtSymbol, direction, offset, price, volume):
        """Constructor"""
        self.vtSymbol = vtSymbol
        self.direction = direction
        self.offset = offset
        self.price = price
        self.volume = volume


########################################################################
class DailyResult(object):
    """每日的成交记录"""

    #----------------------------------------------------------------------
    def __init__(self, date):
        """Constructor"""
        self.date = date
        
        self.closeDict = {}                     # 收盘价字典
        self.previousCloseDict = {}             # 昨收盘字典
        
        self.tradeDict = defaultdict(list)      # 成交字典
        self.posDict = {}                       # 持仓字典（开盘时）
        
        self.tradingPnl = 0
        self.holdingPnl = 0
        self.totalPnl = 0
    
    #----------------------------------------------------------------------
    def updateTrade(self, trade):
        """更新交易"""
        l = self.tradeDict[trade.vtSymbol]
        l.append(trade)
        
    #----------------------------------------------------------------------
    def updatePos(self, d):
        """更新昨持仓"""
        self.posDict.update(d)
    
    #----------------------------------------------------------------------
    def updateBar(self, bar):
        """更新K线"""
        self.closeDict[bar.vtSymbol] = bar.close
    
    #----------------------------------------------------------------------
    def updatePreviousClose(self, d):
        """更新昨收盘"""
        self.previousCloseDict.update(d)

    #----------------------------------------------------------------------
    def calculateTradingPnl(self):
        """计算当日交易盈亏"""
        for vtSymbol, l in self.tradeDict.items():
            close = self.closeDict[vtSymbol]
            
            for trade in l:
                if trade.direction == DIRECTION_LONG:
                    side = 1
                else:
                    side = -1
                pnl = (close - trade.price) * trade.volume * side
                self.tradingPnl += pnl
    
    #----------------------------------------------------------------------
    def calculateHoldingPnl(self):
        """计算当日持仓盈亏"""
        for vtSymbol, pos in self.posDict.items():
            previousClose = self.previousCloseDict.get(vtSymbol, 0)
            close = self.closeDict[vtSymbol]
            pnl = (close - previousClose) * pos
            self.holdingPnl += pnl

    #----------------------------------------------------------------------
    def calculatePnl(self):
        """计算总盈亏"""
        self.calculateHoldingPnl()
        self.calculateTradingPnl()
        self.totalPnl = self.holdingPnl + self.tradingPnl
        