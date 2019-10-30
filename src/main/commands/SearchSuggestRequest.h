#ifndef SEARCHSUGGESTREQUEST_H
#define SEARCHSUGGESTREQUEST_H

#include "common_and_base/base_requests_responses/ServerGetRequest.h"

namespace ymlcpp {
namespace server_access {

class SearchSuggestRequest : public ServerGetRequest
{
public:
    SearchSuggestRequest(const QString&, const QString&);
    QNetworkRequest toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QString createSearchUrl() const;

private:
    QString _oauthToken;
    QString _searchString;

    static const QString _searchSuggestUrl;
};


}
}

#endif // SEARCHSUGGESTREQUEST_H
