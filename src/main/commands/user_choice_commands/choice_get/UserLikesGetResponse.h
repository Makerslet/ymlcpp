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
    UserLikeAlbumsGetResponse(const QByteArray&);
    ~UserLikeAlbumsGetResponse() override;
};

class UserLikeArtistsGetResponse : public UserChoiceArtistsGetResponse
{
public:
    UserLikeArtistsGetResponse(const QByteArray&);
    ~UserLikeArtistsGetResponse();
};

class UserLikePlaylistsGetResponse : public UserChoicePlaylistsGetResponse
{
public:
    UserLikePlaylistsGetResponse(const QByteArray&);
    ~UserLikePlaylistsGetResponse();
};

class UserLikeTracksGetResponse : public UserChoiceTracksGetResponse
{
public:
    UserLikeTracksGetResponse(const QByteArray&);
    ~UserLikeTracksGetResponse() override;
};

}
}

#endif // USERLIKESGETRESPONSE_H
