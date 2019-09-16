#ifndef SERVERPOSTREQUEST_H
#define SERVERPOSTREQUEST_H

#include "headers/IServerRequest.h"
#include "headers/AppRequestTypes.h"

#include <QPair>
#include <QNetworkRequest>

namespace ymlcpp {
namespace server_access {


class ServerPostRequest : public IServerRequest
{
public:
    ServerPostRequest(AppRequestType appReqType);
    ~ServerPostRequest() override;

    ServerRequestType serverRequestType() const override;
    AppRequestType appRequestType() const override;

    virtual QPair<QNetworkRequest, QByteArray> toNetworkRequest() const = 0;

private:
    const ServerRequestType _serverReqType = ServerRequestType::POST;
    const AppRequestType    _appReqType;
};

}
}

#endif // SERVERPOSTREQUEST_H
