#ifndef CLIENTCODEMOCK_H
#define CLIENTCODEMOCK_H

#include "ServerAccessManager.h"
#include "commands/headers/IServerRequest.h"
#include "commands/headers/IServerResponse.h"
#include "commands/AuthorizationRequest.h"

#include <QObject>
#include <QSharedPointer>

namespace ymlcpp {
namespace server_access {

class ClientCodeMock : public QObject
{
    Q_OBJECT
public:
    ClientCodeMock();

public slots:
    void responseReceived(QSharedPointer<IServerResponse>);
    void timerEvent(QTimerEvent*) override;


signals:
    void sendRequest(QSharedPointer<IServerRequest>);

private:
    ymlcpp::server_access::ServerAccessManager _sam;
    QString _oauthToken;
};

}
}

#endif // CLIENTCODEMOCK_H
