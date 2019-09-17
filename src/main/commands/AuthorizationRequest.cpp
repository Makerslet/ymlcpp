#include "AuthorizationRequest.h"
#include "AuthorizationResponse.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

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
    QUrl serviceUrl("https://oauth.yandex.ru/token");
    QNetworkRequest request(serviceUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, payloadLen);
    return  request;
}

QByteArray AuthorizationRequest::preparePayload() const
{
    QHash<QString, QString> requestData;
    requestData.insert("grant_type", "password");
    requestData.insert("client_id", "23cabbbdc6cd418abb4b39c32c41195d");
    requestData.insert("client_secret", "53bc75238f0c4d08a118e51fe9203300");
    requestData.insert("username", "yamustest@yandex.ru");
    requestData.insert("password", "123456789a");

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
