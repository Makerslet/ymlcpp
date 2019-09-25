#ifndef USERCHOICEGETREQUEST_H
#define USERCHOICEGETREQUEST_H

#include "../../common_and_base/base_requests_responses/ServerGetRequest.h"
#include "../../common_and_base/common_enums/UserChoice.h"

namespace ymlcpp {
namespace server_access  {


class UserChoiceGetRequest : public ServerGetRequest
{
public:
    UserChoiceGetRequest(const QString&, const QString&, UserChoiceType, UserChoiceContent);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    QString _login;
    UserChoiceType _choiceType;
    UserChoiceContent _choiceContent;

    static const QString _templateUrl;
};

}
}

#endif // USERCHOICEGETREQUEST_H
