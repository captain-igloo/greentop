/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_KEYLINESELECTION_H
#define STREAM_KEYLINESELECTION_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace stream {        

class KeyLineSelection : public JsonMember {
    public:

        KeyLineSelection(const Optional<int64_t>& id = Optional<int64_t>(),
            const Optional<double>& hc = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getId() const;
        void setId(const Optional<int64_t>& id);

        const Optional<double>& getHc() const;
        void setHc(const Optional<double>& hc);


    private:

        Optional<int64_t> id;

        Optional<double> hc;
};

}
}

#endif // STREAM_KEYLINESELECTION_H
