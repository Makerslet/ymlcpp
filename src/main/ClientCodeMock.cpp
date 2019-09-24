#include "ClientCodeMock.h"
#include "commands/authorization_commands/AuthorizationRequest.h"
#include "commands/authorization_commands/AuthorizationResponse.h"
#include "commands/user_choice_commands/UserChoiceRequest.h"
#include "commands/user_choice_commands/UserLikesResponse.h"
#include "commands/user_choice_commands/UserDislikesResponse.h"

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

        auto uInfoReq = QSharedPointer<UserChoiceRequest>::create(_oauthToken, "yamustest",
                                 UserChoiceType::Dislike, UserChoiceContent::Tracks);
        emit sendRequest(uInfoReq);
    }
    else if(response->appResponseType() == AppResponseType::UserChoiceResponse) {
        auto responseDc  = response.dynamicCast<UserDislikeTracksResponse>();
        int i = 10;
    }
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
