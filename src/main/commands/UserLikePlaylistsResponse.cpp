#include "UserLikePlaylistsResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserLikePlaylistsResponse::UserLikePlaylistsResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserLikePlaylistsResponse)
{
    qDebug() << data;
    parseResponse(data);
}

UserLikePlaylistsResponse::~UserLikePlaylistsResponse()
{
}

ResponseResult UserLikePlaylistsResponse::status() const
{
    return _respStatus;
}
UserLikePlaylists UserLikePlaylistsResponse::userLikes() const
{
    return _userLikes;
}

ErrorInfo UserLikePlaylistsResponse::errorInfo() const
{
    return _errInfo;
}


void UserLikePlaylistsResponse::parseResponse(const QByteArray& data)
{

}

}
}
