#ifndef USERCHOICEARTISTSRESPONSE_H
#define USERCHOICEARTISTSRESPONSE_H

#include "UserChoiceResponse.h"
#include "../common_and_base/common_structures/ArtistDescription.h"

#include <QVector>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


class UserChoiceArtistsResponse : public UserChoiceResponse
{
public:
    UserChoiceArtistsResponse(UserChoiceType, const QByteArray&);
    ~UserChoiceArtistsResponse() override;

    QVector<ArtistDescription> userLikes() const;

private:
    void parseResponse(const QByteArray&) override;

private:
    QVector<ArtistDescription> _userLikes;
};

}
}

#endif // USERCHOICEARTISTSRESPONSE_H
