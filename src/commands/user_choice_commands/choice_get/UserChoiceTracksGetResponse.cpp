#include "UserChoiceTracksGetResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


UserChoiceTracksGetResponse::UserChoiceTracksGetResponse(UserChoiceType choiceType) :
    UserChoiceGetResponse (choiceType, ContentType::Tracks)
{}

UserChoiceTracksGetResponse::~UserChoiceTracksGetResponse()
{}

UserLikeTracks UserChoiceTracksGetResponse::userLikes() const
{
    return _userLikes;
}

void UserChoiceTracksGetResponse::parseContent(const QVariant& data)
{
    parseLibrary(data.toHash());
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
