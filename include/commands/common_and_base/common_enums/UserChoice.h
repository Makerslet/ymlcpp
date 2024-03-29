#ifndef USERCHOICE_H
#define USERCHOICE_H

#include <QString>

namespace ymlcpp {
namespace server_access {

enum class ContentType
{
    Albums,
    Artists,
    Playlists,
    Tracks,
    Unknown
};

enum class UserChoiceType
{
    Like,
    Dislike
};

enum class UserAction
{
    AddMultiple,
    Remove
};

class UserChoiceConvertor
{
public:
    static QString userChoiceContentToString(ContentType);
    static QString userChoiceContentToStringSingle(ContentType);
    static QString userChoiceTypeToString(UserChoiceType);
    static QString userActionToString(UserAction);
    static ContentType contentTypeFromString(const QString&);
};


}
}

#endif // USERCHOICE_H
