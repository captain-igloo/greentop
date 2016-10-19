/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEINSTRUCTION_H
#define UPDATEINSTRUCTION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/sport/enum/PersistenceType.h"

namespace greentop {

class UpdateInstruction : public JsonMember {
    public:
        UpdateInstruction();

        UpdateInstruction(const std::string& betId,
            const PersistenceType& newPersistenceType);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const PersistenceType& getNewPersistenceType() const;
        void setNewPersistenceType(const PersistenceType& newPersistenceType);


    private:
        std::string betId;
        PersistenceType newPersistenceType;
};

}

#endif // UPDATEINSTRUCTION_H


