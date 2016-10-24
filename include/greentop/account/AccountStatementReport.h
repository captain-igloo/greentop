/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTSTATEMENTREPORT_H
#define ACCOUNTSTATEMENTREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/StatementItem.h"

namespace greentop {

/**
 * A container representing search results.
 */
class AccountStatementReport : public JsonResponse {
    public:
        AccountStatementReport();

        AccountStatementReport(const std::vector<StatementItem>& accountStatement,
            const bool moreAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<StatementItem>& getAccountStatement() const;
        void setAccountStatement(const std::vector<StatementItem>& accountStatement);

        const bool getMoreAvailable() const;
        void setMoreAvailable(const bool moreAvailable);


    private:
        /**
         * The list of statement items returned by your request.
         */
        std::vector<StatementItem> accountStatement;
        /**
         * Indicates whether there are further result items beyond this page.
         */
        bool moreAvailable;
};

}

#endif // ACCOUNTSTATEMENTREPORT_H


