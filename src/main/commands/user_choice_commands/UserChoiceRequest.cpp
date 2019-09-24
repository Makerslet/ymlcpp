#include "UserChoiceRequest.h"
#include "UserLikesResponse.h"
#include "UserDislikesResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

const QString UserChoiceRequest::_templateUrl("https://api.music.yandex.net/users/%1/%2/%3");

UserChoiceRequest::UserChoiceRequest(const QString& oauthToken, const QString& login,
                                     UserChoiceType type, UserChoiceContent content) :
    ServerGetRequest (AppRequestType::UserChoiceRequest),
    _oauthToken(oauthToken),
    _login(login),
    _choiceType(type),
    _choiceContent(content)
{
}

QNetworkRequest UserChoiceRequest::toNetworkRequest() const
{
    QString contentTypeStr;
    switch (_choiceContent) {
    case UserChoiceContent::Albums:     contentTypeStr = "albums";    break;
    case UserChoiceContent::Artists:    contentTypeStr = "artists";   break;
    case UserChoiceContent::Playlists:  contentTypeStr = "playlists";  break;
    case UserChoiceContent::Tracks:     contentTypeStr = "tracks";    break;
    }

    QString choiceTypeStr;
    switch (_choiceType) {
    case UserChoiceType::Like: choiceTypeStr = "likes"; break;
    case UserChoiceType::Dislike: choiceTypeStr = "dislikes"; break;
    }

    QUrl actualUrl = _templateUrl.arg(_login).arg(choiceTypeStr).arg(contentTypeStr);
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> UserChoiceRequest::createResponse(const QByteArray& data) const
{
    if(_choiceType == UserChoiceType::Like)
    {
        switch (_choiceContent) {
        case UserChoiceContent::Albums:     return QSharedPointer<UserLikeAlbumsResponse>::create(data);
        case UserChoiceContent::Artists:    return QSharedPointer<UserLikeArtistsResponse>::create(data);
        case UserChoiceContent::Playlists:  return QSharedPointer<UserLikePlaylistsResponse>::create(data);
        case UserChoiceContent::Tracks:     return QSharedPointer<UserLikeTracksResponse>::create(data);
        }
    }
    else if(_choiceType == UserChoiceType::Dislike)
    {
        switch (_choiceContent) {
        case UserChoiceContent::Albums:     return QSharedPointer<UserDislikeAlbumsResponse>::create(data);
        case UserChoiceContent::Artists:    return QSharedPointer<UserDislikeArtistsResponse>::create(data);
        case UserChoiceContent::Playlists:  return QSharedPointer<UserDislikePlaylistsResponse>::create(data);
        case UserChoiceContent::Tracks:     return QSharedPointer<UserDislikeTracksResponse>::create(data);
        }
    }

}



}
}
