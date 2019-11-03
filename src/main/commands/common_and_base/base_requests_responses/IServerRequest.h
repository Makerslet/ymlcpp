#ifndef ISERVERREQUEST_H
#define ISERVERREQUEST_H
// давим warning по виртуальному деструктору чтобы не добавлять cpp файл
#pragma clang diagnostic ignored "-Wweak-vtables"

#include "IServerResponse.h"
#include "../common_enums/AppRequestTypes.h"

#include <QSharedPointer>

namespace ymlcpp {
namespace server_access {

enum class ServerRequestType{GET, POST};

class IServerRequest
{
public:
    virtual ~IServerRequest(){}

    virtual ServerRequestType serverRequestType() const = 0;
    virtual AppRequestType appRequestType() const = 0;
    virtual QSharedPointer<IServerResponse> createResponse(const QByteArray&) const = 0;
};

}
}

#endif // ISERVERREQUEST_H
