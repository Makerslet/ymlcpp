#ifndef USERDISLIKESGETRESPONSE_H
#define USERDISLIKESGETRESPONSE_H

#include "UserChoiceTracksGetResponse.h"
#include "UserChoiceArtistsGetResponse.h"
#include "UserChoiceAlbumsGetResponse.h"
#include "UserChoicePlaylistsGetResponse.h"

namespace ymlcpp {
namespace server_access {


class UserDislikeAlbumsGetResponse : public UserChoiceAlbumsGetResponse
{
public:
    UserDislikeAlbumsGetResponse();
    ~UserDislikeAlbumsGetResponse() override;
};

class UserDislikeArtistsGetResponse : public UserChoiceArtistsGetResponse
{
public:
    UserDislikeArtistsGetResponse();
    ~UserDislikeArtistsGetResponse();
};

class UserDislikePlaylistsGetResponse : public UserChoicePlaylistsGetResponse
{
public:
    UserDislikePlaylistsGetResponse();
    ~UserDislikePlaylistsGetResponse();
};

class UserDislikeTracksGetResponse : public UserChoiceTracksGetResponse
{
public:
    UserDislikeTracksGetResponse();
    ~UserDislikeTracksGetResponse() override;
};

}
}

#endif // USERDISLIKESGETRESPONSE_H
