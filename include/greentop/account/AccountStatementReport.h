/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTSTATEMENTREPORT_H
#define ACCOUNTSTATEMENTREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"
#include "greentop/account/StatementItem.h"

namespace greentop {

class AccountStatementReport : public JsonResponse {
    public:

        AccountStatementReport(const std::vector<StatementItem>& accountStatement = std::vector<StatementItem>(),
            const Optional<bool>& moreAvailable = Optional<bool>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<StatementItem>& getAccountStatement() const;
        void setAccountStatement(const std::vector<StatementItem>& accountStatement);

        const Optional<bool>& getMoreAvailable() const;
        void setMoreAvailable(const Optional<bool>& moreAvailable);


    private:
        std::vector<StatementItem> accountStatement;
        Optional<bool> moreAvailable;
};

}

#endif // ACCOUNTSTATEMENTREPORT_H


