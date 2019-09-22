#include "UserLikesRequest.h"
#include "UserLikesResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

const QString UserLikesRequest::_templateUrl("https://api.music.yandex.net/users/%1/likes/tracks");

UserLikesRequest::UserLikesRequest(const QString& oauthToken, const QString& login) :
    ServerGetRequest (AppRequestType::UserLikesRequest),
    _oauthToken(oauthToken),
    _login(login)
{
}

QNetworkRequest UserLikesRequest::toNetworkRequest() const
{
    QUrl actualUrl = _templateUrl.arg(_login);
    qDebug() << actualUrl;
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> UserLikesRequest::createResponse(const QByteArray& data) const
{
    return QSharedPointer<UserLikesResponse>::create(data);
}



}
}
