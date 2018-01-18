/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef KEYLINESELECTION_H
#define KEYLINESELECTION_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
/**
 * Description of a markets key line selection, comprising the selectionId and handicap of the team
 * it is applied to.
 */
class KeyLineSelection : public JsonMember {
    public:
        KeyLineSelection();

        KeyLineSelection(const Optional<int64_t>& selectionId,
            const Optional<double>& handicap);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getSelectionId() const;
        void setSelectionId(const Optional<int64_t>& selectionId);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);


    private:
        /**
         * Selection ID of the runner in the key line handicap.
         */
        Optional<int64_t> selectionId;
        /**
         * Handicap value of the key line.
         */
        Optional<double> handicap;
};

}

#endif // KEYLINESELECTION_H
