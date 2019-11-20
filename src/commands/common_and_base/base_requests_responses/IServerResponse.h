#ifndef ISERVERRESPONSE_H
#define ISERVERRESPONSE_H
// давим warning по виртуальному деструктору чтобы не добавлять cpp файл
#pragma clang diagnostic ignored "-Wweak-vtables"

#include "../common_enums/AppResponseTypes.h"

#include <QByteArray>
#include <QString>

namespace ymlcpp {
namespace server_access {

enum class ResponseResult {
    Succes,
    Error
};

struct ErrorInfo
{
    QString name;
    QString message;
};

class IServerResponse
{
public:
    virtual ~IServerResponse(){}
    virtual AppResponseType appResponseType() const = 0;
    virtual ResponseResult status() const = 0;
    virtual ErrorInfo errInfo() const = 0;
    virtual void parseResponse(const QByteArray&) = 0;
};

}
}

#endif // ISERVERCOMMAND_H
