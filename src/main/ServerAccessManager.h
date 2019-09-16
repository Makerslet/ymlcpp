#ifndef SERVERACCESSMANAGER_H
#define SERVERACCESSMANAGER_H

#include <QObject>

#include "header/IServerRequest.h"
#include "header/IServerResponse.h"

#include "RequestResponseConvertor.h"
#include "ServerAccessor.h"

namespace ympcpp {
namespace server_access {

class ServerAccessManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerAccessManager(QObject *parent = nullptr);
    ~ServerAccessManager();

    ServerAccessManager(const ServerAccessManager&) = delete;
    ServerAccessManager& operator=(const ServerAccessManager&) = delete;

public slots:
    void sendRequest(QSharedPointer<IServerRequest>);
    void responseFromNetwork(QNetworkReply*);
    void responseErrors(QNetworkReply*, const QList<QSslError>&);

signals:
    void responseReceived(QSharedPointer<IServerResponse>);

private:
    RequestResponseConvertor* _convertor;
    ServerAccessor* _accessor;
};

}
}

#endif // SERVERACCESSMANAGER_H
