#include "UserLikeTracksResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {


UserLikeTracksResponse::UserLikeTracksResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserLikeTracksResponse)
{
    qDebug() << data;
    parseResponse(data);
}

UserLikeTracksResponse::~UserLikeTracksResponse()
{
}

ResponseResult UserLikeTracksResponse::status() const
{
    return _respStatus;
}
UserLikeTracks UserLikeTracksResponse::userLikes() const
{
    return _userLikes;
}

ErrorInfo UserLikeTracksResponse::errorInfo() const
{
    return _errInfo;
}


void UserLikeTracksResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        parseLibrary(resultFieldIter.value().toHash());
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void UserLikeTracksResponse::parseLibrary(const QVariantHash& resultHash)
{
    auto libraryIter = resultHash.find("library");
    if(libraryIter== resultHash.end())
        return;

    auto libraryHash = libraryIter.value().toHash();
    _userLikes.uid = libraryHash["uid"].toUInt();
    _userLikes.revision = libraryHash["revision"].toUInt();

    auto tracks = libraryHash["tracks"].toList();
    for(auto track : tracks)
        parseTrack(track.toHash());

}

void UserLikeTracksResponse::parseTrack(const QVariantHash& trackHash)
{
    Track track;
    track.id = trackHash["id"].toString();
    track.albumId = trackHash["albumId"].toString();
    track.timestamp = trackHash["timestamp"].toDateTime().toLocalTime();

    _userLikes.tracks.push_back(track);
}

void UserLikeTracksResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
