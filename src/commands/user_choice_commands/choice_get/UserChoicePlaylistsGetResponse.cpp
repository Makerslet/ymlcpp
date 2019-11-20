#include "UserChoicePlaylistsGetResponse.h"
#include "../../common_and_base/parsers/PlaylistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

UserChoicePlaylistsGetResponse::UserChoicePlaylistsGetResponse(UserChoiceType choiceType) :
    UserChoiceGetResponse(choiceType, ContentType::Playlists)
{}

UserChoicePlaylistsGetResponse::~UserChoicePlaylistsGetResponse()
{}

QVector<PlaylistDescription> UserChoicePlaylistsGetResponse::userLikes() const
{
    return _userLikes;
}



void UserChoicePlaylistsGetResponse::parseContent(const QVariant& data)
{
    for(auto playlist : data.toList())
        _userLikes.push_back(PlaylistDescriptionParser::parsePlaylistDescription(
                                 playlist.toHash()));
}

}
}
