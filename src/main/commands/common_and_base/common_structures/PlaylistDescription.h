#ifndef PLAYLISTDESCRIPTION_H
#define PLAYLISTDESCRIPTION_H

#include <QString>
#include <QDateTime>

namespace ymlcpp {
namespace server_access {

struct PlaylistOwner
{
    uint uid;
    QString login;
    QString name;
    QString sex;
    bool verified;
};

struct PlaylistCover
{
    QString type;
    QString dir;
    QString version;
    QString uri;
    bool custom;
};

struct PlaylistInfo
{
    PlaylistOwner owner;
    uint uid;
    uint kind;
    QString title;
    QString description;
    QString descriptionFormatted;
    uint revision;
    uint snapshot;
    uint trackCount;
    QString visibility;
    bool collective;
    QDateTime created;
    QDateTime modified;
    bool available;
    bool isBanner;
    bool isPremiere;
    QString idForFrom;
    uint durationMs;
    PlaylistCover cover;
    QString ogImage;
    QStringList tags;
    QStringList prerolls;
};

struct PlaylistDescription
{
    PlaylistInfo description;
    QDateTime timestamp;
};



}
}


#endif // PLAYLISTDESCRIPTION_H
