#include "UserDislikesGetResponse.h"

namespace ymlcpp {
namespace server_access  {

UserDislikeAlbumsGetResponse::UserDislikeAlbumsGetResponse(const QByteArray& data) :
    UserChoiceAlbumsGetResponse(UserChoiceType::Dislike, data)
{}

UserDislikeAlbumsGetResponse::~UserDislikeAlbumsGetResponse()
{}


UserDislikeArtistsGetResponse::UserDislikeArtistsGetResponse(const QByteArray& data) :
    UserChoiceArtistsGetResponse(UserChoiceType::Dislike, data)
{}

UserDislikeArtistsGetResponse::~UserDislikeArtistsGetResponse()
{}

UserDislikePlaylistsGetResponse::UserDislikePlaylistsGetResponse(const QByteArray& data) :
    UserChoicePlaylistsGetResponse(UserChoiceType::Dislike, data)
{}

UserDislikePlaylistsGetResponse::~UserDislikePlaylistsGetResponse()
{}

UserDislikeTracksGetResponse::UserDislikeTracksGetResponse(const QByteArray& data) :
    UserChoiceTracksGetResponse(UserChoiceType::Dislike, data)
{}

UserDislikeTracksGetResponse::~UserDislikeTracksGetResponse()
{}

}
}
