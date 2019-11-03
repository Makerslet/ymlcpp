#include "TrackGetPathRequest.h"
#include "TrackGetPathResponse.h"

namespace ymlcpp {
namespace server_access {

TrackGetPathRequest::TrackGetPathRequest(const QString& oauth, const QUrl& trackXmlUrl) :
    ServerGetRequest(AppRequestType::TrackPathRequest),
    _oauthToken(oauth),
    _trackXmlUrl(trackXmlUrl)
{
}

QNetworkRequest TrackGetPathRequest::toNetworkRequest() const
{
    QNetworkRequest request(_trackXmlUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> TrackGetPathRequest::createResponse(const QByteArray& data) const
{
    auto response = QSharedPointer<TrackGetPathResponse>::create();
    response->parseResponse(data);
    return response.dynamicCast<IServerResponse>();
}


}
}
