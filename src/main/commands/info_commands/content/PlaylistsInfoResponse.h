#ifndef PLAYLISTSINFORESPONSE_H
#define PLAYLISTSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/ServerResponse.h"

namespace ymlcpp {
namespace server_access {


class PlaylistsInfoResponse : public ServerResponse
{
public:
    PlaylistsInfoResponse();
    ~PlaylistsInfoResponse() override;

private:
    void parseContent(const QVariant&) override;
};

}
}

#endif // PLAYLISTSINFORESPONSE_H
