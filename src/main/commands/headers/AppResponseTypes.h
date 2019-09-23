#ifndef APPRESPONSETYPES_H
#define APPRESPONSETYPES_H

namespace ymlcpp {
namespace server_access {

enum class AppResponseType {
    AuthorizationResponse,
    UserInfoResponse,
    UserLikeAlbumsResponse,
    UserLikeArtistsResponse,
    UserLikePlaylistsResponse,
    UserLikeTracksResponse,
    TrackVariantsResponse,
    TrackPathResponse
};

}
}

#endif // APPRESPONSETYPES_H
