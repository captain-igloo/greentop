/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEINSTRUCTIONREPORT_H
#define UPDATEINSTRUCTIONREPORT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/sport/UpdateInstruction.h"

namespace greentop {

class UpdateInstructionReport : public JsonMember {
    public:
        UpdateInstructionReport();

        UpdateInstructionReport(const std::string& status,
            const std::string& errorCode = std::string(),
            const UpdateInstruction& instruction = UpdateInstruction());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const std::string& getErrorCode() const;
        void setErrorCode(const std::string& errorCode);

        const UpdateInstruction& getInstruction() const;
        void setInstruction(const UpdateInstruction& instruction);


    private:
        std::string status;
        std::string errorCode;
        UpdateInstruction instruction;
};

}

#endif // UPDATEINSTRUCTIONREPORT_H


