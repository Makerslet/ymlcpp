#ifndef GENRESRESPONSE_H
#define GENRESRESPONSE_H

#include "common_and_base/base_requests_responses/IServerResponse.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

struct GenreDescription
{

};

class GenresResponse : public IServerResponse
{
public:
    GenresResponse(const QByteArray&);
    ~GenresResponse() override;

    ResponseResult status() const override;
    GenreDescription genreDescription() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseResult(const QVariantHash &);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    GenreDescription _genreDescription;
    ErrorInfo _errInfo;
};

}
}

#endif // GENRESRESPONSE_H
