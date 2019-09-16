#ifndef REQUESTRESPONSECONVERTOR_H
#define REQUESTRESPONSECONVERTOR_H

#include "commands/headers/IServerRequest.h"
#include "commands/headers/IServerResponse.h"
#include "commands/ServerPostRequest.h"

#include <QSharedPointer>

class QNetworkRequest;
class QNetworkReply;

namespace ymlcpp {
namespace server_access {

class RequestResponseConvertor
{
public:
    RequestResponseConvertor();
    QNetworkRequest createGetNetworkRequest(QSharedPointer<IServerRequest>);
    QPair<QNetworkRequest, QByteArray> createPostNetworkRequest(QSharedPointer<ServerPostRequest>);
    QSharedPointer<IServerResponse> parseNetworkResponse(QNetworkReply*);

private:
    QHash<QUrl, QList<QNetworkRequest>> _requestsHash;
};

}
}

#endif // REQUESTRESPONSECONVERTOR_H
