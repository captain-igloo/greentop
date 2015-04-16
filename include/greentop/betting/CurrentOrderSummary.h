#ifndef CURRENTORDERSUMMARY_H
#define CURRENTORDERSUMMARY_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/betting/PriceSize.h"
#include "greentop/enum/OrderStatus.h"
#include "greentop/enum/OrderType.h"
#include "greentop/enum/PersistenceType.h"
#include "greentop/enum/Side.h"

namespace greentop {

class CurrentOrderSummary : public JsonMember {
    public:
        CurrentOrderSummary();

        CurrentOrderSummary(const std::string& betId,
            const std::string& marketId,
            const uint64_t selectionId,
            const double handicap,
            const PriceSize& priceSize,
            const double bspLiability,
            const Side& side,
            const OrderStatus& status,
            const PersistenceType& persistenceType,
            const OrderType& orderType,
            const std::tm& placedDate,
            const std::tm& matchedDate,
            const double averagePriceMatched = -1,
            const double sizeMatched = -1,
            const double sizeRemaining = -1,
            const double sizeLapsed = -1,
            const double sizeCancelled = -1,
            const double sizeVoided = -1,
            const std::string& regulatorAuthCode = std::string(),
            const std::string& regulatorCode = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const PriceSize& getPriceSize() const;
        void setPriceSize(const PriceSize& priceSize);

        const double getBspLiability() const;
        void setBspLiability(const double bspLiability);

        const Side& getSide() const;
        void setSide(const Side& side);

        const OrderStatus& getStatus() const;
        void setStatus(const OrderStatus& status);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const std::tm& getMatchedDate() const;
        void setMatchedDate(const std::tm& matchedDate);

        const double getAveragePriceMatched() const;
        void setAveragePriceMatched(const double averagePriceMatched);

        const double getSizeMatched() const;
        void setSizeMatched(const double sizeMatched);

        const double getSizeRemaining() const;
        void setSizeRemaining(const double sizeRemaining);

        const double getSizeLapsed() const;
        void setSizeLapsed(const double sizeLapsed);

        const double getSizeCancelled() const;
        void setSizeCancelled(const double sizeCancelled);

        const double getSizeVoided() const;
        void setSizeVoided(const double sizeVoided);

        const std::string& getRegulatorAuthCode() const;
        void setRegulatorAuthCode(const std::string& regulatorAuthCode);

        const std::string& getRegulatorCode() const;
        void setRegulatorCode(const std::string& regulatorCode);


    private:
        std::string betId;
        std::string marketId;
        uint64_t selectionId;
        double handicap;
        PriceSize priceSize;
        double bspLiability;
        Side side;
        OrderStatus status;
        PersistenceType persistenceType;
        OrderType orderType;
        std::tm placedDate;
        std::tm matchedDate;
        double averagePriceMatched;
        double sizeMatched;
        double sizeRemaining;
        double sizeLapsed;
        double sizeCancelled;
        double sizeVoided;
        std::string regulatorAuthCode;
        std::string regulatorCode;
};

}

#endif // CURRENTORDERSUMMARY_H


