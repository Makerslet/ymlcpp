#ifndef USERCHOICEARTISTSGETRESPONSE_H
#define USERCHOICEARTISTSGETRESPONSE_H

#include "UserChoiceGetResponse.h"
#include "../../common_and_base/common_structures/ArtistDescription.h"

#include <QVector>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


class UserChoiceArtistsGetResponse : public UserChoiceGetResponse
{
public:
    UserChoiceArtistsGetResponse(UserChoiceType, const QByteArray&);
    ~UserChoiceArtistsGetResponse() override;

    QVector<ArtistDescription> userLikes() const;

private:
    void parseResponse(const QByteArray&) override;

private:
    QVector<ArtistDescription> _userLikes;
};

}
}

#endif // USERCHOICEARTISTSGETRESPONSE_H
