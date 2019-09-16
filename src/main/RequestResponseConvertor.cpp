#include "RequestResponseConvertor.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPair>
#include <QByteArray>

namespace ymlcpp {
namespace server_access {

RequestResponseConvertor::RequestResponseConvertor()
{

}

QNetworkRequest RequestResponseConvertor::createGetNetworkRequest(QSharedPointer<IServerRequest>)
{
    return QNetworkRequest();
}

QPair<QNetworkRequest, QByteArray> RequestResponseConvertor::createPostNetworkRequest(
        QSharedPointer<ServerPostRequest> req)
{
    auto networkRequest = req->toNetworkRequest();
    return networkRequest;
}

QSharedPointer<IServerResponse> RequestResponseConvertor::parseNetworkResponse(QNetworkReply*)
{

}

}
}
