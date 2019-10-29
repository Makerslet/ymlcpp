#include "GetFeedResponse.h"
#include "common_and_base/parsers/PlaylistDescriptionParser.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

namespace ymlcpp {
namespace server_access {

GetFeedResponse::GetFeedResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::FeedResponse)
{
    parseResponse(data);
}

GetFeedResponse::~GetFeedResponse(){}

void GetFeedResponse::parseResponse(const QByteArray& data)
{
    // пока что из фида будем доставать только плейлист дня
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        auto resultHash = resultFieldIter.value().toHash();
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
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

ResponseResult GetFeedResponse::status() const
{
    return _respStatus;
}


ErrorInfo GetFeedResponse::errorInfo() const
{
    return _errInfo;
}

void GetFeedResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

QVector<PlaylistWithTracks> GetFeedResponse::description() const
{
    return _playlists;
}

}
}
