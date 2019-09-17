#include "RequestResponseConvertor.h"
#include "commands/ResponseCreator.h"

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
    insertRequest(req->appRequestType(), networkRequest.first);
    return networkRequest;
}

void RequestResponseConvertor::insertRequest(AppRequestType type, const QNetworkRequest& req)
{
    auto url = req.url();

    if(_requestsHash.contains(req.url()))
        return;

    _requestsHash.insert(url, qMakePair(type, req));
}


QSharedPointer<IServerResponse> RequestResponseConvertor::parseNetworkResponse(QNetworkReply* reply)
{
    auto baseRequest = reply->request();
    auto url = baseRequest.url();

    auto iterToReq = _requestsHash.find(url);
    if(iterToReq == _requestsHash.end())
        return QSharedPointer<IServerResponse>();
    else
    {
        auto reqType = iterToReq.value().first;
        auto reqPayload = reply->readAll();

        _requestsHash.erase(iterToReq);

        return  ResponseCreator::createResponse(reqType, reqPayload);
    }
}

}
}
