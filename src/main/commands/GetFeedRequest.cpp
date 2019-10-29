#include "GetFeedRequest.h"
#include "GetFeedResponse.h"

namespace ymlcpp {
namespace server_access {

const QUrl GetFeedRequest::_userInfoUrl("https://api.music.yandex.net/feed");


GetFeedRequest::GetFeedRequest(const QString& oauthToken) :
    ServerGetRequest (AppRequestType::FeedRequest),
    _oauthToken(oauthToken)
{

}

QNetworkRequest GetFeedRequest::toNetworkRequest() const
{
    QNetworkRequest request(_userInfoUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> GetFeedRequest::createResponse(const QByteArray& data) const
{
    return  QSharedPointer<GetFeedResponse>::create(data);
}

}
}
