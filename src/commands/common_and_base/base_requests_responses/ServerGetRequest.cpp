#include "commands/common_and_base/base_requests_responses/ServerGetRequest.h"

namespace ymlcpp {
namespace server_access {

ServerGetRequest::ServerGetRequest(AppRequestType appReqType) :
    _appReqType(appReqType)
{}

ServerGetRequest::~ServerGetRequest()
{}

ServerRequestType ServerGetRequest::serverRequestType() const
{
    return _serverReqType;
}

AppRequestType ServerGetRequest::appRequestType() const
{
    return _appReqType;
}

}
}
