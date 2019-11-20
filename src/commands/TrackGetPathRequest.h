#ifndef TRACKGETPATHREQUEST_H
#define TRACKGETPATHREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"

#include <QUrl>


namespace ymlcpp {
namespace server_access {

class TrackGetPathRequest : public ServerGetRequest
{
public:
    TrackGetPathRequest(const QString&, const QUrl&);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    QUrl _trackXmlUrl;
};

}
}

#endif // TRACKGETPATHREQUEST_H
