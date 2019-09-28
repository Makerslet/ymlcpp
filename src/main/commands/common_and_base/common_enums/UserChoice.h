#ifndef USERCHOICE_H
#define USERCHOICE_H

#include <QString>

namespace ymlcpp {
namespace server_access {

enum class UserChoiceContent
{
    Albums,
    Artists,
    Playlists,
    Tracks
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
    static QString userChoiceContentToString(UserChoiceContent);
    static QString userChoiceContentToStringSingle(UserChoiceContent);
    static QString userChoiceTypeToString(UserChoiceType);
    static QString userActionToString(UserAction);
};


}
}

#endif // USERCHOICE_H
