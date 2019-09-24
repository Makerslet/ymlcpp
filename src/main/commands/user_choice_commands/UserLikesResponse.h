#ifndef USERLIKESRESPONSE_H
#define USERLIKESRESPONSE_H

#include "UserChoiceTracksResponse.h"
#include "UserChoiceArtistsResponse.h"
#include "UserChoiceAlbumsResponse.h"
#include "UserChoicePlaylistsResponse.h"

namespace ymlcpp {
namespace server_access {


class UserLikeAlbumsResponse : public UserChoiceAlbumsResponse
{
public:
    UserLikeAlbumsResponse(const QByteArray&);
    ~UserLikeAlbumsResponse() override;
};

class UserLikeArtistsResponse : public UserChoiceArtistsResponse
{
public:
    UserLikeArtistsResponse(const QByteArray&);
    ~UserLikeArtistsResponse();
};

class UserLikePlaylistsResponse : public UserChoicePlaylistsResponse
{
public:
    UserLikePlaylistsResponse(const QByteArray&);
    ~UserLikePlaylistsResponse();
};

class UserLikeTracksResponse : public UserChoiceTracksResponse
{
public:
    UserLikeTracksResponse(const QByteArray&);
    ~UserLikeTracksResponse() override;
};

}
}

#endif // USERLIKESRESPONSE_H
