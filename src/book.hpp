#pragma once
#include "order.hpp"
#include <functional>
#include <map>
#include <list>
#include <uuid/uuid.h>

struct OrderEntry{
  uuid_t id;
  unsigned int quantity;
};

class Book{
    std::map<float, std::list<OrderEntry>,std::greater<float>> bid_map;
    std::map<float, std::list<OrderEntry>> ask_map;

    public:
        void place_order(const Order& order);
        void show_asks();
        void show_bids();
        void show_book();

};
