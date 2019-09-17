#include "ResponseCreator.h"

#include "AuthorizationResponse.h"
namespace ymlcpp {
namespace server_access {


QSharedPointer<IServerResponse> ResponseCreator::createResponse(AppRequestType type, const QByteArray& data)
{
    switch (type) {
    case AppRequestType::AuthorizationRequest: return QSharedPointer<AuthorizationResponse>::create(data);
    default: return QSharedPointer<IServerResponse>();
    }
}

}
}
