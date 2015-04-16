#ifndef LIMITORDER_H
#define LIMITORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/enum/PersistenceType.h"

namespace greentop {

class LimitOrder : public JsonMember {
    public:
        LimitOrder();

        LimitOrder(const double size,
            const double price,
            const PersistenceType& persistenceType);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getSize() const;
        void setSize(const double size);

        const double getPrice() const;
        void setPrice(const double price);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);


    private:
        double size;
        double price;
        PersistenceType persistenceType;
};

}

#endif // LIMITORDER_H


