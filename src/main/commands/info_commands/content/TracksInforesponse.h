#ifndef TRACKSINFORESPONSE_H
#define TRACKSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"
#include "../../common_and_base/common_structures/TrackDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {


class TracksInfoResponse : public IServerResponse
{
public:
    TracksInfoResponse(const QByteArray&);
    ~TracksInfoResponse() override;

    ResponseResult status() const override;
    QList<TrackDescription> tracksDescription() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QList<TrackDescription> _tracks;
    ErrorInfo _errInfo;
};

}
}

#endif // TRACKSINFORESPONSE_H
