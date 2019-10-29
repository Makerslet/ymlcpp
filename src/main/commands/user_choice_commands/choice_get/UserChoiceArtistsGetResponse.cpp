#include "UserChoiceArtistsGetResponse.h"

#include "../../common_and_base/parsers/ArtistDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserChoiceArtistsGetResponse::UserChoiceArtistsGetResponse(UserChoiceType choiceType, const QByteArray& data) :
    UserChoiceGetResponse (choiceType, ContentType::Artists)
{
    parseResponse(data);
}

UserChoiceArtistsGetResponse::~UserChoiceArtistsGetResponse()
{
}

QVector<ArtistDescription> UserChoiceArtistsGetResponse::userLikes() const
{
    return _userLikes;
}

void UserChoiceArtistsGetResponse::parseResponse(const QByteArray& data)
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

}
}
