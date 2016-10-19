/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TRANSFERRESPONSE_H
#define TRANSFERRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {

class TransferResponse : public JsonResponse {
    public:
        TransferResponse();

        TransferResponse(const std::string& transactionId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getTransactionId() const;
        void setTransactionId(const std::string& transactionId);


    private:
        std::string transactionId;
};

}

#endif // TRANSFERRESPONSE_H


