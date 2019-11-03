#include "SearchResponse.h"
#include "common_and_base/parsers/TrackDescriptionParser.h"
#include "common_and_base/parsers/AlbumDescriptionParser.h"
#include "common_and_base/parsers/PlaylistDescriptionParser.h"
#include "common_and_base/parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {


SearchResponse::SearchResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::SearchResponse)
{
    parseResponse(data);
}

SearchResponse::~SearchResponse(){}

ResponseResult SearchResponse::status() const
{
    return _respStatus;
}

void SearchResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        auto resultFieldHash = resultFieldIter.value().toHash();
        parseTracks(resultFieldHash);
        parseAlbums(resultFieldHash);
        parsePlaylists(resultFieldHash);
        parseArtists(resultFieldHash);
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void SearchResponse::parseTracks(const QVariantHash& rootResult)
{

    auto tracksIter = rootResult.find("tracks");
    if(tracksIter != rootResult.end())
    {
        auto tracksRootHash = tracksIter.value().toHash();
        for(auto track : tracksRootHash["results"].toList())
            _result.tracks.push_back(
                        TrackDescriptionParser::parseTrackDescription(track.toHash()));
    }
}

void SearchResponse::parseAlbums(const QVariantHash& rootResult)
{
    auto albumsIter = rootResult.find("albums");
    if(albumsIter != rootResult.end())
    {
        auto albumsRootHash = albumsIter.value().toHash();
        for(auto album : albumsRootHash["results"].toList())
            _result.albums.push_back(
                        AlbumDescriptionParser::parseAlbumDescription(album.toHash()));
    }
}

void SearchResponse::parsePlaylists(const QVariantHash& rootResult)
{
    auto playlistsIter = rootResult.find("playlists");
    if(playlistsIter != rootResult.end())
    {
        auto playlistsRootHash = playlistsIter.value().toHash();
        for(auto playlist : playlistsRootHash["results"].toList())
            _result.playlists.push_back(
                        PlaylistDescriptionParser::parsePlaylistInfo(playlist.toHash()));
    }
}

void SearchResponse::parseArtists(const QVariantHash& rootResult)
{
    auto artistsIter = rootResult.find("artists");
    if(artistsIter != rootResult.end())
    {
        auto artistsRootHash = artistsIter.value().toHash();
        for(auto artist : artistsRootHash["results"].toList())
            _result.artists.push_back(
                        ArtistDescriptionParser::parseArtistDescription(artist.toHash()));
    }
}


ErrorInfo SearchResponse::errorInfo() const
{
    return _errInfo;
}

void SearchResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

SearchResult SearchResponse::description() const
{
    return _result;
}

}
}
