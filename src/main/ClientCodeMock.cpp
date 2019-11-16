#include "ClientCodeMock.h"
#include "commands/authorization_commands/AuthorizationRequest.h"
#include "commands/authorization_commands/AuthorizationResponse.h"
#include "commands/user_choice_commands/choice_get/UserChoiceGetRequest.h"
#include "commands/user_choice_commands/choice_get/UserLikesGetResponse.h"
#include "commands/user_choice_commands/choice_get/UserDislikesGetResponse.h"
#include "commands/user_choice_commands/choice_set/UserChoiceSetRequest.h"
#include "commands/info_commands/user/UserInfoRequest.h"
#include "commands/info_commands/user/UserInfoResponse.h"
#include "commands/info_commands/content/ContentInfoRequest.h"
#include "commands/info_commands/content/TracksInforesponse.h"
#include "commands/info_commands/content/PlaylistsInfoResponse.h"
#include "commands/GetFeedRequest.h"
#include "commands/GetFeedResponse.h"
#include "commands/SearchRequest.h"
#include "commands/SearchResponse.h"
#include "commands/SearchSuggestRequest.h"
#include "commands/SearchSuggestResponse.h"
#include "commands/TrackVariantsRequest.h"
#include "commands/TrackVariantsResponse.h"
#include "commands/TrackGetPathRequest.h"
#include "commands/TrackGetPathResponse.h"
#include "commands/TrackDownloadRequest.h"
#include "commands/TrackDownloadResponse.h"
#include "commands/GenresRequest.h"
#include"commands/GenresResponse.h"
#include "commands/info_commands/content/AlbumsInfoResponse.h"
#include "commands/info_commands/content/ArtistsInfoResponse.h"
#include "commands/info_commands/content/PlaylistsInfoResponse.h"
#include "commands/info_commands/content/TracksInforesponse.h"
#include "commands/user_choice_commands/choice_set/UserChoiceSetResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

ClientCodeMock::ClientCodeMock()
{
    connect(this, &ClientCodeMock::sendRequest, &_sam, &ServerAccessManager::sendRequest);
    connect(&_sam, &ServerAccessManager::responseReceived, this, &ClientCodeMock::responseReceived);

    auto authReq = QSharedPointer<AuthorizationRequest>::create("yamustest@yandex.ru", "123456789a");
    emit sendRequest(authReq);
}

void ClientCodeMock::responseReceived(QSharedPointer<IServerResponse> response)
{
    if(response == nullptr)
    {
        qDebug() << "nullpointer response, something goes wrong";
        return;
    }

    if(response->appResponseType() == AppResponseType::AuthorizationResponse) {
        auto authResponse = response.dynamicCast<AuthorizationResponse>();
        qDebug() << "AuthorizationResponse";
        qDebug() << (int)authResponse->status();
        qDebug() << authResponse->oauthToken();
        _oauthToken = authResponse->oauthToken();

//        auto searchRequest = QSharedPointer<SearchSuggestRequest>::create(_oauthToken, "bullet for");
//        emit sendRequest(searchRequest);

//        auto infoReq = QSharedPointer<ContentInfoRequest>::create(_oauthToken, ContentType::Playlists, QStringList{"25722788"});
//        emit sendRequest(infoReq);

//        auto feedReq = QSharedPointer<GetFeedRequest>::create(_oauthToken);
//        emit sendRequest(feedReq);

//        auto likesPlaylists = QSharedPointer<UserChoiceGetRequest>::create(_oauthToken, _userId, UserChoiceType::Like, ContentType::Playlists);
//        emit sendRequest(likesPlaylists);

//        auto trackVariantsReq = QSharedPointer<TrackVariantsRequest>::create(_oauthToken, "45675837");
//        emit sendRequest(trackVariantsReq);
        auto likesAlbumsReq = QSharedPointer<UserChoiceSetRequest>::create(_oauthToken,
                                                                           "yamustest",
                                                                           UserChoiceType::Like,
                                                                           ContentType::Tracks,
                                                                           UserAction::Remove,
                                                                           QStringList{"5348657"});
        emit sendRequest(likesAlbumsReq);
    }
    else if(response->appResponseType() == AppResponseType::UserChoiceSetResponse)
    {
        auto feedResponse = response.dynamicCast<UserChoiceSetResponse>();
    }
    else if(response->appResponseType() == AppResponseType::TrackVariantsResponse)
    {
        auto trackVariantsResponse = response.dynamicCast<TrackVariantsResponse>();
        auto trackVariants = trackVariantsResponse->trackVariants();

        auto lambda = [](const TrackVariant& track) {return track.codec == TrackCodec::mp3;};
        auto iterMp3 = std::find_if(trackVariants.begin(), trackVariants.end(), lambda);

        auto url = iterMp3->trackXmlUrl.toString() + "f";
        auto reqDescriptionXml = QSharedPointer<TrackGetPathRequest>::create(_oauthToken,
                    iterMp3->trackXmlUrl);

        emit sendRequest(reqDescriptionXml);
    }
    else if(response->appResponseType() == AppResponseType::TrackPathResponse)
    {
        auto trackVariantsResponse = response.dynamicCast<TrackGetPathResponse>();
        auto pathDescription = trackVariantsResponse->pathDescription();
        auto trackDownloadRequest = QSharedPointer<TrackDownloadRequest>::create(
                    _oauthToken, pathDescription);
        emit sendRequest(trackDownloadRequest);

    }
    else if(response->appResponseType() == AppResponseType::TrackDownloadResponse)
    {
        auto trackDownloadResponse = response.dynamicCast<TrackDownloadResponse>();
    }
//    else if(response->appResponseType() == AppResponseType::UserInfoResponse) {
//        auto userInfoResp = response.dynamicCast<UserInfoResponse>();
//        int i = 10;
//        _userId = QString::number(userInfoResp->userInfo().account.uid);

//        auto uInfoReq = QSharedPointer<UserChoiceGetRequest>::create(_oauthToken, _userId,
//                                                                     UserChoiceType::Like, ContentType::Playlists);
//        emit sendRequest(uInfoReq);
//    }
//    else if(response->appResponseType() == AppResponseType::UserChoiceGetResponse) {
//        auto rep = response.dynamicCast<UserChoicePlaylistsGetResponse>();
//        int i = 10;
//    }
//    else if(response->appResponseType() == AppResponseType::ContentInfoResponse) {
//        auto responseDc  = response.dynamicCast<PlaylistsInfoResponse>();
//    }
    /*
    else if(response->appResponseType() == AppResponseType::TrackVariantsResponse)
    {
        auto trackVariantsResponse = response.dynamicCast<TrackVariantsResponse>();
        auto trackVariants = trackVariantsResponse->trackVariants();

        auto lambda = [](const TrackVariant& track) {return track.codec == TrackCodec::mp3;};
        auto iterMp3 = std::find_if(trackVariants.begin(), trackVariants.end(), lambda);

        auto url = iterMp3->trackXmlUrl.toString() + "f";
        auto reqDescriptionXml = QSharedPointer<TrackGetPathRequest>::create(_oauthToken,
                    iterMp3->trackXmlUrl);

        emit sendRequest(reqDescriptionXml);
    }
    else if(response->appResponseType() == AppResponseType::TrackPathResponse)
    {
        auto trackPath = response.dynamicCast<TrackGetPathResponse>();
    }*/
}

void ClientCodeMock::timerEvent(QTimerEvent* event)
{

}


}
}
