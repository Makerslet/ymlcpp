#ifndef USERCHOICEALBUMSRESPONSE_H
#define USERCHOICEALBUMSRESPONSE_H

#include "UserChoiceResponse.h"

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


class UserChoiceAlbumsResponse : public UserChoiceResponse
{
public:
    UserChoiceAlbumsResponse(UserChoiceType, const QByteArray&);
    ~UserChoiceAlbumsResponse() override;

    QVector<LikeAlbum> userLikes() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseAlbum(const QVariantHash&);

private:
    QVector<LikeAlbum> _userLikes;
};

}
}

#endif // USERCHOICEALBUMSRESPONSE_H
