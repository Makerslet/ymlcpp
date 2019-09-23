#ifndef USERLIKEPLAYLISTSRESPONSE_H
#define USERLIKEPLAYLISTSRESPONSE_H

#include "headers/IServerResponse.h"

namespace ymlcpp {
namespace server_access {

struct UserLikePlaylists
{

};

class UserLikePlaylistsResponse : public IServerResponse
{
public:
    UserLikePlaylistsResponse(const QByteArray&);
    ~UserLikePlaylistsResponse() override;

    ResponseResult status() const override;
    UserLikePlaylists userLikes() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;

private:
    ResponseResult _respStatus;
    UserLikePlaylists _userLikes;
    ErrorInfo _errInfo;
};

}
}

#endif // USERLIKEPLAYLISTSRESPONSE_H
