#include "ArtistsInfoResponse.h"
#include "../../common_and_base/parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

ArtistsInfoResponse::ArtistsInfoResponse() :
    ServerResponse (AppResponseType::ContentInfoResponse)
{}

ArtistsInfoResponse::~ArtistsInfoResponse()
{}

void ArtistsInfoResponse::parseContent(const QVariant& data)
{
    for(auto artist : data.toList())
        _artists.push_back(ArtistDescriptionParser::parseArtistDescription(
                               artist.toHash()));
}

QList<ArtistDescription> ArtistsInfoResponse::artistsDescription() const
{
    return _artists;
}

}
}
