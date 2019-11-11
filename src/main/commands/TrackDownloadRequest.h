#ifndef TRACKDOWNLOADREQUEST_H
#define TRACKDOWNLOADREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"
#include "common_and_base/common_structures/TrackPathDescription.h"

namespace ymlcpp {
namespace server_access {

class TrackDownloadRequest : public ServerGetRequest
{
public:
    TrackDownloadRequest(const QString&, const TrackPathDescription&);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    TrackPathDescription _pathDescr;

    static const QString _templateUrl;
};

}
}

#endif // TRACKDOWNLOADREQUEST_H
