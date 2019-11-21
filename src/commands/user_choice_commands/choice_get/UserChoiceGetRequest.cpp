#include "commands/user_choice_commands/choice_get/UserChoiceGetRequest.h"
#include "commands/user_choice_commands/choice_get/UserLikesGetResponse.h"
#include "commands/user_choice_commands/choice_get/UserDislikesGetResponse.h"

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
    QSharedPointer<IServerResponse> response;
    if(_choiceType == UserChoiceType::Like)
    {
        switch (_choiceContent) {
        case ContentType::Albums:     response = QSharedPointer<UserLikeAlbumsGetResponse>::create(); break;
        case ContentType::Artists:    response = QSharedPointer<UserLikeArtistsGetResponse>::create(); break;
        case ContentType::Playlists:  response = QSharedPointer<UserLikePlaylistsGetResponse>::create(); break;
        case ContentType::Tracks:     response = QSharedPointer<UserLikeTracksGetResponse>::create(); break;
        }
    }
    else if(_choiceType == UserChoiceType::Dislike)
    {
        switch (_choiceContent) {
        case ContentType::Albums:     response = QSharedPointer<UserDislikeAlbumsGetResponse>::create(); break;
        case ContentType::Artists:    response = QSharedPointer<UserDislikeArtistsGetResponse>::create(); break;
        case ContentType::Playlists:  response = QSharedPointer<UserDislikePlaylistsGetResponse>::create(); break;
        case ContentType::Tracks:     response = QSharedPointer<UserDislikeTracksGetResponse>::create(); break;
        }
    }
    response->parseResponse(data);
    return response;
}



}
}
