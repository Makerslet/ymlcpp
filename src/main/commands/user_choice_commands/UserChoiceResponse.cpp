#include "UserChoiceResponse.h"

namespace ymlcpp {
namespace server_access {

UserChoiceResponse::UserChoiceResponse(UserChoiceType type, UserChoiceContent content) :
    IServerResponse (AppResponseType::UserChoiceResponse),
    _choiceType(type), _choiceContent(content)
{

}

UserChoiceResponse::~UserChoiceResponse()
{
}

ResponseResult UserChoiceResponse::status() const
{
    return _respStatus;
}

ErrorInfo UserChoiceResponse::errorInfo() const
{
    return _errInfo;
}

UserChoiceType UserChoiceResponse::choiceType() const
{
    return  _choiceType;
}
UserChoiceContent UserChoiceResponse::choiceContent() const
{
    return _choiceContent;
}

void UserChoiceResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}



}
}
