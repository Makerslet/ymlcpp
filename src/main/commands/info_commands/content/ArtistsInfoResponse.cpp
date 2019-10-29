#include "ArtistsInfoResponse.h"
#include "../../common_and_base/parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

ArtistsInfoResponse::ArtistsInfoResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::ContentInfoResponse)
{
    parseResponse(data);
}

ArtistsInfoResponse::~ArtistsInfoResponse()
{}

void ArtistsInfoResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        for(auto artist : resultFieldIter->toList())
            _artists.push_back(
                        ArtistDescriptionParser::parseArtistDescription(artist.toHash()));
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
    {
        // unknown error
        _respStatus = ResponseResult::Error;
    }
}

void ArtistsInfoResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

ResponseResult ArtistsInfoResponse::status() const
{
    return _respStatus;
}

QList<ArtistDescription> ArtistsInfoResponse::artistsDescription() const
{
    return _artists;
}

ErrorInfo ArtistsInfoResponse::errorInfo() const
{
    return _errInfo;
}

}
}
