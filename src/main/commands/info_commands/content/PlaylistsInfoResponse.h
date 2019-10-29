#ifndef PLAYLISTSINFORESPONSE_H
#define PLAYLISTSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"

namespace ymlcpp {
namespace server_access {


class PlaylistsInfoResponse : public IServerResponse
{
public:
    PlaylistsInfoResponse(const QByteArray&);
    ~PlaylistsInfoResponse() override;

    ResponseResult status() const override;

private:
    void parseResponse(const QByteArray&) override;

private:
    ResponseResult _respResult;
};

}
}

#endif // PLAYLISTSINFORESPONSE_H
