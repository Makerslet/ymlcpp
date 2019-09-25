#include "UserChoiceGetResponse.h"

namespace ymlcpp {
namespace server_access {

UserChoiceGetResponse::UserChoiceGetResponse(UserChoiceType type, UserChoiceContent content) :
    IServerResponse (AppResponseType::UserChoiceGetResponse),
    _choiceType(type), _choiceContent(content)
{

}

UserChoiceGetResponse::~UserChoiceGetResponse()
{
}

ResponseResult UserChoiceGetResponse::status() const
{
    return _respStatus;
}

ErrorInfo UserChoiceGetResponse::errorInfo() const
{
    return _errInfo;
}

UserChoiceType UserChoiceGetResponse::choiceType() const
{
    return  _choiceType;
}
UserChoiceContent UserChoiceGetResponse::choiceContent() const
{
    return _choiceContent;
}

void UserChoiceGetResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}



}
}
