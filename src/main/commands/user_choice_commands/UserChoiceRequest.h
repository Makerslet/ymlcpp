#ifndef USERCHOICEREQUEST_H
#define USERCHOICEREQUEST_H

#include "../common_and_base/base_requests_responses/ServerGetRequest.h"
#include "../common_and_base/common_enums/UserChoice.h"

namespace ymlcpp {
namespace server_access  {


class UserChoiceRequest : public ServerGetRequest
{
public:
    UserChoiceRequest(const QString&, const QString&, UserChoiceType, UserChoiceContent);

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

#endif // USERCHOICEREQUEST_H
