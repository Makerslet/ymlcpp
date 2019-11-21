#ifndef TRACKPATHDESCRIPTION_H
#define TRACKPATHDESCRIPTION_H

#include <QString>

namespace ymlcpp {
namespace server_access {

struct TrackPathDescription
{
    QString host;
    QString path;
    QString ts;
    QString s;
    int region;
};

}
}


#endif // TRACKPATHDESCRIPTION_H
