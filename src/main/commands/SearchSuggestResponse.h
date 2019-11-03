#ifndef SEARCHSUGGESTRESPONSE_H
#define SEARCHSUGGESTRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"

#include <QVariant>
#include <QVector>

namespace ymlcpp {
namespace server_access {

struct SearchSuggestResult
{
    //QSharedPointer<void> best;
    QStringList suggestions;
};

class SearchSuggestResponse : public ServerResponse
{
public:
    SearchSuggestResponse();
    ~SearchSuggestResponse() override;

    SearchSuggestResult suggestResult() const;

private:
    void parseContent(const QVariant&) override;
    void parseSuggestions(const QVariantList &);
    void parseBest(const QVariantHash &);

private:
    SearchSuggestResult _result;
};

}
}

#endif // SEARCHSUGGESTRESPONSE_H
