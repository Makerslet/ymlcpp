#ifndef TRACKSINFORESPONSE_H
#define TRACKSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"

namespace ymlcpp {
namespace server_access {


class TracksInfoResponse : public IServerResponse
{
public:
    TracksInfoResponse(const QByteArray&);
    ~TracksInfoResponse() override;

    ResponseResult status() const override;

private:
    void parseResponse(const QByteArray&) override;

private:
    ResponseResult _respResult;
};

}
}

#endif // TRACKSINFORESPONSE_H
