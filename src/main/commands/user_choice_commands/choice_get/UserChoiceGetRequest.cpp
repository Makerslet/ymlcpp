#include "UserChoiceGetRequest.h"
#include "UserLikesGetResponse.h"
#include "UserDislikesGetResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

const QString UserChoiceGetRequest::_templateUrl("https://api.music.yandex.net/users/%1/%2/%3");

UserChoiceGetRequest::UserChoiceGetRequest(const QString& oauthToken, const QString& login,
                                     UserChoiceType type, ContentType content) :
    ServerGetRequest (AppRequestType::UserChoiceGetRequest),
    _oauthToken(oauthToken),
    _login(login),
    _choiceType(type),
    _choiceContent(content)
{
}

QNetworkRequest UserChoiceGetRequest::toNetworkRequest() const
{
    QString contentTypeStr;
    switch (_choiceContent) {
    case ContentType::Albums:     contentTypeStr = "albums";    break;
    case ContentType::Artists:    contentTypeStr = "artists";   break;
    case ContentType::Playlists:  contentTypeStr = "playlists";  break;
    case ContentType::Tracks:     contentTypeStr = "tracks";    break;
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

QSharedPointer<IServerResponse> UserChoiceGetRequest::createResponse(const QByteArray& data) const
{
    if(_choiceType == UserChoiceType::Like)
    {
        switch (_choiceContent) {
        case ContentType::Albums:     return QSharedPointer<UserLikeAlbumsGetResponse>::create(data);
        case ContentType::Artists:    return QSharedPointer<UserLikeArtistsGetResponse>::create(data);
        case ContentType::Playlists:  return QSharedPointer<UserLikePlaylistsGetResponse>::create(data);
        case ContentType::Tracks:     return QSharedPointer<UserLikeTracksGetResponse>::create(data);
        }
    }
    else if(_choiceType == UserChoiceType::Dislike)
    {
        switch (_choiceContent) {
        case ContentType::Albums:     return QSharedPointer<UserDislikeAlbumsGetResponse>::create(data);
        case ContentType::Artists:    return QSharedPointer<UserDislikeArtistsGetResponse>::create(data);
        case ContentType::Playlists:  return QSharedPointer<UserDislikePlaylistsGetResponse>::create(data);
        case ContentType::Tracks:     return QSharedPointer<UserDislikeTracksGetResponse>::create(data);
        }
    }

}



}
}
