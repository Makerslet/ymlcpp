#ifndef TRACKSINFORESPONSE_H
#define TRACKSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"

namespace ymlcpp {
namespace server_access {


class TracksInforesponse : public IServerResponse
{
public:
    TracksInforesponse(const QByteArray&);
};

}
}

#endif // TRACKSINFORESPONSE_H
