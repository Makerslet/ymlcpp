#ifndef USERCHOICEPLAYLISTSRESPONSE_H
#define USERCHOICEPLAYLISTSRESPONSE_H

#include "UserChoiceResponse.h"
#include "../common_and_base/common_structures/PlaylistDescription.h"

#include <QVector>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


class UserChoicePlaylistsResponse : public UserChoiceResponse
{
public:
    UserChoicePlaylistsResponse(UserChoiceType, const QByteArray&);
    ~UserChoicePlaylistsResponse() override;

    QVector<PlaylistDescription> userLikes() const;

private:
    void parseResponse(const QByteArray&) override;

private:
    QVector<PlaylistDescription> _userLikes;
};

}
}

#endif // USERCHOICEPLAYLISTSRESPONSE_H
