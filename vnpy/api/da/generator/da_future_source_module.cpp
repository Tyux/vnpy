.def("reqUserLogin", &FutureApi::reqUserLogin)
.def("reqUserLogout", &FutureApi::reqUserLogout)
.def("reqSafeVerify", &FutureApi::reqSafeVerify)
.def("reqVerifyCode", &FutureApi::reqVerifyCode)
.def("reqSetVerifyQA", &FutureApi::reqSetVerifyQA)
.def("reqGetQuestion", &FutureApi::reqGetQuestion)
.def("reqOrderInsert", &FutureApi::reqOrderInsert)
.def("reqOrderModify", &FutureApi::reqOrderModify)
.def("reqOrderCancel", &FutureApi::reqOrderCancel)
.def("reqPasswordUpdate", &FutureApi::reqPasswordUpdate)
.def("reqQryOrder", &FutureApi::reqQryOrder)
.def("reqQryTrade", &FutureApi::reqQryTrade)
.def("reqQryCapital", &FutureApi::reqQryCapital)
.def("reqQryVersion", &FutureApi::reqQryVersion)
.def("reqQryCurrency", &FutureApi::reqQryCurrency)
.def("reqQryExchange", &FutureApi::reqQryExchange)
.def("reqQryPosition", &FutureApi::reqQryPosition)
.def("reqQryStrategy", &FutureApi::reqQryStrategy)
.def("reqQryCommodity", &FutureApi::reqQryCommodity)
.def("reqQryInstrument", &FutureApi::reqQryInstrument)
.def("reqQryExchangeTime", &FutureApi::reqQryExchangeTime)
.def("reqQryCommodityTime", &FutureApi::reqQryCommodityTime)
.def("reqQryTotalPosition", &FutureApi::reqQryTotalPosition)
.def("reqQryStrategyDetail", &FutureApi::reqQryStrategyDetail)

.def("onFrontConnected", &FutureApi::onFrontConnected)
.def("onFrontDisconnected", &FutureApi::onFrontDisconnected)
.def("onHeartBeatWarning", &FutureApi::onHeartBeatWarning)
.def("onRspNeedVerify", &FutureApi::onRspNeedVerify)
.def("onRspUserLogin", &FutureApi::onRspUserLogin)
.def("onRspUserLogout", &FutureApi::onRspUserLogout)
.def("onRspVerifyCode", &FutureApi::onRspVerifyCode)
.def("onRspSafeVerify", &FutureApi::onRspSafeVerify)
.def("onRspSetVerifyQA", &FutureApi::onRspSetVerifyQA)
.def("onRspAccount", &FutureApi::onRspAccount)
.def("onRspQuestion", &FutureApi::onRspQuestion)
.def("onRspOrderInsert", &FutureApi::onRspOrderInsert)
.def("onRspOrderModify", &FutureApi::onRspOrderModify)
.def("onRspOrderCancel", &FutureApi::onRspOrderCancel)
.def("onRspPasswordUpdate", &FutureApi::onRspPasswordUpdate)
.def("onRtnTrade", &FutureApi::onRtnTrade)
.def("onRtnOrder", &FutureApi::onRtnOrder)
.def("onRtnCapital", &FutureApi::onRtnCapital)
.def("onRtnPosition", &FutureApi::onRtnPosition)
.def("onRspQryOrder", &FutureApi::onRspQryOrder)
.def("onRspQryTrade", &FutureApi::onRspQryTrade)
.def("onRspQryCapital", &FutureApi::onRspQryCapital)
.def("onRspQryVersion", &FutureApi::onRspQryVersion)
.def("onRspQryPosition", &FutureApi::onRspQryPosition)
.def("onRspQryCurrency", &FutureApi::onRspQryCurrency)
.def("onRspQryExchange", &FutureApi::onRspQryExchange)
.def("onRspQryStrategy", &FutureApi::onRspQryStrategy)
.def("onRspQryCommodity", &FutureApi::onRspQryCommodity)
.def("onRspQryInstrument", &FutureApi::onRspQryInstrument)
.def("onRspQryExchangeTime", &FutureApi::onRspQryExchangeTime)
.def("onRspQryCommodityTime", &FutureApi::onRspQryCommodityTime)
.def("onRspQryTotalPosition", &FutureApi::onRspQryTotalPosition)
.def("onRspQryStrategyDetail", &FutureApi::onRspQryStrategyDetail)
;
