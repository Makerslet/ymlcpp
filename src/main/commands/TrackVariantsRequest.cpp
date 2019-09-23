#include "TrackVariantsRequest.h"
#include "TrackVariantsResponse.h"

namespace ymlcpp {
namespace server_access {

const QString TrackVariantsRequest::_templateUrl("https://api.music.yandex.net/tracks/%1/download-info");

TrackVariantsRequest::TrackVariantsRequest(const QString& oauthToken, const QString& trackId) :
    ServerGetRequest (AppRequestType::TrackVariantsRequest),
    _oauthToken(oauthToken),
    _trackId(trackId)
{

}

QNetworkRequest TrackVariantsRequest::toNetworkRequest() const
{
    QUrl actualUrl = _templateUrl.arg(_trackId);
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> TrackVariantsRequest::createResponse(const QByteArray& data) const
{
    return QSharedPointer<TrackVariantsResponse>::create(data);
}

}
}
