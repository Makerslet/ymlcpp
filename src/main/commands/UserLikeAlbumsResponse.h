#ifndef USERLIKEALBUMSRESPONSE_H
#define USERLIKEALBUMSRESPONSE_H

#include "headers/IServerResponse.h"

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


class UserLikeAlbumsResponse : public IServerResponse
{
public:
    UserLikeAlbumsResponse(const QByteArray&);
    ~UserLikeAlbumsResponse() override;

    ResponseResult status() const override;
    QVector<LikeAlbum> userLikes() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseAlbum(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QVector<LikeAlbum> _userLikes;
    ErrorInfo _errInfo;
};

}
}

#endif // USERLIKEALBUMSRESPONSE_H
