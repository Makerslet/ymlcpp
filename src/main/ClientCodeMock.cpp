#include "ClientCodeMock.h"
#include "commands/AuthorizationRequest.h"
#include "commands/AuthorizationResponse.h"
#include "commands/UserLikesRequest.h"

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

        auto uInfoReq = QSharedPointer<UserLikesRequest>::create(authResponse->oauthToken(),
                                                                 "yamustest");
        emit sendRequest(uInfoReq);
    }
    /*
    else if(response->appResponseType() == AppResponseType::UserInfoResponse) {
        auto uInfoResponse = response.dynamicCast<UserInfoResponse>();
        qDebug() << "UserInfoResponse";
        qDebug() << (int)uInfoResponse->status();
    }*/
}

void ClientCodeMock::timerEvent(QTimerEvent* event)
{

}


}
}
