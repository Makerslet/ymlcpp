#include "AlbumsInfoResponse.h"
#include "../../common_and_base/common_enums/AppResponseTypes.h"
#include "../../common_and_base/parsers/AlbumDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

AlbumsInfoResponse::AlbumsInfoResponse() :
    ServerResponse(AppResponseType::ContentInfoResponse)
{}

AlbumsInfoResponse::~AlbumsInfoResponse()
{}

void AlbumsInfoResponse::parseContent(const QVariant& data)
{
    for(auto album : data.toList())
        _albums.push_back(AlbumDescriptionParser::parseAlbumDescription(
                              album.toHash()));

}

QList<AlbumDescription> AlbumsInfoResponse::albumsDescription() const
{
    return _albums;
}

}
}
