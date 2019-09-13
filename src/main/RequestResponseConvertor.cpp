#include "RequestResponseConvertor.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPair>
#include <QByteArray>

namespace ympcpp {
namespace server_access {

RequestResponseConvertor::RequestResponseConvertor()
{

}

QNetworkRequest RequestResponseConvertor::createGetNetworkRequest(QSharedPointer<IServerRequest>)
{
    return QNetworkRequest();
}

QPair<QNetworkRequest, QByteArray> RequestResponseConvertor::createPostNetworkRequest(QSharedPointer<IServerRequest>)
{
    return qMakePair(QNetworkRequest(), QByteArray());
}

QSharedPointer<IServerResponse> RequestResponseConvertor::parseNetworkResponse(QNetworkReply*)
{

}

}
}
