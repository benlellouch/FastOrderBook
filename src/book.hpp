#pragma once
#include "order.hpp"
#include <cstring>
#include <functional>
#include <map>
#include <list>
#include <uuid/uuid.h>

struct OrderEntry{
  uuid_t id;
  unsigned int quantity;
};

template<typename PriceOrder>
using RestingMap = std::map<float, std::list<OrderEntry>, PriceOrder>;
using BidMap = RestingMap<std::greater<float>>;
using AskMap = RestingMap<std::less<float>>;


class Book{
    BidMap bid_map;
    AskMap ask_map;

    public:
        void place_order(const Order& order);
        void show_asks();
        void show_bids();
        void show_book();
    private:
        template <typename PriceOrder>
        void match_orders_(RestingMap<PriceOrder>& resting_map, const Order& order, unsigned int& remaining_quantity){
            auto comp = resting_map.key_comp();
            auto level = resting_map.begin();
            while (level != resting_map.end() && !comp(order.price, level->first) && remaining_quantity){
                auto entry = level->second.begin();
                while (entry != level->second.end() && remaining_quantity){
                    unsigned int fill = std::min(remaining_quantity, entry->quantity);
                    entry->quantity -= fill;
                    remaining_quantity -= fill;
                    entry ++;
                }
                level ++;
            }
        }

        template <typename PriceOrder>
        void push_entry_(RestingMap<PriceOrder>& resting_map, const Order& order, int quantity){
            OrderEntry entry;
            std::memcpy(entry.id, order.id, sizeof order.id);
            entry.quantity = quantity;
            resting_map[order.price].push_back(entry);
        }

};
