#ifndef GENRESREQUEST_H
#define GENRESREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"

#include <QUrl>

namespace ymlcpp {
namespace server_access {


class GenresRequest : public ServerGetRequest
{
public:
    GenresRequest(const QString&);

    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString _oauthToken;
    static const QUrl _url;
};

}
}

#endif // GENRESREQUEST_H
