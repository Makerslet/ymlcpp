#include "parsers/TrackDescriptionParser.h"
#include "parsers/ArtistDescriptionParser.h"
#include "parsers/AlbumDescriptionParser.h"

namespace ymlcpp {
namespace server_access {

TrackDescription TrackDescriptionParser::parseTrackDescription(const QVariantHash& trackHash)
{
    TrackDescription track;
    track.id = trackHash["id"].toString();
    track.realId = trackHash["realId"].toString();
    track.title = trackHash["title"].toString();
    track.major = parseMajorDescription(trackHash["major"].toHash());
    track.available = trackHash["available"].toBool();
    track.availableForPremiumUsers = trackHash["availableForPremiumUsers"].toBool();
    track.availableFullWithoutPermission = trackHash["availableFullWithoutPermission"].toBool();
    track.durationMs = trackHash["durationMs"].toUInt();
    track.storageDir = trackHash["storageDir"].toString();
    track.fileSize = trackHash["fileSize"].toUInt();
    track.normalization = parseNormalizationDescription(trackHash["normalization"].toHash());
    track.previewDurationMs = trackHash["previewDurationMs"].toUInt();
    track.coverUri = trackHash["coverUri"].toString();
    track.ogImage = trackHash["ogImage"].toString();
    track.lyricsAvailable = trackHash["lyricsAvailable"].toBool();
    track.type = trackHash["type"].toString();

    auto artists = trackHash["artists"].toList();
    for(auto artist : trackHash["artists"].toList())
        track.artists.push_back(
                    ArtistDescriptionParser::parseArtistDescription(
                        artist.toHash()));

    for(auto album : trackHash["albums"].toList())
        track.albums.push_back(
                    AlbumDescriptionParser::parseAlbumDescription(
                        album.toHash()));

    return track;
}

MajorDescription TrackDescriptionParser::parseMajorDescription(const QVariantHash& majorHash)
{
    MajorDescription major;
    major.id = majorHash["id"].toUInt();
    major.name = majorHash["name"].toString();
    return major;
}

NormalizationDescription TrackDescriptionParser::parseNormalizationDescription(const QVariantHash& normHash)
{
    NormalizationDescription norm;
    norm.gain = normHash["gain"].toDouble();
    norm.peak = normHash["peak"].toUInt();
    return norm;
}

}
}
