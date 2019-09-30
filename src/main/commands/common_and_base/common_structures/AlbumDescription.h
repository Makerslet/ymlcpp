#ifndef ALBUMDESCRIPTION_H
#define ALBUMDESCRIPTION_H

#include "ArtistDescription.h"

#include <QString>
#include <QStringList>
#include <QDateTime>

namespace ymlcpp {
namespace server_access {

struct BuyAlbumDescription
{

};

struct LabelDescription
{
    uint id;
    QString name;
};

struct BestDescription
{

};

struct AlbumDescription
{
    uint id;
    QString title;
    uint year;
    QDateTime releaseTime;
    QString coverUri;
    QString ogImage;
    QString genre;
    QList<BuyAlbumDescription> buyDescriptions;
    uint trackCount;
    bool recent;
    bool veryImportant;
    QList<ArtistDescription> artists;
    QList<LabelDescription> labels;
    bool available;
    bool availableForPremiumUsers;
    bool availableForMobile;
    bool availablePartially;
    QList<BestDescription> bests;
};

}
}

#endif // ALBUMDESCRIPTION_H
