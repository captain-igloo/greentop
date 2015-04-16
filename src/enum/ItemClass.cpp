#include "greentop/enum/ItemClass.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string ItemClass::UNKNOWN = "UNKNOWN";

ItemClass::ItemClass() {
    valid = false;
};

ItemClass::ItemClass(const std::string& v) {

    if (v != UNKNOWN) {
        throw std::invalid_argument("Invalid ItemClass: " + v);
    }

    value = v;
    valid = true;
}

bool ItemClass::operator<(const ItemClass& other) const {
    return value < other.value;
}

bool ItemClass::operator==(const ItemClass& other) const {
    return value == other.value;
}

}

