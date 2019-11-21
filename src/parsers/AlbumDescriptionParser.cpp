#include "parsers/AlbumDescriptionParser.h"
#include "parsers/ArtistDescriptionParser.h"

namespace ymlcpp {
namespace server_access {


AlbumDescription AlbumDescriptionParser::parseAlbumDescription(const QVariantHash& albumHash)
{
    AlbumDescription description;
    description.id = albumHash["id"].toUInt();
    description.title = albumHash["title"].toString();
    description.year = albumHash["year"].toUInt();
    description.releaseTime = albumHash["releaseDate"].toDateTime().toLocalTime();
    description.coverUri = albumHash["coverHash"].toString();
    description.ogImage = albumHash["ogImage"].toString();
    description.genre = albumHash["genre"].toString();
    description.trackCount = albumHash["trackCount"].toUInt();
    description.recent = albumHash["recent"].toBool();
    description.veryImportant = albumHash["veryImportant"].toBool();
    description.available = albumHash["available"].toBool();
    description.availableForPremiumUsers = albumHash["availableForPremiumUsers"].toBool();
    description.availableForMobile = albumHash["availableForMobile"].toBool();
    description.availablePartially = albumHash["availablePartially"].toBool();

    for(auto buy : albumHash["buy"].toList())
        description.buyDescriptions.push_back(
                    parseBuyAlbumDescription(buy.toHash()));

    for(auto artist : albumHash["artists"].toList())
        description.artists.push_back(
                    ArtistDescriptionParser::parseArtistDescription(
                        artist.toHash()));

    for(auto label : albumHash["labels"].toList())
        description.labels.push_back(
                    parseLabelDescription(label.toHash()));

    for(auto best : albumHash["best"].toList())
        description.bests.push_back(
                    parseBestDescription(best.toHash()));
    return description;
}

BuyAlbumDescription AlbumDescriptionParser::parseBuyAlbumDescription(const QVariantHash& buyHash)
{
    Q_UNUSED(buyHash)
    return BuyAlbumDescription();
}

LabelDescription AlbumDescriptionParser::parseLabelDescription(const QVariantHash& labelHash)
{
    LabelDescription label;
    label.id = labelHash["id"].toUInt();
    label.name = labelHash["name"].toString();
    return label;
}

BestDescription AlbumDescriptionParser::parseBestDescription(const QVariantHash& bestHash)
{
    Q_UNUSED(bestHash);
    return BestDescription();
}

}
}
