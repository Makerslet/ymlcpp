#ifndef USERCHOICEALBUMSGETRESPONSE_H
#define USERCHOICEALBUMSGETRESPONSE_H

#include "UserChoiceGetResponse.h"

#include <QVariant>
#include <QDateTime>
#include <QVector>

namespace ymlcpp {
namespace server_access {

struct LikeAlbum
{
    uint id;
    QDateTime timestamp;
};


class UserChoiceAlbumsGetResponse : public UserChoiceGetResponse
{
public:
    UserChoiceAlbumsGetResponse(UserChoiceType, const QByteArray&);
    ~UserChoiceAlbumsGetResponse() override;

    QVector<LikeAlbum> userLikes() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseAlbum(const QVariantHash&);

private:
    QVector<LikeAlbum> _userLikes;
};

}
}

#endif // USERCHOICEALBUMSGETRESPONSE_H
