#include "UserChoiceTracksGetResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {


UserChoiceTracksGetResponse::UserChoiceTracksGetResponse(UserChoiceType choiceType, const QByteArray& data) :
    UserChoiceGetResponse (choiceType, ContentType::Tracks)
{
    qDebug() << data;
    parseResponse(data);
}

UserChoiceTracksGetResponse::~UserChoiceTracksGetResponse()
{
}

UserLikeTracks UserChoiceTracksGetResponse::userLikes() const
{
    return _userLikes;
}

void UserChoiceTracksGetResponse::parseResponse(const QByteArray& data)
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

void UserChoiceTracksGetResponse::parseLibrary(const QVariantHash& resultHash)
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

void UserChoiceTracksGetResponse::parseTrack(const QVariantHash& trackHash)
{
    Track track;
    track.id = trackHash["id"].toString();
    track.albumId = trackHash["albumId"].toString();
    track.timestamp = trackHash["timestamp"].toDateTime().toLocalTime();

    _userLikes.tracks.push_back(track);
}

}
}
