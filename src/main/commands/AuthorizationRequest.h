#ifndef AUTHORIZATIONREQUEST_H
#define AUTHORIZATIONREQUEST_H

#include "ServerPostRequest.h"
#include "headers/AppRequestTypes.h"

#include <QPair>
#include <QNetworkRequest>
#include <QMap>

namespace ymlcpp {
namespace server_access {

class AuthorizationRequest : public ServerPostRequest
{
    enum class Fields {
        GrantType,
        ClientId,
        ClientSecret,
        Username,
        Password
    };

    using RequestFields = QMap<Fields, QString>;
public:
    AuthorizationRequest(const QString& login,
                         const QString& password);

    QPair<QNetworkRequest, QByteArray> toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QNetworkRequest prepareRequest(int payloadLen) const;
    QByteArray preparePayload() const;

    QByteArray toApiFormat(const QHash<QString, QString>&) const;

private:
    const QString _login;
    const QString _password;

    static const QUrl _authUrl;
    static const QString _clientId;
    static const QString _clientSecret;
    static const QString _grantType;

    static const RequestFields _fields;
};

}
}

#endif // AUTHORIZATIONREQUEST_H
