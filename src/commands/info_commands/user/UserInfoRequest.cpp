#include "UserInfoRequest.h"
#include "UserInfoResponse.h"

namespace ymlcpp {
namespace server_access {

const QUrl UserInfoRequest::_userInfoUrl("https://api.music.yandex.net/account/status");

UserInfoRequest::UserInfoRequest(const QString& oauthToken) :
    ServerGetRequest (AppRequestType::UserInfoRequest),
    _oauthToken(oauthToken)
{

}

QNetworkRequest UserInfoRequest::toNetworkRequest() const
{
    QNetworkRequest request(_userInfoUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> UserInfoRequest::createResponse(const QByteArray& data) const
{
    auto response =  QSharedPointer<UserInfoResponse>::create();
    response->parseResponse(data);
    return response.dynamicCast<IServerResponse>();
}

}
}
