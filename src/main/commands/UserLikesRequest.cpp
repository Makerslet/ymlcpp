#include "UserLikesRequest.h"
#include "UserLikeAlbumsResponse.h"
#include "UserLikeArtistsResponse.h"
#include "UserLikePlaylistsResponse.h"
#include "UserLikeTracksResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

const QString UserLikesRequest::_templateUrl("https://api.music.yandex.net/users/%1/likes/%2");

UserLikesRequest::UserLikesRequest(const QString& oauthToken, const QString& login, LikesType likesType) :
    ServerGetRequest (AppRequestType::UserLikesRequest),
    _oauthToken(oauthToken),
    _login(login),
    _likesType(likesType)
{
}

QNetworkRequest UserLikesRequest::toNetworkRequest() const
{
    QString likesTypeStr;
    switch (_likesType) {
    case LikesType::Albums:     likesTypeStr = "albums";    break;
    case LikesType::Artists:    likesTypeStr = "artists";   break;
    case LikesType::Playlists:  likesTypeStr = "playlists";  break;
    case LikesType::Tracks:     likesTypeStr = "tracks";    break;
    }

    QUrl actualUrl = _templateUrl.arg(_login).arg(likesTypeStr);
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> UserLikesRequest::createResponse(const QByteArray& data) const
{
    switch (_likesType) {
    case LikesType::Albums:     return QSharedPointer<UserLikeAlbumsResponse>::create(data);
    case LikesType::Artists:    return QSharedPointer<UserLikeArtistsResponse>::create(data);
    case LikesType::Playlists:  return QSharedPointer<UserLikePlaylistsResponse>::create(data);
    case LikesType::Tracks:     return QSharedPointer<UserLikeTracksResponse>::create(data);
    }
}



}
}
