#include "commands/GenresResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {


GenresResponse::GenresResponse() :
    ServerResponse (AppResponseType::GenresResponse)
{}

GenresResponse::~GenresResponse(){}

GenreDescription GenresResponse::genreDescription() const
{
    return _genreDescription;
}

void GenresResponse::parseContent(const QVariant&)
{}

}
}
