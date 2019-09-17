#include "AuthorizationResponse.h"
namespace ymlcpp {
namespace server_access {

AuthorizationResponse::AuthorizationResponse(const QByteArray& data)
{
    parseResponse(data);
}

void AuthorizationResponse::parseResponse(const QByteArray& data)
{

}

}
}
