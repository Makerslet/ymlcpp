#ifndef USERCHOICE_H
#define USERCHOICE_H

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

}
}

#endif // USERCHOICE_H
