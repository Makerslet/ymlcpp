#include "PlaylistsInfoResponse.h"
#include <QDebug>

namespace ymlcpp {
namespace server_access {

PlaylistsInfoResponse::PlaylistsInfoResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::ContentInfoResponse)
{
    qDebug() << data;
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
