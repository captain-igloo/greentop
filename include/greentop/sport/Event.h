/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_EVENT_H
#define SPORT_EVENT_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {
namespace sport {
/**
 * Event
 */
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
        /**
         * The unique id for the event
         */
        std::string id;
        /**
         * The name of the event
         */
        std::string name;
        /**
         * countryCode
         */
        std::string countryCode;
        /**
         * timezone
         */
        std::string timezone;
        /**
         * venue
         */
        std::string venue;
        /**
         * openDate
         */
        std::tm openDate;
};

}
}

#endif // SPORT_EVENT_H
