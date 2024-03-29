#include "commands/SearchSuggestResponse.h"
#include "parsers/TrackDescriptionParser.h"
#include "parsers/AlbumDescriptionParser.h"
#include "parsers/PlaylistDescriptionParser.h"
#include "parsers/ArtistDescriptionParser.h"
#include "parsers/BestParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

namespace ymlcpp {
namespace server_access {

SearchSuggestResponse::SearchSuggestResponse() :
    ServerResponse (AppResponseType::SearchSuggestResponse)
{
}

SearchSuggestResponse::~SearchSuggestResponse(){}

void SearchSuggestResponse::parseContent(const QVariant& data)
{
    auto resultFieldHash = data.toHash();
    parseBest(resultFieldHash["best"].toHash());
    parseSuggestions(resultFieldHash["suggestions"].toList());
}

void SearchSuggestResponse::parseSuggestions(const QVariantList& suggList)
{
    for(const auto& suggest : suggList)
        _result.suggestions.push_back(suggest.toString());
}

void SearchSuggestResponse::parseBest(const QVariantHash& bestHash)
{
    auto bestIter = bestHash.find("best");
    if(bestIter == bestHash.end())
        return;

    _result.best = BestParser::parseBest(bestIter.value().toHash());
}

SearchSuggestResult SearchSuggestResponse::suggestResult() const
{
    return _result;
}

}
}
