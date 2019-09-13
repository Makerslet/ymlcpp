#include "ServerAccessManager.h"

#include <QSharedPointer>
#include <QNetworkRequest>

namespace ympcpp {
namespace server_access {

ServerAccessManager::ServerAccessManager(QObject *parent) : QObject(parent)
{

}

void ServerAccessManager::sendRequest(QSharedPointer<IServerRequest> request)
{
    switch (request->requestType()) {
    case RequestType::GET: {
        auto req = _convertor.createGetNetworkRequest(request);
        _accessor.sendRequest(req);
        break;
    }
    case RequestType::POST: {
        auto req = _convertor.createPostNetworkRequest(request);
        _accessor.sendRequest(req);
        break;
    }
    default: break;
    }
}

}
}
