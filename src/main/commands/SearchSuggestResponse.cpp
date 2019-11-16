#include "SearchSuggestResponse.h"
#include "common_and_base/parsers/TrackDescriptionParser.h"
#include "common_and_base/parsers/AlbumDescriptionParser.h"
#include "common_and_base/parsers/PlaylistDescriptionParser.h"
#include "common_and_base/parsers/ArtistDescriptionParser.h"

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
    auto contentType = bestHash["type"].toString();
    auto content = bestHash["result"].toHash();

    if(contentType == "track")
    {
        auto trackDescr = TrackDescriptionParser::parseTrackDescription(content);
    }
    else if(contentType == "album")
    {
        auto albumDescr = AlbumDescriptionParser::parseAlbumDescription(content);
    }
    else if(contentType == "playlist")
    {
        auto playlistDescr = PlaylistDescriptionParser::parsePlaylistInfo(content);
    }
    else if(contentType == "artist")
    {
        auto artistDescr = ArtistDescriptionParser::parseArtistDescription(content);
    }

    auto text = bestHash["text"].toString();
    _result.suggestions.push_back(text);
}

SearchSuggestResult SearchSuggestResponse::suggestResult() const
{
    return _result;
}

}
}
