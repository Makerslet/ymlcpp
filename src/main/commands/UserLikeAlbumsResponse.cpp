#include "UserLikeAlbumsResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserLikeAlbumsResponse::UserLikeAlbumsResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserLikeAlbumsResponse)
{
    qDebug() << data;
    parseResponse(data);
}

UserLikeAlbumsResponse::~UserLikeAlbumsResponse()
{

}

ResponseResult UserLikeAlbumsResponse::status() const
{
    return _respStatus;
}
QVector<LikeAlbum> UserLikeAlbumsResponse::userLikes() const
{
    return _userLikes;
}

ErrorInfo UserLikeAlbumsResponse::errorInfo() const
{
    return _errInfo;
}


void UserLikeAlbumsResponse::parseResponse(const QByteArray& data)
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

void UserLikeAlbumsResponse::parseAlbum(const QVariantHash& albumHash)
{
    LikeAlbum likeAlbum;
    likeAlbum.id = albumHash["id"].toUInt();
    likeAlbum.timestamp = albumHash["timestamp"].toDateTime().toLocalTime();

    _userLikes.push_back(likeAlbum);
}

void UserLikeAlbumsResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
