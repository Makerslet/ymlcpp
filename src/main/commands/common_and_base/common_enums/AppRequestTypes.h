#ifndef APPREQUESTTYPES_H
#define APPREQUESTTYPES_H

namespace ymlcpp {
namespace server_access {

enum class AppRequestType {
    AuthorizationRequest,
    UserInfoRequest,
    UserChoiceGetRequest,
    UserChoiceSetRequest,
    TrackVariantsRequest,
    TrackPathRequest
};

}
}

#endif // APPREQUESTTYPES_H
