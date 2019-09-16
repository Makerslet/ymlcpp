#ifndef AUTHORIZATIONREQUEST_H
#define AUTHORIZATIONREQUEST_H

#include "ServerPostRequest.h"
#include "headers/AppRequestTypes.h"

#include <QPair>
#include <QNetworkRequest>

namespace ymlcpp {
namespace server_access {

class AuthorizationRequest : public ServerPostRequest
{
public:
    AuthorizationRequest(const QString& login,
                         const QString& password);

    QPair<QNetworkRequest, QByteArray> toNetworkRequest() const override;


private:
    QNetworkRequest prepareRequest(int payloadLen) const;
    QByteArray preparePayload() const;

    QByteArray toApiFormat(const QHash<QString, QString>&) const;

private:
    const QString _login;
    const QString _password;
};

}
}

#endif // AUTHORIZATIONREQUEST_H
