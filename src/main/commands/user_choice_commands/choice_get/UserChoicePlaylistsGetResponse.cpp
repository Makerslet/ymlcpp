#include "UserChoicePlaylistsGetResponse.h"
#include "../../common_and_base/parsers/PlaylistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserChoicePlaylistsGetResponse::UserChoicePlaylistsGetResponse(UserChoiceType choiceType, const QByteArray& data) :
    UserChoiceGetResponse(choiceType, ContentType::Playlists)
{
    parseResponse(data);
}

UserChoicePlaylistsGetResponse::~UserChoicePlaylistsGetResponse()
{
}

QVector<PlaylistDescription> UserChoicePlaylistsGetResponse::userLikes() const
{
    return _userLikes;
}



void UserChoicePlaylistsGetResponse::parseResponse(const QByteArray& data)
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

}
}
