#include "UserChoice.h"

namespace ymlcpp {
namespace server_access {

    QString UserChoiceConvertor::userChoiceContentToString(UserChoiceContent content)
    {
        switch (content) {
        case UserChoiceContent::Albums:     return "albums";
        case UserChoiceContent::Artists:    return "artists";
        case UserChoiceContent::Playlists:  return "playlists";
        case UserChoiceContent::Tracks:     return "tracks";

        }
    }

    QString UserChoiceConvertor::userChoiceContentToStringSingle(UserChoiceContent content)
    {
        auto result = userChoiceContentToString(content);
        return result.remove(result.length() - 1, 1);
    }

    QString UserChoiceConvertor::userChoiceTypeToString(UserChoiceType type)
    {
        switch (type) {
        case UserChoiceType::Like: return "likes";
        case UserChoiceType::Dislike: return "dislikes";
        }
    }

}
}
