.def("initialize", &MdApi::initialize)
.def("login", &MdApi::login)
.def("stop", &MdApi::stop)
.def("subscribeDepthMarketData", &MdApi::subscribeDepthMarketData)
.def("subscribeMarketData", &MdApi::subscribeMarketData)
.def("subscribeIndexData", &MdApi::subscribeIndexData)
.def("unSubscribeDepthMarketData", &MdApi::unSubscribeDepthMarketData)
.def("unSubscribeMarketData", &MdApi::unSubscribeMarketData)
.def("unSubscribeIndexData", &MdApi::unSubscribeIndexData)
.def("subscribeOrderQueue", &MdApi::subscribeOrderQueue)
.def("unSubscribeOrderQueue", &MdApi::unSubscribeOrderQueue)
.def("subscribeStepTrade", &MdApi::subscribeStepTrade)
.def("unSubscribeStepTrade", &MdApi::unSubscribeStepTrade)
.def("subscribeStepOrder", &MdApi::subscribeStepOrder)
.def("unSubscribeStepOrder", &MdApi::unSubscribeStepOrder)
.def("subscribeBaseInfo", &MdApi::subscribeBaseInfo)
.def("unSubscribeBaseInfo", &MdApi::unSubscribeBaseInfo)
.def("subscribeKline", &MdApi::subscribeKline)
.def("unSubscribeKline", &MdApi::unSubscribeKline)
.def("subscribeFutures", &MdApi::subscribeFutures)
.def("unSubscribeFutures", &MdApi::unSubscribeFutures)
.def("subscribeEtfExt", &MdApi::subscribeEtfExt)
.def("unSubscribeEtfExt", &MdApi::unSubscribeEtfExt)

.def("onLog", &MdApi::onLog)
.def("onDisconnect", &MdApi::onDisconnect)
.def("onSubscribe", &MdApi::onSubscribe)
.def("onUnSubscribe", &MdApi::onUnSubscribe)
.def("onDepthMarketData", &MdApi::onDepthMarketData)
.def("onMarketData", &MdApi::onMarketData)
.def("onIndexData", &MdApi::onIndexData)
.def("onOrderQueue", &MdApi::onOrderQueue)
.def("onSHTrade", &MdApi::onSHTrade)
.def("onSZTrade", &MdApi::onSZTrade)
.def("onSZOrder", &MdApi::onSZOrder)
.def("onSHBaseInfo", &MdApi::onSHBaseInfo)
.def("onKline", &MdApi::onKline)
.def("onEtfExtData", &MdApi::onEtfExtData)
;
