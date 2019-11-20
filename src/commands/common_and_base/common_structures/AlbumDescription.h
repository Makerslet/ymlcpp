#ifndef ALBUMDESCRIPTION_H
#define ALBUMDESCRIPTION_H

#include "ContentBase.h"
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

struct AlbumDescription : public ContentBase
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

    ContentType contentType() const override {return ContentType::Albums;}
};

}
}

#endif // ALBUMDESCRIPTION_H
