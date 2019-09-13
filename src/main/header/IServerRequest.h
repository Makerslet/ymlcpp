#ifndef ISERVERREQUEST_H
#define ISERVERREQUEST_H

namespace ympcpp {
namespace server_access {

enum class RequestType{GET, POST};

class IServerRequest
{
public:
    RequestType requestType() const;
};

}
}

#endif // ISERVERREQUEST_H
