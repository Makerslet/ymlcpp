#ifndef APPRESPONSETYPES_H
#define APPRESPONSETYPES_H

namespace ymlcpp {
namespace server_access {

enum class AppResponseType {
    AuthorizationResponse,
    UserInfoResponse,
    UserLikesResponse,
    TrackVariantsResponse
};

}
}

#endif // APPRESPONSETYPES_H
