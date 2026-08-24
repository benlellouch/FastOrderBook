#pragma once
#include "order.hpp"
#include <map>

class Book{
    std::map<float, unsigned int> bid_map;
    std::map<float, unsigned int> ask_map;

    public:
        void place_order(Order& order);
        unsigned int get_quantity_at_level(float price);
};
