#ifndef ISERVERRESPONSE_H
#define ISERVERRESPONSE_H

#include <QByteArray>

namespace ymlcpp {
namespace server_access {

enum class ResponseResult {
    Succes,
    Error
};

class IServerResponse
{
public:
    virtual ~IServerResponse(){}

protected:
    virtual void parseResponse(const QByteArray&) = 0;
};

}
}

#endif // ISERVERCOMMAND_H
