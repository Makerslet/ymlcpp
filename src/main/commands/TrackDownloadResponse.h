#ifndef TRACKDOWNLOADRESPONSE_H
#define TRACKDOWNLOADRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"

namespace ymlcpp {
namespace server_access {

class TrackDownloadResponse : public ServerResponse
{
public:
    TrackDownloadResponse();
    ~TrackDownloadResponse() override;

    QByteArray binaryTrack() const;
    void parseResponse(const QByteArray&) override;
    void parseContent(const QVariant&) override;

private:
    QByteArray _result;
};

}
}

#endif // TRACKDOWNLOADRESPONSE_H
