#ifndef SERVERPOSTREQUEST_H
#define SERVERPOSTREQUEST_H

#include "IServerRequest.h"
#include "IServerResponse.h"

#include "../common_enums/AppRequestTypes.h"

#include <QPair>
#include <QNetworkRequest>
#include <QByteArray>

namespace ymlcpp {
namespace server_access {


class ServerPostRequest : public IServerRequest
{
public:
    ServerPostRequest(AppRequestType);
    ~ServerPostRequest() override;

    ServerRequestType serverRequestType() const override;
    AppRequestType appRequestType() const override;

    virtual QPair<QNetworkRequest, QByteArray> toNetworkRequest() const = 0;

protected:
    QByteArray toApiFormat(const QHash<QString, QString>&) const;
    QByteArray toApiFormat(const QString&, const QStringList&) const;
    QByteArray toApiFormat(const QString&, const QString&, const QStringList&) const;

private:
    const ServerRequestType _serverReqType = ServerRequestType::POST;
    const AppRequestType    _appReqType;
};

}
}

#endif // SERVERPOSTREQUEST_H
