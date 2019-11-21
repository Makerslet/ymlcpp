#ifndef BESTPARSER_H
#define BESTPARSER_H

#include "commands/common_and_base/common_structures/ContentBase.h"

#include <QVariant>
#include <QSharedPointer>

namespace ymlcpp {
namespace server_access {


class BestParser
{
public:
    static QSharedPointer<ContentBase> parseBest(const QVariantHash&);
};

}
}

#endif // BESTPARSER_H
