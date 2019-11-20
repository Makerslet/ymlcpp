#include "SearchSuggestRequest.h"
#include "SearchSuggestResponse.h"

namespace ymlcpp {
namespace server_access {

const QString SearchSuggestRequest::_searchSuggestUrl("https://api.music.yandex.net/search/suggest?%1");

SearchSuggestRequest::SearchSuggestRequest(const QString& oauthToken, const QString& searchString) :
    ServerGetRequest (AppRequestType::SearchSuggestRequest),
    _oauthToken(oauthToken), _searchString(searchString)
{
}

QNetworkRequest SearchSuggestRequest::toNetworkRequest() const
{
    QUrl actualUrl(_searchSuggestUrl.arg(createSearchUrl()));
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QString SearchSuggestRequest::createSearchUrl() const
{
    QString searchUrl("part=%1");

    QString copySearch = _searchString;
    copySearch.replace(" ", "+");

    return searchUrl.arg(copySearch);

}

QSharedPointer<IServerResponse> SearchSuggestRequest::createResponse(const QByteArray& data) const
{
    auto response = QSharedPointer<SearchSuggestResponse>::create();
    response->parseResponse(data);
    return response.dynamicCast<IServerResponse>();
}

}
}
