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
    UserDislikeAlbumsGetResponse(const QByteArray&);
    ~UserDislikeAlbumsGetResponse() override;
};

class UserDislikeArtistsGetResponse : public UserChoiceArtistsGetResponse
{
public:
    UserDislikeArtistsGetResponse(const QByteArray&);
    ~UserDislikeArtistsGetResponse();
};

class UserDislikePlaylistsGetResponse : public UserChoicePlaylistsGetResponse
{
public:
    UserDislikePlaylistsGetResponse(const QByteArray&);
    ~UserDislikePlaylistsGetResponse();
};

class UserDislikeTracksGetResponse : public UserChoiceTracksGetResponse
{
public:
    UserDislikeTracksGetResponse(const QByteArray&);
    ~UserDislikeTracksGetResponse() override;
};

}
}

#endif // USERDISLIKESGETRESPONSE_H
