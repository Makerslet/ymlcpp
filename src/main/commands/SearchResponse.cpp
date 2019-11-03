#include "SearchResponse.h"
#include "common_and_base/parsers/TrackDescriptionParser.h"
#include "common_and_base/parsers/AlbumDescriptionParser.h"
#include "common_and_base/parsers/PlaylistDescriptionParser.h"
#include "common_and_base/parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {


SearchResponse::SearchResponse() :
    ServerResponse (AppResponseType::SearchResponse)
{}

SearchResponse::~SearchResponse(){}

void SearchResponse::parseContent(const QVariant& data)
{
    auto resultFieldHash = data.toHash();
    parseTracks(resultFieldHash);
    parseAlbums(resultFieldHash);
    parsePlaylists(resultFieldHash);
    parseArtists(resultFieldHash);

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

SearchResult SearchResponse::description() const
{
    return _result;
}

}
}
