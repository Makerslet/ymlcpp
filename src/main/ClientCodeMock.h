#ifndef CLIENTCODEMOCK_H
#define CLIENTCODEMOCK_H

#include "ServerAccessManager.h"
#include "commands/common_and_base/base_requests_responses/IServerRequest.h"
#include "commands/common_and_base/base_requests_responses/IServerResponse.h"
#include "commands/authorization_commands/AuthorizationRequest.h"

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
    QString _userId;
};

}
}

#endif // CLIENTCODEMOCK_H
