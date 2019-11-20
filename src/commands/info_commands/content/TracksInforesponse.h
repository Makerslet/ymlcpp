#ifndef TRACKSINFORESPONSE_H
#define TRACKSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/ServerResponse.h"
#include "../../common_and_base/common_structures/TrackDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {


class TracksInfoResponse : public ServerResponse
{
public:
    TracksInfoResponse();
    ~TracksInfoResponse() override;

    QList<TrackDescription> tracksDescription() const;

private:
    void parseContent(const QVariant&) override;

private:
    QList<TrackDescription> _tracks;
};

}
}

#endif // TRACKSINFORESPONSE_H
