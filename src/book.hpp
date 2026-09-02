#pragma once
#include "order.hpp"
#include <functional>
#include <map>
#include <list>
#include <boost/uuid/uuid.hpp>
struct OrderEntry{
  boost::uuids::uuid id;
  unsigned int quantity;
};

template<typename PriceOrder>
using RestingMap = std::map<float, std::list<OrderEntry>, PriceOrder>;
using BidMap = RestingMap<std::greater<float>>;
using AskMap = RestingMap<std::less<float>>;


class Book{
    BidMap bid_map;
    AskMap ask_map;
    std::map<boost::uuids::uuid ,OrderEntry*> order_map;

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
        void push_entry_(RestingMap<PriceOrder>& resting_map, const Order& order, unsigned int quantity){
            OrderEntry entry {order.id, quantity};
            resting_map[order.price].push_back(entry);
            order_map[order.id] = &entry;
        }

};
