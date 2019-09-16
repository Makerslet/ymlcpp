#ifndef ISERVERREQUEST_H
#define ISERVERREQUEST_H

#include "AppRequestTypes.h"

namespace ymlcpp {
namespace server_access {

enum class ServerRequestType{GET, POST};

class IServerRequest
{
public:
    virtual ~IServerRequest(){}

    virtual ServerRequestType serverRequestType() const = 0;
    virtual AppRequestType appRequestType() const = 0;
};

}
}

#endif // ISERVERREQUEST_H
