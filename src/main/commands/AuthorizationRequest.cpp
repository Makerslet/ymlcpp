#include "AuthorizationRequest.h"
#include "AuthorizationResponse.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

const QUrl AuthorizationRequest::_authUrl("https://oauth.yandex.ru/token");
const QString AuthorizationRequest::_clientId("23cabbbdc6cd418abb4b39c32c41195d");
const QString AuthorizationRequest::_clientSecret("53bc75238f0c4d08a118e51fe9203300");
const QString AuthorizationRequest::_grantType("password");

const AuthorizationRequest::RequestFields AuthorizationRequest::_fields{
    {Fields::GrantType,     "grant_type"},
    {Fields::ClientId,      "client_id"},
    {Fields::ClientSecret,  "client_secret"},
    {Fields::Username,      "username"},
    {Fields::Password,      "password"}
};

AuthorizationRequest::AuthorizationRequest(const QString &login, const QString &password) :
    ServerPostRequest (AppRequestType::AuthorizationRequest),
    _login(login),
    _password(password)
{

}

QPair<QNetworkRequest, QByteArray> AuthorizationRequest::toNetworkRequest() const
{
    auto payload = preparePayload();
    auto request = prepareRequest(payload.length());
    return qMakePair(request, payload);
}


QSharedPointer<IServerResponse> AuthorizationRequest::createResponse(const QByteArray& payload) const
{
    return QSharedPointer<AuthorizationResponse>::create(payload);
}

QNetworkRequest AuthorizationRequest::prepareRequest(int payloadLen) const
{
    QNetworkRequest request(_authUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, payloadLen);
    return  request;
}

QByteArray AuthorizationRequest::preparePayload() const
{
    QHash<QString, QString> requestData;
    requestData.insert(_fields[Fields::GrantType],      _grantType);
    requestData.insert(_fields[Fields::ClientId],       _clientId);
    requestData.insert(_fields[Fields::ClientSecret],   _clientSecret);
    requestData.insert(_fields[Fields::Username],       _login);
    requestData.insert(_fields[Fields::Password],       _password);

    return toApiFormat(requestData);
}

QByteArray AuthorizationRequest::toApiFormat(const QHash<QString, QString>& data) const
{
    QByteArray result;

    for(auto it = data.begin(); it != data.end(); ++it)
        result.append(QString("%1=%2&").arg(it.key()).arg(it.value()));

    result.remove(result.length() - 1, 1);

    return result;
}


}
}
