#include "PlaylistsInfoResponse.h"

namespace ymlcpp {
namespace server_access {

PlaylistsInfoResponse::PlaylistsInfoResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::ContentInfoResponse)
{
}

PlaylistsInfoResponse::~PlaylistsInfoResponse()
{

}

void PlaylistsInfoResponse::parseResponse(const QByteArray& data)
{

}

ResponseResult PlaylistsInfoResponse::status() const
{
    return _respResult;
}

}
}
