#ifndef USERCHOICEPLAYLISTSGETRESPONSE_H
#define USERCHOICEPLAYLISTSGETRESPONSE_H

#include "UserChoiceGetResponse.h"
#include "../../common_and_base/common_structures/PlaylistDescription.h"

#include <QVector>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


class UserChoicePlaylistsGetResponse : public UserChoiceGetResponse
{
public:
    UserChoicePlaylistsGetResponse(UserChoiceType);
    ~UserChoicePlaylistsGetResponse() override;

    QVector<PlaylistDescription> userLikes() const;

private:
    void parseContent(const QVariant&) override;

private:
    QVector<PlaylistDescription> _userLikes;
};

}
}

#endif // USERCHOICEPLAYLISTSGETRESPONSE_H
