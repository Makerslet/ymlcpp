#ifndef USERLIKEPLAYLISTSRESPONSE_H
#define USERLIKEPLAYLISTSRESPONSE_H

#include "headers/IServerResponse.h"
#include "common_structures/PlaylistDescription.h"

#include <QVector>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


class UserLikePlaylistsResponse : public IServerResponse
{
public:
    UserLikePlaylistsResponse(const QByteArray&);
    ~UserLikePlaylistsResponse() override;

    ResponseResult status() const override;
    QVector<PlaylistDescription> userLikes() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QVector<PlaylistDescription> _userLikes;
    ErrorInfo _errInfo;
};

}
}

#endif // USERLIKEPLAYLISTSRESPONSE_H
