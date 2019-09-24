#include "UserDislikesResponse.h"

namespace ymlcpp {
namespace server_access  {

UserDislikeAlbumsResponse::UserDislikeAlbumsResponse(const QByteArray& data) :
    UserChoiceAlbumsResponse(UserChoiceType::Dislike, data)
{}

UserDislikeAlbumsResponse::~UserDislikeAlbumsResponse()
{}


UserDislikeArtistsResponse::UserDislikeArtistsResponse(const QByteArray& data) :
    UserChoiceArtistsResponse(UserChoiceType::Dislike, data)
{}

UserDislikeArtistsResponse::~UserDislikeArtistsResponse()
{}

UserDislikePlaylistsResponse::UserDislikePlaylistsResponse(const QByteArray& data) :
    UserChoicePlaylistsResponse(UserChoiceType::Dislike, data)
{}

UserDislikePlaylistsResponse::~UserDislikePlaylistsResponse()
{}

UserDislikeTracksResponse::UserDislikeTracksResponse(const QByteArray& data) :
    UserChoiceTracksResponse(UserChoiceType::Dislike, data)
{}

UserDislikeTracksResponse::~UserDislikeTracksResponse()
{}

}
}
