#ifndef USERLIKESREQUEST_H
#define USERLIKESREQUEST_H

#include "ServerGetRequest.h"

namespace ymlcpp {
namespace server_access  {

enum class LikesType
{
    Albums,
    Artists,
    Playlists,
    Tracks
};

class UserLikesRequest : public ServerGetRequest
{
public:
    UserLikesRequest(const QString&, const QString&, LikesType);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    QString _login;
    LikesType _likesType;

    static const QString _templateUrl;
};

}
}

#endif // USERLIKESREQUEST_H
