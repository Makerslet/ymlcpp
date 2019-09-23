#ifndef USERLIKETRACKSRESPONSE_H
#define USERLIKETRACKSRESPONSE_H

#include "headers/IServerResponse.h"

#include <QVariant>
#include <QVector>
#include <QDateTime>

namespace ymlcpp {
namespace server_access {

struct Track
{
    QString id;
    QString albumId;
    QDateTime timestamp; // like timestamp
};

struct UserLikeTracks
{
    uint uid;
    uint revision;
    QVector<Track> tracks;
};

class UserLikeTracksResponse : public IServerResponse
{
public:
    UserLikeTracksResponse(const QByteArray&);
    ~UserLikeTracksResponse() override;

    ResponseResult status() const override;
    UserLikeTracks userLikes() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseLibrary(const QVariantHash&);
    void parseTrack(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    UserLikeTracks _userLikes;
    ErrorInfo _errInfo;
};

}
}

#endif // USERLIKETRACKSRESPONSE_H
