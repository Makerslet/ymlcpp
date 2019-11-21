#ifndef REQUESTRESPONSECONVERTOR_H
#define REQUESTRESPONSECONVERTOR_H

#include "commands/common_and_base/base_requests_responses/IServerResponse.h"
#include "commands/common_and_base/base_requests_responses/ServerPostRequest.h"
#include "commands/common_and_base/base_requests_responses/ServerGetRequest.h"
#include "commands/common_and_base/common_enums/AppRequestTypes.h"

#include <QSharedPointer>

class QNetworkRequest;
class QNetworkReply;

namespace ymlcpp {
namespace server_access {

class RequestResponseConvertor
{
    using RequestSptr = QSharedPointer<IServerRequest>;
    using PostRequestSptr = QSharedPointer<ServerPostRequest>;
    using RequestsHash = QHash<QUrl, QPair<QNetworkRequest, RequestSptr>>;

public:
    RequestResponseConvertor();
    QNetworkRequest createGetNetworkRequest(QSharedPointer<ServerGetRequest>);
    QPair<QNetworkRequest, QByteArray> createPostNetworkRequest(QSharedPointer<ServerPostRequest>);
    QSharedPointer<IServerResponse> parseNetworkResponse(QNetworkReply*);

private:
    void insertRequest(RequestSptr, const QNetworkRequest&);

private:
    RequestsHash _requestsHash;
};

}
}

#endif // REQUESTRESPONSECONVERTOR_H
