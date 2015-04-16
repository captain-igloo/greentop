#include "greentop/enum/PriceData.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string PriceData::SP_AVAILABLE = "SP_AVAILABLE";
const std::string PriceData::SP_TRADED = "SP_TRADED";
const std::string PriceData::EX_BEST_OFFERS = "EX_BEST_OFFERS";
const std::string PriceData::EX_ALL_OFFERS = "EX_ALL_OFFERS";
const std::string PriceData::EX_TRADED = "EX_TRADED";

PriceData::PriceData() {
    valid = false;
};

PriceData::PriceData(const std::string& v) {

    if (v != SP_AVAILABLE &&
        v != SP_TRADED &&
        v != EX_BEST_OFFERS &&
        v != EX_ALL_OFFERS &&
        v != EX_TRADED) {
        throw std::invalid_argument("Invalid PriceData: " + v);
    }

    value = v;
    valid = true;
}

bool PriceData::operator<(const PriceData& other) const {
    return value < other.value;
}

bool PriceData::operator==(const PriceData& other) const {
    return value == other.value;
}

}

