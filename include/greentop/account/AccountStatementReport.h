/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTSTATEMENTREPORT_H
#define ACCOUNTSTATEMENTREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"
#include "greentop/account/StatementItem.h"

namespace greentop {
/**
 * A container representing search results.
 */
class AccountStatementReport : public JsonResponse {
    public:
        AccountStatementReport();

        AccountStatementReport(const std::vector<StatementItem>& accountStatement,
            const Optional<bool>& moreAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<StatementItem>& getAccountStatement() const;
        void setAccountStatement(const std::vector<StatementItem>& accountStatement);

        const Optional<bool>& getMoreAvailable() const;
        void setMoreAvailable(const Optional<bool>& moreAvailable);


    private:
        /**
         * The list of statement items returned by your request.
         */
        std::vector<StatementItem> accountStatement;
        /**
         * Indicates whether there are further result items beyond this page.
         */
        Optional<bool> moreAvailable;
};

}

#endif // ACCOUNTSTATEMENTREPORT_H
