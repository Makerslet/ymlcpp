#ifndef USERLIKESREQUEST_H
#define USERLIKESREQUEST_H

#include "ServerGetRequest.h"

namespace ymlcpp {
namespace server_access  {


class UserLikesRequest : public ServerGetRequest
{
public:
    UserLikesRequest(const QString&, const QString&login);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    QString _login;

    static const QString _templateUrl;
};

}
}

#endif // USERLIKESREQUEST_H
