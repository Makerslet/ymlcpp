#include "UserLikePlaylistsResponse.h"
#include "parsers/PlaylistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserLikePlaylistsResponse::UserLikePlaylistsResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserLikePlaylistsResponse)
{
    qDebug() << data;
    parseResponse(data);
}

UserLikePlaylistsResponse::~UserLikePlaylistsResponse()
{
}

ResponseResult UserLikePlaylistsResponse::status() const
{
    return _respStatus;
}
QVector<PlaylistDescription> UserLikePlaylistsResponse::userLikes() const
{
    return _userLikes;
}

ErrorInfo UserLikePlaylistsResponse::errorInfo() const
{
    return _errInfo;
}


void UserLikePlaylistsResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        for(auto playlist : resultFieldIter.value().toList())
            _userLikes.push_back(PlaylistDescriptionParser::parsePlaylistDescription(playlist.toHash()));
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void UserLikePlaylistsResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
