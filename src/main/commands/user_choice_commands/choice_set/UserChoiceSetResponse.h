#ifndef USERCHOICESETRESPONSE
#define USERCHOICESETRESPONSE

#include "../../common_and_base/base_requests_responses/ServerResponse.h"

#include <QByteArray>
#include <QJsonObject>
#include <QUrl>

namespace ymlcpp {
namespace server_access {


class UserChoiceSetResponse : public ServerResponse
{
public:
    UserChoiceSetResponse();
    ~UserChoiceSetResponse();

private:
    void parseContent(const QVariant&) override;
};

}
}

#endif // USERCHOICESETRESPONSE
