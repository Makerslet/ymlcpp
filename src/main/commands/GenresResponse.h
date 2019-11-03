#ifndef GENRESRESPONSE_H
#define GENRESRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

struct GenreDescription
{

};

class GenresResponse : public ServerResponse
{
public:
    GenresResponse();
    ~GenresResponse() override;
    GenreDescription genreDescription() const;

private:
    void parseContent(const QVariant&) override;

private:
    GenreDescription _genreDescription;
};

}
}

#endif // GENRESRESPONSE_H
