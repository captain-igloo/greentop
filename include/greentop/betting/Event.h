/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EVENT_H
#define EVENT_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {

class Event : public JsonMember {
    public:

        Event(const std::string& id = std::string(),
            const std::string& name = std::string(),
            const std::string& countryCode = std::string(),
            const std::string& timezone = std::string(),
            const std::string& venue = std::string(),
            const std::tm& openDate = std::tm());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getId() const;
        void setId(const std::string& id);

        const std::string& getName() const;
        void setName(const std::string& name);

        const std::string& getCountryCode() const;
        void setCountryCode(const std::string& countryCode);

        const std::string& getTimezone() const;
        void setTimezone(const std::string& timezone);

        const std::string& getVenue() const;
        void setVenue(const std::string& venue);

        const std::tm& getOpenDate() const;
        void setOpenDate(const std::tm& openDate);


    private:
        std::string id;
        std::string name;
        std::string countryCode;
        std::string timezone;
        std::string venue;
        std::tm openDate;
};

}

#endif // EVENT_H


