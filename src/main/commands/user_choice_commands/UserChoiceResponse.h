#ifndef USERCHOICERESPONSE_H
#define USERCHOICERESPONSE_H

#include "../common_and_base/base_requests_responses/IServerResponse.h"
#include "../common_and_base/common_enums/UserChoice.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class UserChoiceResponse : public IServerResponse
{
public:
    UserChoiceResponse(UserChoiceType, UserChoiceContent);
    ~UserChoiceResponse() override;

    ResponseResult status() const override;
    ErrorInfo errorInfo() const;
    UserChoiceType choiceType() const;
    UserChoiceContent choiceContent() const;

protected:
    void parseError(const QVariantHash&);

protected:
    ResponseResult _respStatus;
    ErrorInfo _errInfo;

private:
    const UserChoiceType _choiceType;
    const UserChoiceContent _choiceContent;
};

}
}

#endif // USERCHOICERESPONSE_H
