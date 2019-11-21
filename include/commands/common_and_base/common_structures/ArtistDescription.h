#ifndef ARTISTDESCRIPTION_H
#define ARTISTDESCRIPTION_H

#include "ContentBase.h"

#include <QString>
#include <QStringList>
#include <QUrl>

namespace ymlcpp {
namespace server_access {

struct ArtistCover
{
    QString type;
    QString prefix;
    QString uri;
};

struct ArtistCounts
{
    uint tracks;
    uint directAlbums;
    uint alsoAlbums;
    uint alsoTracks;
};

struct ArtistRaitings
{
    uint week;
    uint month;
    uint day;
};

struct ArtistLink
{
    QString title;
    QUrl href;
    QString type;
    QString socialNetwork;
};


struct ArtistDescription : public ContentBase
{
    QString id;
    QString name;
    bool various;
    bool composer;
    ArtistCover cover;
    QString ogImage;
    QStringList genres;
    ArtistCounts counts;
    bool available;
    ArtistRaitings raitings;
    QList<ArtistLink> links;
    bool ticketsAvailable;

    ContentType contentType() const override {return  ContentType::Artists;}
};

}
}

#endif // ARTISTDESCRIPTION_H
