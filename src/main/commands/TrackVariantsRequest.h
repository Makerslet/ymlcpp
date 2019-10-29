#ifndef TRACKVARIANTSREQUEST_H
#define TRACKVARIANTSREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"

namespace ymlcpp {
namespace server_access {


class TrackVariantsRequest : public ServerGetRequest
{
public:
    TrackVariantsRequest(const QString&, const QString&);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    QString _trackId;

    static const QString _templateUrl;
};

}
}

#endif // TRACKVARIANTSREQUEST_H
