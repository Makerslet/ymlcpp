#include "PlaylistsInfoResponse.h"

namespace ymlcpp {
namespace server_access {

PlaylistsInfoResponse::PlaylistsInfoResponse() :
    ServerResponse (AppResponseType::ContentInfoResponse)
{}

PlaylistsInfoResponse::~PlaylistsInfoResponse()
{
}

void PlaylistsInfoResponse::parseContent(const QVariant &)
{
}

}
}
