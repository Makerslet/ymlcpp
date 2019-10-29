#include "PlaylistDescriptionParser.h"

namespace ymlcpp {
namespace server_access {

PlaylistDescription PlaylistDescriptionParser::parsePlaylistDescription(const QVariantHash& descrHash)
{
    PlaylistDescription description;
    description.description = parsePlaylistInfo(descrHash["playlist"].toHash());
    description.timestamp = descrHash["timestamp"].toDateTime().toLocalTime();
    return description;
}

PlaylistInfo PlaylistDescriptionParser::parsePlaylistInfo(const QVariantHash& infoHash)
{
    PlaylistInfo info;

    info.uid = infoHash["uid"].toUInt();
    info.kind = infoHash["kind"].toUInt();
    info.title = infoHash["title"].toString();
    info.description = infoHash["description"].toString();
    info.descriptionFormatted = infoHash["descriptionFormatted"].toString();
    info.revision = infoHash["revision"].toUInt();
    info.snapshot = infoHash["snapshot"].toUInt();
    info.trackCount = infoHash["trackCount"].toUInt();
    info.visibility = infoHash["visibility"].toString();
    info.collective = infoHash["collective"].toBool();
    info.created = infoHash["created"].toDateTime().toLocalTime();
    info.modified = infoHash["modified"].toDateTime().toLocalTime();
    info.available = infoHash["available"].toBool();
    info.isBanner = infoHash["isBanner"].toBool();
    info.isPremiere = infoHash["isPremiere"].toBool();
    info.idForFrom = infoHash["idForFrom"].toString();
    info.durationMs = infoHash["durationMs"].toUInt();
    info.ogImage = infoHash["ogImage"].toString();
    info.tags = infoHash["tags"].toStringList();
    info.prerolls = infoHash["prerolls"].toStringList();

    info.owner = parsePlaylistOwner(infoHash["owner"].toHash());
    info.cover = parsePlaylistCover(infoHash["cover"].toHash());

    return info;
}

PlaylistOwner PlaylistDescriptionParser::parsePlaylistOwner(const QVariantHash& ownerHash)
{
    PlaylistOwner owner;

    owner.uid = ownerHash["uid"].toUInt();
    owner.login = ownerHash["login"].toString();
    owner.name = ownerHash["name"].toString();
    owner.sex = ownerHash["sex"].toString();
    owner.verified = ownerHash["verified"].toBool();

    return owner;
}

PlaylistCover PlaylistDescriptionParser::parsePlaylistCover(const QVariantHash& coverHash)
{
    PlaylistCover cover;

    cover.type = coverHash["type"].toString();
    cover.dir = coverHash["dir"].toString();
    cover.version = coverHash["version"].toString();
    cover.uri = coverHash["uri"].toString();
    cover.custom = coverHash["custom"].toBool();

    return cover;
}

}
}
