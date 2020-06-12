 'OnFrontConnected': {},
 'OnRspUserLogin': {'pRspUserLogin': 'CUftRspUserLoginField', 'pRspInfo': 'CUftRspInfoField'},
 'OnAnsOrderInsert': {'pOrderRsp': 'CUftAnsOrderInsertField', 'pError': 'CUftRspErrorField'},
 'OnRspOrderInsert': {'pOrderRsp': 'CUftRspnOrderInsertField', 'pError': 'CUftRspErrorField'},
 'OnAnsOrderAction': {'pOrderAction': 'CUftAnsOrderActionField', 'pError': 'CUftRspErrorField'},
 'OnRspOrderAction': {'pOrderAction': 'CUftRspnOrderActionField', 'pError': 'CUftRspErrorField'},
 'OnOrderRtn': {'pOrder': 'CUftRtnnOrderField'},
 'OnTradeRtn': {'pOrder': 'CUftRtnnTradeField'},
 'OnRspTradingAccount': {'pRspFund': 'CUftAnsQueryFundField'},
 'OnRspError': {'pError': 'CUftRspErrorField'},
 'OnRspQryOrder': {'pEntrust': 'CUftAnsQueryOrderField', 'bIsLast': 'bool'},
 'OnRspQryTrade': {'pTrade': 'CUftAnsQueryTradeField', 'bIsLast': 'bool'},
 'OnRspQryInvestorPosition': {'pInvestorPosition': 'CUftAnsQueryPositionField', 'bIsLast': 'bool'},
 'OnRspQryChangePwd': {},
 'OnRspLogout': {'szMsg': 'char'},
 'OnRtnInstrumentStatus': {'pInstStatus': 'CUftRtnInstrumentStatusField'},
 'OnRspTest': {'pTest': 'CUftRspTest'},
 'OnErrRtnOrderInsert': {'pError': 'CUftRspErrorField'},
 'OnErrRtnOrderAction': {'pError': 'CUftRspErrorField'}}

 'ReqUserLogin': {},
 'ReqUserLogout': {},
 'ReqOrderAction': {'nOrderIndex': 'int', 'nOrderRef': 'int64_t'},
 'ReqTradingAccount': {},
 'ReqQryOrder': {'szInstrumentID': 'char', 'nStartTime': 'int32_t', 'nEndTime': 'int32_t', 'szOrderSysID': 'char', 'nOrderRef': 'int64_t', 'nOrderIndex': 'uint32_t', 'bAllSession': 'bool', 'false': '='},
 'ReqQryTrade': {'szInstrumentID': 'char', 'nStartTime': 'int32_t', 'nEndTime': 'int32_t', 'szOrderSysID': 'char', 'nOrderIndex': 'uint32_t', 'nOrderRef': 'int64_t', 'bAllSession': 'bool', 'false': '='},
 'ReqQryInvestorPosition': {'szInstrumentID': 'char'},
 'ReqChangePwd': {'szNewPwd': 'char', 'szOldPwd': 'char'},
 'ReqQryTest': {}}