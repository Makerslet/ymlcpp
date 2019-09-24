#include "UserChoiceAlbumsResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserChoiceAlbumsResponse::UserChoiceAlbumsResponse(UserChoiceType choiceType, const QByteArray& data) :
    UserChoiceResponse (choiceType, UserChoiceContent::Albums)
{
    parseResponse(data);
}

UserChoiceAlbumsResponse::~UserChoiceAlbumsResponse()
{

}

QVector<LikeAlbum> UserChoiceAlbumsResponse::userLikes() const
{
    return _userLikes;
}


void UserChoiceAlbumsResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        for(auto album : resultFieldIter.value().toList())
            parseAlbum(album.toHash());
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void UserChoiceAlbumsResponse::parseAlbum(const QVariantHash& albumHash)
{
    LikeAlbum likeAlbum;
    likeAlbum.id = albumHash["id"].toUInt();
    likeAlbum.timestamp = albumHash["timestamp"].toDateTime().toLocalTime();

    _userLikes.push_back(likeAlbum);
}


}
}
