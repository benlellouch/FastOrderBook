#pragma once
#include "order.hpp"
#include <functional>
#include <map>

class Book{
    std::map<float, unsigned int,std::greater<float>> bid_map;
    std::map<float, unsigned int> ask_map;

    public:
        void place_order(const Order& order);
        void show_asks();
        void show_bids();
        unsigned int get_quantity_at_level(float price);

};
