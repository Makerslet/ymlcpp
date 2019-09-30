#ifndef CONTENTINFOREQUEST_H
#define CONTENTINFOREQUEST_H

#include "../common_and_base/base_requests_responses/ServerPostRequest.h"
#include "../common_and_base/common_enums/UserChoice.h"

#include <QPair>
#include <QNetworkRequest>

namespace ymlcpp {
namespace server_access {

class ContentInfoRequest : public ServerPostRequest
{
public:
    ContentInfoRequest(const QString&, ContentType, QStringList);
    QPair<QNetworkRequest, QByteArray> toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QNetworkRequest prepareRequest(int payloadLen) const;
    QByteArray preparePayload() const;

private:
    const QString _oauth;
    const ContentType _contentType;
    const QStringList _ids;

    static const QString _templateUrl;
};

}
}
#endif // CONTENTINFOREQUEST_H
