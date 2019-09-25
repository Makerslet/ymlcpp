#ifndef USERCHOICESETRESPONSE
#define USERCHOICESETRESPONSE

#include "../../common_and_base/base_requests_responses/IServerResponse.h"

#include <QByteArray>
#include <QJsonObject>
#include <QUrl>

namespace ymlcpp {
namespace server_access {


class UserChoiceSetResponse : public IServerResponse
{
public:
    UserChoiceSetResponse(const QByteArray&);

    ResponseResult status() const override;

private:
    void parseResponse(const QByteArray&) override;

private:
};

}
}

#endif // USERCHOICESETRESPONSE
