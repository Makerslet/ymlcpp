#include "ServerAccessManager.h"
#include <QSharedPointer>

namespace ympcpp {
namespace server_access {

ServerAccessManager::ServerAccessManager(QObject *parent) : QObject(parent)
{

}

void ServerAccessManager::sendRequest(QSharedPointer<IServerRequest> request)
{
}

}
}
