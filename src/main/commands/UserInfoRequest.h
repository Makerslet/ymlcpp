#ifndef USERINFOREQUEST_H
#define USERINFOREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"

namespace ymlcpp {
namespace server_access {

class UserInfoRequest : public ServerGetRequest
{
public:
    UserInfoRequest(const QString&);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    static const QUrl _userInfoUrl;
};

}
}

#endif // USERINFOREQUEST_H
