#ifndef REQUESTRESPONSECONVERTOR_H
#define REQUESTRESPONSECONVERTOR_H

#include "header/IServerRequest.h"
#include "header/IServerResponse.h"

#include <QSharedPointer>

class QNetworkRequest;
class QNetworkReply;

namespace ympcpp {
namespace server_access {

class RequestResponseConvertor
{
public:
    RequestResponseConvertor();
    QNetworkRequest createGetNetworkRequest(QSharedPointer<IServerRequest>);
    QPair<QNetworkRequest, QByteArray> createPostNetworkRequest(QSharedPointer<IServerRequest>);
    QSharedPointer<IServerResponse> parseNetworkResponse(QNetworkReply*);

private:
    // реализация конкретных конверторов
    QNetworkRequest convertFromTo();

private:
    QHash<QUrl, QList<QNetworkRequest>> _requestsHash;
};

}
}

#endif // REQUESTRESPONSECONVERTOR_H
