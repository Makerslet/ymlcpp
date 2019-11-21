#include "commands/user_choice_commands/choice_get/UserChoiceArtistsGetResponse.h"
#include "parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

UserChoiceArtistsGetResponse::UserChoiceArtistsGetResponse(UserChoiceType choiceType) :
    UserChoiceGetResponse (choiceType, ContentType::Artists)
{}

UserChoiceArtistsGetResponse::~UserChoiceArtistsGetResponse()
{}

QVector<ArtistDescription> UserChoiceArtistsGetResponse::userLikes() const
{
    return _userLikes;
}

void UserChoiceArtistsGetResponse::parseContent(const QVariant& data)
{
    for(auto artist : data.toList())
        _userLikes.push_back(ArtistDescriptionParser::parseArtistDescription(
                                 artist.toHash()));
}

}
}
