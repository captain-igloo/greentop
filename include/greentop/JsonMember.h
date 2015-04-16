#ifndef JSONMEMBER_H
#define JSONMEMBER_H

#include <json/json.h>

#include <string>

namespace greentop {

class JsonMember {

    public:
        JsonMember();
        virtual bool isValid() const;
        virtual void fromJson(const Json::Value& json) = 0;
        virtual Json::Value toJson() const = 0;
        virtual std::string toString() const;
        virtual ~JsonMember();

    protected:
        bool valid;

    private:

};

}

std::ostream& operator<<(std::ostream& os, const greentop::JsonMember& jm);

std::istream& operator>>(std::istream& is, greentop::JsonMember& jm);

#endif // JSONMEMBER_H
