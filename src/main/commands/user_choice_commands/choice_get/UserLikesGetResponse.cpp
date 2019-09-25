#include "UserLikesGetResponse.h"

namespace ymlcpp {
namespace server_access  {

UserLikeAlbumsGetResponse::UserLikeAlbumsGetResponse(const QByteArray& data) :
    UserChoiceAlbumsGetResponse (UserChoiceType::Like, data)
{}

UserLikeAlbumsGetResponse::~UserLikeAlbumsGetResponse()
{}


UserLikeArtistsGetResponse::UserLikeArtistsGetResponse(const QByteArray& data) :
    UserChoiceArtistsGetResponse (UserChoiceType::Like, data)
{}

UserLikeArtistsGetResponse::~UserLikeArtistsGetResponse()
{}

UserLikePlaylistsGetResponse::UserLikePlaylistsGetResponse(const QByteArray& data) :
    UserChoicePlaylistsGetResponse (UserChoiceType::Like, data)
{}

UserLikePlaylistsGetResponse::~UserLikePlaylistsGetResponse()
{}

UserLikeTracksGetResponse::UserLikeTracksGetResponse(const QByteArray& data) :
    UserChoiceTracksGetResponse (UserChoiceType::Like, data)
{}

UserLikeTracksGetResponse::~UserLikeTracksGetResponse()
{}

}
}
