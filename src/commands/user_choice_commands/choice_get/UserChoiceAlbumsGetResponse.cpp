#include "commands/user_choice_commands/choice_get/UserChoiceAlbumsGetResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserChoiceAlbumsGetResponse::UserChoiceAlbumsGetResponse(UserChoiceType choiceType) :
    UserChoiceGetResponse (choiceType, ContentType::Albums)
{}

UserChoiceAlbumsGetResponse::~UserChoiceAlbumsGetResponse()
{}

QVector<LikeAlbum> UserChoiceAlbumsGetResponse::userLikes() const
{
    return _userLikes;
}


void UserChoiceAlbumsGetResponse::parseContent(const QVariant& data)
{
    for(auto album : data.toList())
        parseAlbum(album.toHash());
}

void UserChoiceAlbumsGetResponse::parseAlbum(const QVariantHash& albumHash)
{
    LikeAlbum likeAlbum;
    likeAlbum.id = albumHash["id"].toUInt();
    likeAlbum.timestamp = albumHash["timestamp"].toDateTime().toLocalTime();

    _userLikes.push_back(likeAlbum);
}


}
}
