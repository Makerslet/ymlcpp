#ifndef SERVERACCESSOR_H
#define SERVERACCESSOR_H

#include <QNetworkRequest>

namespace ympcpp {
namespace server_access {

class ServerAccessor
{
public:
    ServerAccessor();

    void sendRequest(QNetworkRequest);
    void sendRequest(QPair<QNetworkRequest, QByteArray>);
};

}
}

#endif // SERVERACCESSOR_H
