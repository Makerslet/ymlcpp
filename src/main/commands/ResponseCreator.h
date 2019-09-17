#ifndef RESPONSECREATOR_H
#define RESPONSECREATOR_H

#include "headers/IServerResponse.h"
#include "headers/AppRequestTypes.h"

#include <QByteArray>
#include <QSharedPointer>

namespace ymlcpp {
namespace server_access {

class ResponseCreator
{
public:
    static QSharedPointer<IServerResponse> createResponse(AppRequestType, const QByteArray&);
};

}
}

#endif // RESPONSECREATOR_H
