#include "commands/user_choice_commands/choice_get/UserChoiceGetResponse.h"

namespace ymlcpp {
namespace server_access {

UserChoiceGetResponse::UserChoiceGetResponse(UserChoiceType type, ContentType content) :
    ServerResponse (AppResponseType::UserChoiceGetResponse),
    _choiceType(type), _choiceContent(content)
{}

UserChoiceGetResponse::~UserChoiceGetResponse()
{}

UserChoiceType UserChoiceGetResponse::choiceType() const
{
    return  _choiceType;
}
ContentType UserChoiceGetResponse::choiceContent() const
{
    return _choiceContent;
}



}
}
