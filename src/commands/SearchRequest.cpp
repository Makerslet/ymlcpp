#include "commands/SearchRequest.h"
#include "commands/SearchResponse.h"


namespace ymlcpp {
namespace server_access {

const QString SearchRequest::_searchUrl("https://api.music.yandex.net/search?%1");


SearchRequest::SearchRequest(const QString& oauthToken, const QString& searchString) :
    ServerGetRequest (AppRequestType::SearchRequest),
    _oauthToken(oauthToken), _searchString(searchString), _concreteContent(false)
{
}

SearchRequest::SearchRequest(const QString& oauthToken, const QString& searchString, ContentType content) :
    ServerGetRequest (AppRequestType::SearchRequest),
    _oauthToken(oauthToken), _searchString(searchString), _concreteContent(true),
    _contentType(content)
{
}

QNetworkRequest SearchRequest::toNetworkRequest() const
{
    QUrl actualUrl(_searchUrl.arg(createSearchUrl()));
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauthToken);
    request.setRawHeader("Authorization", authValue.toUtf8());
    request.setRawHeader("Content-Type", "application/json;charset=utf-8");

    return request;
}

QString SearchRequest::createSearchUrl() const
{
    QString searchUrl("text=%1"
                      "&nocorrect=False"
                      "&type=%2"
                      "&page=0"
                      "&playlist-in-best=False");

    QString copySearch = _searchString;

    copySearch.replace(" ", "+");

    if(_concreteContent)
    {
        QString stringContent = UserChoiceConvertor::userChoiceContentToStringSingle(_contentType);
        return searchUrl.arg(copySearch).arg(stringContent);
    }
    else
        return searchUrl.arg(copySearch).arg("all");

}

QSharedPointer<IServerResponse> SearchRequest::createResponse(const QByteArray& data) const
{
    auto response =  QSharedPointer<SearchResponse>::create();
    response->parseResponse(data);
    return response.dynamicCast<IServerResponse>();
}

}
}
