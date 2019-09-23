#ifndef USERLIKEARTISTSRESPONSE_H
#define USERLIKEARTISTSRESPONSE_H

#include "headers/IServerResponse.h"
#include "common_structures/ArtistDescription.h"

#include <QVector>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


class UserLikeArtistsResponse : public IServerResponse
{
public:
    UserLikeArtistsResponse(const QByteArray&);
    ~UserLikeArtistsResponse() override;

    ResponseResult status() const override;
    QVector<ArtistDescription> userLikes() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QVector<ArtistDescription> _userLikes;
    ErrorInfo _errInfo;
};

}
}

#endif // USERLIKEARTISTSRESPONSE_H
