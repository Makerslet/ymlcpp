#include "parsers/BestParser.h"
#include "parsers/AlbumDescriptionParser.h"
#include "parsers/ArtistDescriptionParser.h"
#include "parsers/PlaylistDescriptionParser.h"
#include "parsers/TrackDescriptionParser.h"


namespace ymlcpp {
namespace server_access {

QSharedPointer<ContentBase> BestParser::parseBest(const QVariantHash& arg)
{
    QSharedPointer<ContentBase> result;

    ContentType content = UserChoiceConvertor::contentTypeFromString(arg["type"].toString());
    auto resultHash = arg["result"].toHash();

    switch (content) {
    case ContentType::Albums:
        result = QSharedPointer<AlbumDescription>::create(
                    AlbumDescriptionParser::parseAlbumDescription(resultHash));
        break;
    case ContentType::Artists:{
        result = QSharedPointer<ArtistDescription>::create(
                    ArtistDescriptionParser::parseArtistDescription(resultHash));
        break;
    }
    case ContentType::Playlists:
        result = QSharedPointer<PlaylistInfo>::create(
                    PlaylistDescriptionParser::parsePlaylistInfo(resultHash));
        break;
    case ContentType::Tracks:
        result = QSharedPointer<TrackDescription>::create(
                    TrackDescriptionParser::parseTrackDescription(resultHash));
        break;
    case ContentType::Unknown:
        break;
    }

    return result;
}

}
}
