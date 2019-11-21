#ifndef SEARCHREQUEST_H
#define SEARCHREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"
#include "common_and_base/common_enums/UserChoice.h"

namespace ymlcpp {
namespace server_access {

class SearchRequest : public ServerGetRequest
{
public:
    SearchRequest(const QString&, const QString&);
    SearchRequest(const QString&, const QString&, ContentType);
    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString createSearchUrl() const;

private:
    QString _oauthToken;
    QString _searchString;

    bool _concreteContent;
    ContentType _contentType;
    static const QString _searchUrl;
};

}
}

#endif // SEARCHREQUEST_H
