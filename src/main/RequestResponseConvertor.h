#ifndef REQUESTRESPONSECONVERTOR_H
#define REQUESTRESPONSECONVERTOR_H

#include "commands/headers/IServerResponse.h"
#include "commands/ServerPostRequest.h"
#include "commands/headers/AppRequestTypes.h"

#include <QSharedPointer>

class QNetworkRequest;
class QNetworkReply;

namespace ymlcpp {
namespace server_access {

class RequestResponseConvertor
{
    using RequestsHash = QHash<QUrl, QPair<AppRequestType, QNetworkRequest>>;
public:
    RequestResponseConvertor();
    QNetworkRequest createGetNetworkRequest(QSharedPointer<IServerRequest>);
    QPair<QNetworkRequest, QByteArray> createPostNetworkRequest(QSharedPointer<ServerPostRequest>);
    QSharedPointer<IServerResponse> parseNetworkResponse(QNetworkReply*);

private:
    void insertRequest(AppRequestType, const QNetworkRequest&);

private:
    RequestsHash _requestsHash;
};

}
}

#endif // REQUESTRESPONSECONVERTOR_H
