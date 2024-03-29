#ifndef APPRESPONSETYPES_H
#define APPRESPONSETYPES_H

namespace ymlcpp {
namespace server_access {

enum class AppResponseType {
    AuthorizationResponse,
    UserInfoResponse,
    ContentInfoResponse,
    UserChoiceGetResponse,
    UserChoiceSetResponse,
    TrackVariantsResponse,
    TrackPathResponse,
    TrackDownloadResponse,
    GenresResponse,
    FeedResponse,
    SearchResponse,
    SearchSuggestResponse
};

}
}

#endif // APPRESPONSETYPES_H
