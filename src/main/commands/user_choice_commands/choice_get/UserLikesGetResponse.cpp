#include "UserLikesGetResponse.h"

namespace ymlcpp {
namespace server_access  {

UserLikeAlbumsGetResponse::UserLikeAlbumsGetResponse() :
    UserChoiceAlbumsGetResponse (UserChoiceType::Like)
{}

UserLikeAlbumsGetResponse::~UserLikeAlbumsGetResponse()
{}


UserLikeArtistsGetResponse::UserLikeArtistsGetResponse() :
    UserChoiceArtistsGetResponse (UserChoiceType::Like)
{}

UserLikeArtistsGetResponse::~UserLikeArtistsGetResponse()
{}

UserLikePlaylistsGetResponse::UserLikePlaylistsGetResponse() :
    UserChoicePlaylistsGetResponse (UserChoiceType::Like)
{}

UserLikePlaylistsGetResponse::~UserLikePlaylistsGetResponse()
{}

UserLikeTracksGetResponse::UserLikeTracksGetResponse() :
    UserChoiceTracksGetResponse (UserChoiceType::Like)
{}

UserLikeTracksGetResponse::~UserLikeTracksGetResponse()
{}

}
}
