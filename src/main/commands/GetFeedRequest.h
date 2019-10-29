#ifndef GETFEEDREQUEST_H
#define GETFEEDREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"

namespace ymlcpp {
namespace server_access {

class GetFeedRequest : public ServerGetRequest
{
public:
    GetFeedRequest(const QString&);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    static const QUrl _feedUrl;
};

}
}

#endif // GETFEEDREQUEST_H
