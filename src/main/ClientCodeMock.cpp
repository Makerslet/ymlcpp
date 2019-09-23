#include "ClientCodeMock.h"
#include "commands/AuthorizationRequest.h"
#include "commands/AuthorizationResponse.h"
#include "commands/UserLikesRequest.h"
#include "commands/TrackVariantsRequest.h"
#include "commands/UserLikesResponse.h"
#include "commands/TrackVariantsResponse.h"
#include "commands/TrackGetPathRequest.h"
#include "commands/TrackGetPathResponse.h"

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

        auto uInfoReq = QSharedPointer<UserLikesRequest>::create(_oauthToken, "yamustest");
        emit sendRequest(uInfoReq);
    }

    else if(response->appResponseType() == AppResponseType::UserLikesResponse) {
        auto responseDc = response.dynamicCast<UserLikesResponse>();
        auto trackVariants = QSharedPointer<TrackVariantsRequest>::create(_oauthToken,
                          responseDc->userLikes().tracks.first().id);
        emit sendRequest(trackVariants);
    }

    else if(response->appResponseType() == AppResponseType::TrackVariantsResponse)
    {
        auto trackVariantsResponse = response.dynamicCast<TrackVariantsResponse>();
        auto trackVariants = trackVariantsResponse->trackVariants();

        auto lambda = [](const TrackVariant& track) {return track.codec == TrackCodec::mp3;};
        auto iterMp3 = std::find_if(trackVariants.begin(), trackVariants.end(), lambda);

        auto url = iterMp3->trackXmlUrl.toString() + "f";
        auto reqDescriptionXml = QSharedPointer<TrackGetPathRequest>::create(_oauthToken,
                    /*iterMp3->trackXmlUrl*/QUrl(url));

        emit sendRequest(reqDescriptionXml);
    }
    else if(response->appResponseType() == AppResponseType::TrackPathResponse)
    {
        auto trackPath = response.dynamicCast<TrackGetPathResponse>();
    }
}

void ClientCodeMock::timerEvent(QTimerEvent* event)
{

}


}
}
