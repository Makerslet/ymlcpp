#include "ContentInfoRequest.h"
#include "AlbumsInfoResponse.h"
#include "ArtistsInfoResponse.h"
#include "TracksInforesponse.h"
#include "PlaylistsInfoResponse.h"

#include <QDebug>

namespace ymlcpp {
namespace server_access {

const QString ContentInfoRequest::_templateUrl("https://api.music.yandex.net/%1");

ContentInfoRequest::ContentInfoRequest(const QString& oauth, ContentType contentType, QStringList ids) :
    ServerPostRequest (AppRequestType::ContentInfoRequest),
    _oauth(oauth),
    _contentType(contentType),
    _ids(ids)
{
}

QPair<QNetworkRequest, QByteArray> ContentInfoRequest::toNetworkRequest() const
{
    auto payload = preparePayload();
    auto request = prepareRequest(payload.length());
    return qMakePair(request, payload);
}

QSharedPointer<IServerResponse> ContentInfoRequest::createResponse(const QByteArray& data) const
{
    switch (_contentType) {
    case ContentType::Albums:       return QSharedPointer<AlbumsInfoResponse>::create(data);
    case ContentType::Artists:      return QSharedPointer<ArtistsInfoResponse>::create(data);
    case ContentType::Playlists:    return QSharedPointer<PlaylistsInfoResponse>::create(data);
    case ContentType::Tracks:       return QSharedPointer<TracksInfoResponse>::create(data);
    }
}

QNetworkRequest ContentInfoRequest::prepareRequest(int payloadLen) const
{
    QString contentTypeStr = UserChoiceConvertor::userChoiceContentToString(_contentType);
    if(_contentType == ContentType::Playlists)
        contentTypeStr.push_back("/list");

    QUrl actualUrl(_templateUrl.arg(contentTypeStr));
    QNetworkRequest request(actualUrl);
    qDebug() << actualUrl;

    QString authValue = QString("OAuth %1").arg(_oauth);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, payloadLen);
    return  request;
}

QByteArray ContentInfoRequest::preparePayload() const
{
    QString contentId = QString("%1-ids").arg(
                UserChoiceConvertor::userChoiceContentToStringSingle(_contentType));

    QByteArray apiformat;
    if(_contentType == ContentType::Tracks)
        apiformat = toApiFormat(contentId, "with-positions", _ids);
    else
        apiformat = toApiFormat(contentId, _ids);

    qDebug() << apiformat;
    return apiformat;
}

}
}
