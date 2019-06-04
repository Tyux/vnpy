#include <iostream>
#include <string>
#include <pybind11/pybind11.h>
#include <autocxxpy/autocxxpy.hpp>

#include "module.hpp"
#include "wrappers.hpp"
#include "generated_functions.h"

#include "TORATstpMdApi.h"
#include "TORATstpTraderApi.h"
#include "TORATstpUserApiDataType.h"
#include "TORATstpUserApiStruct.h"


void generate_class_CTORATstpMdApi(pybind11::object & parent)
{
    pybind11::class_<
        CTORATstpMdApi,
        std::unique_ptr<CTORATstpMdApi, pybind11::nodelete>,
        PyCTORATstpMdApi
    > c(parent, "CTORATstpMdApi");
    if constexpr (std::is_default_constructible_v<PyCTORATstpMdApi>)
        c.def(pybind11::init<>());
    c.def_static("CreateTstpMdApi",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::CreateTstpMdApi
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def_static("GetApiVersion",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::GetApiVersion
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("Release",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::Release
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("Init",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::Init
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("Join",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::Join
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("RegisterFront",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::RegisterFront
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("RegisterNameServer",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::RegisterNameServer
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("RegisterDeriveServer",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::RegisterDeriveServer
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("RegisterSpi",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::RegisterSpi
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("SubscribeMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::SubscribeMarketData
            >, 
            brigand::list<
                autocxxpy::indexed_transform_holder<autocxxpy::string_array_transform, 0 + 1/*self*/>
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("UnSubscribeMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::UnSubscribeMarketData
            >, 
            brigand::list<
                autocxxpy::indexed_transform_holder<autocxxpy::string_array_transform, 0 + 1/*self*/>
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("SubscribeSpecialMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::SubscribeSpecialMarketData
            >, 
            brigand::list<
                autocxxpy::indexed_transform_holder<autocxxpy::string_array_transform, 0 + 1/*self*/>
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("UnSubscribeSpecialMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::UnSubscribeSpecialMarketData
            >, 
            brigand::list<
                autocxxpy::indexed_transform_holder<autocxxpy::string_array_transform, 0 + 1/*self*/>
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("SubscribeFundsFlowMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::SubscribeFundsFlowMarketData
            >, 
            brigand::list<
                autocxxpy::indexed_transform_holder<autocxxpy::string_array_transform, 0 + 1/*self*/>
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("UnSubscribeFundsFlowMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::UnSubscribeFundsFlowMarketData
            >, 
            brigand::list<
                autocxxpy::indexed_transform_holder<autocxxpy::string_array_transform, 0 + 1/*self*/>
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("ReqUserLogin",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::ReqUserLogin
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("ReqUserLogout",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpMdApi::ReqUserLogout
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    AUTOCXXPY_POST_REGISTER_CLASS(tag_vntora, CTORATstpMdApi, c);
    module_vntora::objects.emplace("CTORATstpMdApi", c);
}
void generate_class_CTORATstpTraderSpi(pybind11::object & parent)
{
    pybind11::class_<CTORATstpTraderSpi, PyCTORATstpTraderSpi> c(parent, "CTORATstpTraderSpi");
    if constexpr (std::is_default_constructible_v<PyCTORATstpTraderSpi>)
        c.def(pybind11::init<>());
    c.def("OnFrontConnected",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnFrontConnected
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnFrontDisconnected",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnFrontDisconnected
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspError",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspError
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspUserLogin",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspUserLogin
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspUserLogout",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspUserLogout
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspUserPasswordUpdate",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspUserPasswordUpdate
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInputDeviceSerial",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInputDeviceSerial
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspOrderInsert",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspOrderInsert
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnOrder",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnOrder
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnErrRtnOrderInsert",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnErrRtnOrderInsert
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspOrderAction",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspOrderAction
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnErrRtnOrderAction",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnErrRtnOrderAction
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnTrade",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnTrade
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnMarketStatus",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnMarketStatus
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspCondOrderInsert",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspCondOrderInsert
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnCondOrder",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnCondOrder
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnErrRtnCondOrderInsert",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnErrRtnCondOrderInsert
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspCondOrderAction",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspCondOrderAction
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnErrRtnCondOrderAction",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnErrRtnCondOrderAction
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInquiryJZFund",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInquiryJZFund
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspTransferFund",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspTransferFund
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnTransferFund",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnTransferFund
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnErrRtnTransferFund",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnErrRtnTransferFund
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnTransferPosition",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnTransferPosition
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnErrRtnTransferPosition",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnErrRtnTransferPosition
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspTransferCollateral",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspTransferCollateral
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInquiryBankAccountFund",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInquiryBankAccountFund
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInquiryTradeConcentration",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInquiryTradeConcentration
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnTradingNotice",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnTradingNotice
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInquiryMaxOrderVolume",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInquiryMaxOrderVolume
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRtnPeripheryTransferPosition",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRtnPeripheryTransferPosition
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInquiryHistoryOrder",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInquiryHistoryOrder
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspInquiryHistoryTrade",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspInquiryHistoryTrade
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryExchange",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryExchange
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryMarketData
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQrySecurity",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQrySecurity
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryETFFile",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryETFFile
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryETFBasket",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryETFBasket
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryIPOInfo",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryIPOInfo
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryBUProxy",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryBUProxy
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryUser",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryUser
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryInvestor",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryInvestor
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryShareholderAccount",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryShareholderAccount
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryOrder",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryOrder
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryOrderAction",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryOrderAction
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryTrade",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryTrade
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryTradingAccount",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryTradingAccount
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryPosition",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryPosition
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryTradingFee",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryTradingFee
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryInvestorTradingFee",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryInvestorTradingFee
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryIPOQuota",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryIPOQuota
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryMarket",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryMarket
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryOrderFundDetail",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryOrderFundDetail
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryFundTransferDetail",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryFundTransferDetail
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryPositionTransferDetail",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryPositionTransferDetail
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryPledgePosition",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryPledgePosition
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryPledgeInfo",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryPledgeInfo
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryConversionBondInfo",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryConversionBondInfo
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryBondPutbackInfo",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryBondPutbackInfo
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryStandardBondPosition",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryStandardBondPosition
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQrySpecialMarketData",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQrySpecialMarketData
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryPrematurityRepoOrder",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryPrematurityRepoOrder
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryShareholderParam",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryShareholderParam
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryPeripheryPositionTransferDetail",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryPeripheryPositionTransferDetail
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryInvestorCondOrderLimitParam",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryInvestorCondOrderLimitParam
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryCondOrder",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryCondOrder
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryCondOrderAction",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryCondOrderAction
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryTradingNotice",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryTradingNotice
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryIPONumberResult",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryIPONumberResult
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    c.def("OnRspQryIPOMatchNumberResult",
        autocxxpy::apply_function_transform<
            autocxxpy::function_constant<
                &CTORATstpTraderSpi::OnRspQryIPOMatchNumberResult
            >, 
            brigand::list<
            >
        >::value,
        pybind11::return_value_policy::reference,
        pybind11::call_guard<pybind11::gil_scoped_release>()
    );
    AUTOCXXPY_POST_REGISTER_CLASS(tag_vntora, CTORATstpTraderSpi, c);
    module_vntora::objects.emplace("CTORATstpTraderSpi", c);
}
