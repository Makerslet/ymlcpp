#ifndef APPREQUESTTYPES_H
#define APPREQUESTTYPES_H

namespace ymlcpp {
namespace server_access {

enum class AppRequestType {
    AuthorizationRequest,
    UserInfoRequest,
    ContentInfoRequest,
    UserChoiceGetRequest,
    UserChoiceSetRequest,
    TrackVariantsRequest,
    TrackPathRequest,
    GenresRequest,
    FeedRequest,
    SearchRequest
};

}
}

#endif // APPREQUESTTYPES_H
