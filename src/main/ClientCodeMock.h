#ifndef CLIENTCODEMOCK_H
#define CLIENTCODEMOCK_H

#include "ServerAccessManager.h"
#include "commands/AuthorizationRequest.h"

#include <QObject>

class ClientCodeMock : public QObject
{
    Q_OBJECT
public:
    ClientCodeMock();

private:
    ymlcpp::server_access::ServerAccessManager _sam;
};

#endif // CLIENTCODEMOCK_H
