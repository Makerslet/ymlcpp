#ifndef SERVERGETREQUEST_H
#define SERVERGETREQUEST_H

#include "IServerRequest.h"
#include "IServerResponse.h"
#include "../common_enums/AppRequestTypes.h"

#include <QNetworkRequest>

namespace ymlcpp {
namespace server_access {

class ServerGetRequest : public IServerRequest
{
public:
    ServerGetRequest(AppRequestType);
    ~ServerGetRequest() override;

    ServerRequestType serverRequestType() const override;
    AppRequestType appRequestType() const override;

    virtual QNetworkRequest toNetworkRequest() const = 0;

private:
    const ServerRequestType _serverReqType = ServerRequestType::GET;
    const AppRequestType    _appReqType;
};

}
}

#endif // SERVERGETREQUEST_H
