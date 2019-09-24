#include "ServerPostRequest.h"


namespace ymlcpp {
namespace server_access {

ServerPostRequest::ServerPostRequest(AppRequestType appReqType) :
    _appReqType(appReqType)
{

}

ServerPostRequest::~ServerPostRequest()
{

}

ServerRequestType ServerPostRequest::serverRequestType() const
{
    return _serverReqType;
}

AppRequestType ServerPostRequest::appRequestType() const
{
    return _appReqType;
}

}
}
