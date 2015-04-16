#ifndef ACCOUNTSTATEMENTREPORT_H
#define ACCOUNTSTATEMENTREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonResponse.h"
#include "greentop/account/StatementItem.h"

namespace greentop {

class AccountStatementReport : public JsonResponse {
    public:

        AccountStatementReport(const std::vector<StatementItem>& accountStatement = std::vector<StatementItem>(),
            const BoolJsonMember& moreAvailable = BoolJsonMember());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<StatementItem>& getAccountStatement() const;
        void setAccountStatement(const std::vector<StatementItem>& accountStatement);

        const BoolJsonMember& getMoreAvailable() const;
        void setMoreAvailable(const BoolJsonMember& moreAvailable);


    private:
        std::vector<StatementItem> accountStatement;
        BoolJsonMember moreAvailable;
};

}

#endif // ACCOUNTSTATEMENTREPORT_H


