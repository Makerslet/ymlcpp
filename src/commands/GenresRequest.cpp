#include "GenresRequest.h"
#include "GenresResponse.h"

namespace ymlcpp {
namespace server_access {

const QUrl GenresRequest::_url("https://api.music.yandex.net/genres");

GenresRequest::GenresRequest(const QString& oauth) :
    ServerGetRequest (AppRequestType::GenresRequest),
    _oauthToken(oauth)
{
}

QNetworkRequest GenresRequest::toNetworkRequest() const
{
    QNetworkRequest request(_url);
    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QSharedPointer<IServerResponse> GenresRequest::createResponse(const QByteArray& data) const
{
    auto response = QSharedPointer<GenresResponse>::create();
    response->parseResponse(data);
    return response.dynamicCast<IServerResponse>();
}


}
}
