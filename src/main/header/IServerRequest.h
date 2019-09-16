#ifndef ISERVERREQUEST_H
#define ISERVERREQUEST_H

namespace ympcpp {
namespace server_access {

enum class RequestType{GET, POST};

class IServerRequest
{
public:
    IServerRequest();
    virtual ~IServerRequest();
    RequestType requestType() const {return _reqType;}

private:
    RequestType _reqType;
};

}
}

#endif // ISERVERREQUEST_H
