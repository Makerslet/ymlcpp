#ifndef CONTENTBASE_H
#define CONTENTBASE_H

#include "../common_enums/UserChoice.h"

namespace ymlcpp {
namespace server_access {


class ContentBase {
public:
    virtual ~ContentBase(){}
    virtual ContentType contentType() const = 0;
};

}
}

#endif // CONTENTBASE_H
