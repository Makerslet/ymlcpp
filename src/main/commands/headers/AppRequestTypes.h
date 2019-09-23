#ifndef APPREQUESTTYPES_H
#define APPREQUESTTYPES_H

namespace ymlcpp {
namespace server_access {

enum class AppRequestType {
    AuthorizationRequest,
    UserInfoRequest,
    UserLikesRequest,
    TrackVariantsRequest
};

}
}

#endif // APPREQUESTTYPES_H
