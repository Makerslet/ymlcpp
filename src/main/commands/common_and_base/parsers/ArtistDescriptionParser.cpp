#include "ArtistDescriptionParser.h"

namespace ymlcpp {
namespace server_access {


    ArtistDescription ArtistDescriptionParser::parseArtistDescription(const QVariantHash& artistHash)
    {
        ArtistDescription description;
        description.id = artistHash["id"].toString();
        description.name = artistHash["name"].toString();
        description.various = artistHash["various"].toBool();
        description.composer = artistHash["composer"].toBool();
        description.ogImage = artistHash["ogImage"].toString();
        description.available = artistHash["available"].toBool();
        description.ticketsAvailable = artistHash["tickestAvailable"].toBool();
        description.genres = artistHash["genres"].toStringList();

        description.cover = parseArtistCover(artistHash["cover"].toHash());
        description.counts = parseArtistCounts(artistHash["counts"].toHash());
        description.raitings = parseArtistRaitings(artistHash["raitings"].toHash());

        for(auto link : artistHash["links"].toList())
            description.links.push_back(
                        parseArtistLink(link.toHash()));
        return  description;
    }

    ArtistCover ArtistDescriptionParser::parseArtistCover(const QVariantHash& coverHash)
    {
        ArtistCover cover;
        cover.type = coverHash["type"].toString();
        cover.prefix = coverHash["prefix"].toString();
        cover.uri = coverHash["uri"].toString();
        return cover;
    }

    ArtistCounts ArtistDescriptionParser::parseArtistCounts(const QVariantHash& countsHash)
    {
        ArtistCounts counts;
        counts.tracks = countsHash["tracks"].toUInt();
        counts.directAlbums = countsHash["directAlbums"].toUInt();
        counts.alsoAlbums = countsHash["alsoAlbums"].toUInt();
        counts.alsoTracks = countsHash["alsoTracks"].toUInt();
        return counts;
    }

    ArtistRaitings ArtistDescriptionParser::parseArtistRaitings(const QVariantHash& raitingsHash)
    {
        ArtistRaitings raitings;
        raitings.week = raitingsHash["week"].toUInt();
        raitings.month = raitingsHash["month"].toUInt();
        raitings.day = raitingsHash["day"].toUInt();
        return raitings;
    }

    ArtistLink ArtistDescriptionParser::parseArtistLink(const QVariantHash& linkHash)
    {
        ArtistLink link;
        link.title = linkHash["title"].toString();
        link.href = linkHash["href"].toUrl();
        link.type = linkHash["type"].toString();

        if(linkHash.contains("socialNetwork"))
            link.type = linkHash["socialNetwork"].toString();

        return link;
    }

}
}
