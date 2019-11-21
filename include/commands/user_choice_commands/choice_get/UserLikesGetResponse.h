#ifndef USERLIKESGETRESPONSE_H
#define USERLIKESGETRESPONSE_H

#include "UserChoiceTracksGetResponse.h"
#include "UserChoiceArtistsGetResponse.h"
#include "UserChoiceAlbumsGetResponse.h"
#include "UserChoicePlaylistsGetResponse.h"

namespace ymlcpp {
namespace server_access {


class UserLikeAlbumsGetResponse : public UserChoiceAlbumsGetResponse
{
public:
    UserLikeAlbumsGetResponse();
    ~UserLikeAlbumsGetResponse() override;
};

class UserLikeArtistsGetResponse : public UserChoiceArtistsGetResponse
{
public:
    UserLikeArtistsGetResponse();
    ~UserLikeArtistsGetResponse();
};

class UserLikePlaylistsGetResponse : public UserChoicePlaylistsGetResponse
{
public:
    UserLikePlaylistsGetResponse();
    ~UserLikePlaylistsGetResponse();
};

class UserLikeTracksGetResponse : public UserChoiceTracksGetResponse
{
public:
    UserLikeTracksGetResponse();
    ~UserLikeTracksGetResponse() override;
};

}
}

#endif // USERLIKESGETRESPONSE_H
