#ifndef USERCHOICETRACKSGETRESPONSE_H
#define USERCHOICETRACKSGETRESPONSE_H

#include "UserChoiceGetResponse.h"

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

class UserChoiceTracksGetResponse : public UserChoiceGetResponse
{
public:
    UserChoiceTracksGetResponse(UserChoiceType, const QByteArray&);
    ~UserChoiceTracksGetResponse() override;

    UserLikeTracks userLikes() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseLibrary(const QVariantHash&);
    void parseTrack(const QVariantHash&);

private:
    UserLikeTracks _userLikes;
};

}
}

#endif // USERCHOICETRACKSGETRESPONSE_H
