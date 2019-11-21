#include "commands/user_choice_commands/choice_get/UserDislikesGetResponse.h"

namespace ymlcpp {
namespace server_access  {

UserDislikeAlbumsGetResponse::UserDislikeAlbumsGetResponse() :
    UserChoiceAlbumsGetResponse(UserChoiceType::Dislike)
{}

UserDislikeAlbumsGetResponse::~UserDislikeAlbumsGetResponse()
{}


UserDislikeArtistsGetResponse::UserDislikeArtistsGetResponse() :
    UserChoiceArtistsGetResponse(UserChoiceType::Dislike)
{}

UserDislikeArtistsGetResponse::~UserDislikeArtistsGetResponse()
{}

UserDislikePlaylistsGetResponse::UserDislikePlaylistsGetResponse() :
    UserChoicePlaylistsGetResponse(UserChoiceType::Dislike)
{}

UserDislikePlaylistsGetResponse::~UserDislikePlaylistsGetResponse()
{}

UserDislikeTracksGetResponse::UserDislikeTracksGetResponse() :
    UserChoiceTracksGetResponse(UserChoiceType::Dislike)
{}

UserDislikeTracksGetResponse::~UserDislikeTracksGetResponse()
{}

}
}
