#ifndef SEARCHSUGGESTRESPONSE_H
#define SEARCHSUGGESTRESPONSE_H

#include "common_and_base/base_requests_responses/IServerResponse.h"

#include <QVariant>
#include <QVector>

namespace ymlcpp {
namespace server_access {

struct SearchSuggestResult
{

};

class SearchSuggestResponse : public IServerResponse
{
public:
    SearchSuggestResponse(const QByteArray&);
    ~SearchSuggestResponse() override;

    ResponseResult status() const override;
    ErrorInfo errorInfo() const;
    SearchSuggestResult description() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    SearchSuggestResult _result;
    ErrorInfo _errInfo;
};

}
}

#endif // SEARCHSUGGESTRESPONSE_H
