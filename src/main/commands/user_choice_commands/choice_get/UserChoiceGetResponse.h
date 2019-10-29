#ifndef USERCHOICEGETRESPONSE_H
#define USERCHOICEGETRESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"
#include "../../common_and_base/common_enums/UserChoice.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class UserChoiceGetResponse : public IServerResponse
{
public:
    UserChoiceGetResponse(UserChoiceType, ContentType);
    ~UserChoiceGetResponse() override;

    ResponseResult status() const override;
    ErrorInfo errorInfo() const;
    UserChoiceType choiceType() const;
    ContentType choiceContent() const;

protected:
    void parseError(const QVariantHash&);

protected:
    ResponseResult _respStatus;
    ErrorInfo _errInfo;

private:
    const UserChoiceType _choiceType;
    const ContentType _choiceContent;
};

}
}

#endif // USERCHOICEGETRESPONSE_H
