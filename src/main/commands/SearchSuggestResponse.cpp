#include "SearchSuggestResponse.h"
#include "common_and_base/parsers/TrackDescriptionParser.h"
#include "common_and_base/parsers/AlbumDescriptionParser.h"
#include "common_and_base/parsers/PlaylistDescriptionParser.h"
#include "common_and_base/parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

SearchSuggestResponse::SearchSuggestResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::SearchSuggestResponse)
{
    parseResponse(data);
}

SearchSuggestResponse::~SearchSuggestResponse(){}

ResponseResult SearchSuggestResponse::status() const
{
    return _respStatus;
}

void SearchSuggestResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        auto resultFieldHash = resultFieldIter.value().toHash();
        parseBest(resultFieldHash["best"].toHash());
        parseSuggestions(resultFieldHash["suggestions"].toList());
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
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

ErrorInfo SearchSuggestResponse::errorInfo() const
{
    return _errInfo;
}

void SearchSuggestResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

SearchSuggestResult SearchSuggestResponse::description() const
{
    return _result;
}


}
}
