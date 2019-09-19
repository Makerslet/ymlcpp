#ifndef ISERVERRESPONSE_H
#define ISERVERRESPONSE_H

#include "AppResponseTypes.h"

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
    IServerResponse(AppResponseType rType) : _respType(rType) {}
    virtual ~IServerResponse(){}
    virtual AppResponseType appResponseType() const { return  _respType;}
    virtual ResponseResult status() const = 0;

protected:
    virtual void parseResponse(const QByteArray&) = 0;

private:
    AppResponseType _respType;
};

}
}

#endif // ISERVERCOMMAND_H
