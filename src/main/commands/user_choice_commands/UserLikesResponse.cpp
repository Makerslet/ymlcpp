#include "UserLikesResponse.h"

namespace ymlcpp {
namespace server_access  {

UserLikeAlbumsResponse::UserLikeAlbumsResponse(const QByteArray& data) :
    UserChoiceAlbumsResponse (UserChoiceType::Like, data)
{}

UserLikeAlbumsResponse::~UserLikeAlbumsResponse()
{}


UserLikeArtistsResponse::UserLikeArtistsResponse(const QByteArray& data) :
    UserChoiceArtistsResponse (UserChoiceType::Like, data)
{}

UserLikeArtistsResponse::~UserLikeArtistsResponse()
{}

UserLikePlaylistsResponse::UserLikePlaylistsResponse(const QByteArray& data) :
    UserChoicePlaylistsResponse (UserChoiceType::Like, data)
{}

UserLikePlaylistsResponse::~UserLikePlaylistsResponse()
{}

UserLikeTracksResponse::UserLikeTracksResponse(const QByteArray& data) :
    UserChoiceTracksResponse (UserChoiceType::Like, data)
{}

UserLikeTracksResponse::~UserLikeTracksResponse()
{}

}
}
