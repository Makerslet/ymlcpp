#include "UserLikeArtistsResponse.h"
#include "parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserLikeArtistsResponse::UserLikeArtistsResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserLikeArtistsResponse)
{
    qDebug() << data;
    parseResponse(data);
}

UserLikeArtistsResponse::~UserLikeArtistsResponse()
{
}

ResponseResult UserLikeArtistsResponse::status() const
{
    return _respStatus;
}
QVector<ArtistDescription> UserLikeArtistsResponse::userLikes() const
{
    return _userLikes;
}

ErrorInfo UserLikeArtistsResponse::errorInfo() const
{
    return _errInfo;
}


void UserLikeArtistsResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        for(auto artist : resultFieldIter.value().toList())
            _userLikes.push_back(ArtistDescriptionParser::parseArtistDescription(artist.toHash()));
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void UserLikeArtistsResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
