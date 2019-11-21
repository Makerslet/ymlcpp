#include "commands/GetFeedResponse.h"
#include "parsers/PlaylistDescriptionParser.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

namespace ymlcpp {
namespace server_access {

GetFeedResponse::GetFeedResponse() :
    ServerResponse (AppResponseType::FeedResponse)
{}

GetFeedResponse::~GetFeedResponse(){}

void GetFeedResponse::parseContent(const QVariant& data)
{
    auto resultHash = data.toHash();
    auto generatedPlaylistsIter = resultHash.find("generatedPlaylists");
    for(auto playlist : generatedPlaylistsIter.value().toList())
    {
        PlaylistWithTracks plwt;

        auto playlistHash = playlist.toHash();
        plwt.type = playlistHash["type"].toString();
        plwt.ready = playlistHash["ready"].toBool();

        auto playlistData = playlistHash["data"].toHash();
        plwt.description = PlaylistDescriptionParser::parsePlaylistInfo(playlistData);

        auto tracksIter = playlistData.find("tracks");
        if(tracksIter != playlistData.end())
            for(auto track : tracksIter.value().toList())
            {
                auto trackHash = track.toHash();
                plwt.tracks.push_back(trackHash.find("id").value().toUInt());
            }

        _playlists.push_back(plwt);
    }
}

QVector<PlaylistWithTracks> GetFeedResponse::description() const
{
    return _playlists;
}

}
}
