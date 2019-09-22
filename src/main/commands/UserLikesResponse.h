#ifndef USERLIKESRESPONSE_H
#define USERLIKESRESPONSE_H

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

struct UserLikes
{
    uint uid;
    uint revision;
    QVector<Track> tracks;
};

class UserLikesResponse : public IServerResponse
{
public:
    UserLikesResponse(const QByteArray&);
    ~UserLikesResponse() override;

    ResponseResult status() const override;
    UserLikes userLikes() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseLibrary(const QVariantHash&);
    void parseTrack(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    UserLikes _userLikes;
    ErrorInfo _errInfo;
};

}
}

#endif // USERLIKESRESPONSE_H
