#include "ServerAccessor.h"
#include <QNetworkReply>

namespace ympcpp {
namespace server_access {

ServerAccessor::ServerAccessor()
{
    _networkAccessManager = new QNetworkAccessManager();

    connect(_networkAccessManager, &QNetworkAccessManager::finished,
            this, &ServerAccessor::responseReceived);

    connect(_networkAccessManager, &QNetworkAccessManager::sslErrors,
            this, &ServerAccessor::errorHapenned);
}

ServerAccessor::~ServerAccessor()
{
    delete _networkAccessManager;
}

void ServerAccessor::sendRequest(const QNetworkRequest& reqGet)
{
    _networkAccessManager->get(reqGet);
}

void ServerAccessor::sendRequest(const QPair<QNetworkRequest, QByteArray>& reqPost)
{
    _networkAccessManager->post(reqPost.first, reqPost.second);
}

}
}
