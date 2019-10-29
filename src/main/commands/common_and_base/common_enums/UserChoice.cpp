#include "UserChoice.h"

namespace ymlcpp {
namespace server_access {

    QString UserChoiceConvertor::userChoiceContentToString(ContentType content)
    {
        switch (content) {
        case ContentType::Albums:     return "albums";
        case ContentType::Artists:    return "artists";
        case ContentType::Playlists:  return "playlists";
        case ContentType::Tracks:     return "tracks";

        }
    }

    QString UserChoiceConvertor::userChoiceContentToStringSingle(ContentType content)
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

    QString UserChoiceConvertor::userActionToString(UserAction action)
    {
        switch (action) {
        case UserAction::AddMultiple:   return "add-multiple";
        case UserAction::Remove:        return "remove";
        }
    }

}
}
