#ifndef USERCHOICE_H
#define USERCHOICE_H

#include <QString>

namespace ymlcpp {
namespace server_access {

enum UserChoiceContent
{
    Albums,
    Artists,
    Playlists,
    Tracks
};

enum UserChoiceType
{
    Like,
    Dislike
};

class UserChoiceConvertor
{
public:
    static QString userChoiceContentToString(UserChoiceContent);
    static QString userChoiceContentToStringSingle(UserChoiceContent);
    static QString userChoiceTypeToString(UserChoiceType);
};


}
}

#endif // USERCHOICE_H
