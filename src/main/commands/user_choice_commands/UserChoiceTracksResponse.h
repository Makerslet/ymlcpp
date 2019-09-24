#ifndef USERCHOICETRACKSRESPONSE_H
#define USERCHOICETRACKSRESPONSE_H

#include "UserChoiceResponse.h"

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

class UserChoiceTracksResponse : public UserChoiceResponse
{
public:
    UserChoiceTracksResponse(UserChoiceType, const QByteArray&);
    ~UserChoiceTracksResponse() override;

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

#endif // USERCHOICETRACKSRESPONSE_H
