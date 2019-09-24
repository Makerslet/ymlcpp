#ifndef USERDISLIKESRESPONSE_H
#define USERDISLIKESRESPONSE_H

#include "UserChoiceTracksResponse.h"
#include "UserChoiceArtistsResponse.h"
#include "UserChoiceAlbumsResponse.h"
#include "UserChoicePlaylistsResponse.h"

namespace ymlcpp {
namespace server_access {


class UserDislikeAlbumsResponse : public UserChoiceAlbumsResponse
{
public:
    UserDislikeAlbumsResponse(const QByteArray&);
    ~UserDislikeAlbumsResponse() override;
};

class UserDislikeArtistsResponse : public UserChoiceArtistsResponse
{
public:
    UserDislikeArtistsResponse(const QByteArray&);
    ~UserDislikeArtistsResponse();
};

class UserDislikePlaylistsResponse : public UserChoicePlaylistsResponse
{
public:
    UserDislikePlaylistsResponse(const QByteArray&);
    ~UserDislikePlaylistsResponse();
};

class UserDislikeTracksResponse : public UserChoiceTracksResponse
{
public:
    UserDislikeTracksResponse(const QByteArray&);
    ~UserDislikeTracksResponse() override;
};

}
}

#endif // USERDISLIKESRESPONSE_H
