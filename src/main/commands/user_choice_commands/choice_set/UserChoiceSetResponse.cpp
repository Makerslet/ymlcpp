#include "UserChoiceSetResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QMap>

namespace ymlcpp {
namespace server_access {


UserChoiceSetResponse::UserChoiceSetResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserChoiceSetResponse)
{
    parseResponse(data);
}

void UserChoiceSetResponse::parseResponse(const QByteArray& data)
{
}

ResponseResult UserChoiceSetResponse::status() const
{
}


}
}
