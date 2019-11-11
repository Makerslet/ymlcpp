#include "TrackDownloadRequest.h"
#include "TrackDownloadResponse.h"


namespace ymlcpp {
namespace server_access {

const QString TrackDownloadRequest::_templateUrl("https://%1/get-mp3/randomTrash/%2%3");

TrackDownloadRequest::TrackDownloadRequest(const QString& oauthToken, const TrackPathDescription& descr) :
    ServerGetRequest (AppRequestType::TrackDownloadRequest),
    _oauthToken(oauthToken),
    _pathDescr(descr)
{}

QNetworkRequest TrackDownloadRequest::toNetworkRequest() const
{
    QString actualUrl = _templateUrl.arg(_pathDescr.host).arg(_pathDescr.ts).arg(_pathDescr.path);
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> TrackDownloadRequest::createResponse(const QByteArray& data) const
{
    auto response = QSharedPointer<TrackDownloadResponse>::create();
    response->parseResponse(data);
    return response.dynamicCast<IServerResponse>();
}



}
}
