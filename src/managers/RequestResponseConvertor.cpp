#include "managers/RequestResponseConvertor.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPair>
#include <QByteArray>

namespace ymlcpp {
namespace server_access {

RequestResponseConvertor::RequestResponseConvertor()
{

}

QNetworkRequest RequestResponseConvertor::createGetNetworkRequest(
        QSharedPointer<ServerGetRequest> req)
{
    auto networkRequest = req->toNetworkRequest();
    insertRequest(req, networkRequest);
    return networkRequest;
}

QPair<QNetworkRequest, QByteArray> RequestResponseConvertor::createPostNetworkRequest(
        QSharedPointer<ServerPostRequest> req)
{
    auto networkRequest = req->toNetworkRequest();
    insertRequest(req, networkRequest.first);
    return networkRequest;
}

void RequestResponseConvertor::insertRequest(RequestSptr req, const QNetworkRequest& networkReq)
{
    auto url = networkReq.url();

    if(_requestsHash.contains(url))
        return;

    _requestsHash.insert(url, qMakePair(networkReq, req));
}


QSharedPointer<IServerResponse> RequestResponseConvertor::parseNetworkResponse(QNetworkReply* reply)
{
    auto baseRequest = reply->request();
    auto url = baseRequest.url();

    auto iterToReq = _requestsHash.find(url);
    if(iterToReq != _requestsHash.end())
    {
        auto request = iterToReq.value().second;
        _requestsHash.erase(iterToReq);

        return request->createResponse(reply->readAll());
    }
    else
        return QSharedPointer<IServerResponse>();
}

}
}
