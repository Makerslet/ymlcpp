#include "commands/user_choice_commands/choice_set/UserChoiceSetResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


UserChoiceSetResponse::UserChoiceSetResponse() :
    ServerResponse (AppResponseType::UserChoiceSetResponse)
{}

UserChoiceSetResponse::~UserChoiceSetResponse()
{}

void UserChoiceSetResponse::parseContent(const QVariant& data)
{}


}
}
