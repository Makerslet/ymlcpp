#ifndef USERCHOICEGETRESPONSE_H
#define USERCHOICEGETRESPONSE_H

#include "../../common_and_base/base_requests_responses/ServerResponse.h"
#include "../../common_and_base/common_enums/UserChoice.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class UserChoiceGetResponse : public ServerResponse
{
public:
    UserChoiceGetResponse(UserChoiceType, ContentType);
    ~UserChoiceGetResponse() override;

    UserChoiceType choiceType() const;
    ContentType choiceContent() const;

private:
    const UserChoiceType _choiceType;
    const ContentType _choiceContent;
};

}
}

#endif // USERCHOICEGETRESPONSE_H
