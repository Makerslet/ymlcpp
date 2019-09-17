#ifndef AUTHORIZATIONRESPONSE_H
#define AUTHORIZATIONRESPONSE_H

#include "headers/IServerResponse.h"

#include <QByteArray>

namespace ymlcpp {
namespace server_access {


class AuthorizationResponse : public IServerResponse
{
public:
    AuthorizationResponse(const QByteArray&);

private:
    void parseResponse(const QByteArray&) override;
};

}
}

#endif // AUTHORIZATIONRESPONSE_H
