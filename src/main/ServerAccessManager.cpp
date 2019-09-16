#include "ServerAccessManager.h"

#include <QSharedPointer>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace ympcpp {
namespace server_access {

ServerAccessManager::ServerAccessManager(QObject *parent) : QObject(parent)
{
    _convertor = new RequestResponseConvertor();

    _accessor = new ServerAccessor();
    connect(_accessor, &ServerAccessor::responseReceived,
            this, &ServerAccessManager::responseFromNetwork);
    connect(_accessor, &ServerAccessor::errorHapenned,
            this, &ServerAccessManager::responseErrors);
}

ServerAccessManager::~ServerAccessManager()
{
    delete _convertor;
    delete _accessor;
}

void ServerAccessManager::sendRequest(QSharedPointer<IServerRequest> request)
{
    switch (request->requestType()) {
    case RequestType::GET: {
        auto req = _convertor->createGetNetworkRequest(request);
        _accessor->sendRequest(req);
        break;
    }
    case RequestType::POST: {
        auto req = _convertor->createPostNetworkRequest(request);
        _accessor->sendRequest(req);
        break;
    }
    default: break;
    }
}

void ServerAccessManager::responseFromNetwork(QNetworkReply* reply)
{
    emit responseReceived(_convertor->parseNetworkResponse(reply));
}

void ServerAccessManager::responseErrors(QNetworkReply*, const QList<QSslError>&)
{
    // log these errors and send user result
}

}
}
