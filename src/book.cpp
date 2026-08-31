#include "book.hpp"
#include "order.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>



void Book::place_order(const Order& order){

    unsigned int remaining_quantity = order.quantity;


    switch (order.order_type) {
        case OrderType::BUY:
        {
            auto level = ask_map.begin();
            while (level != ask_map.end() && level->first <= order.price && remaining_quantity){
                auto entry = level->second.begin();
                while (entry != level->second.end() && remaining_quantity){
                    unsigned int fill = std::min(remaining_quantity, entry->quantity);
                    entry->quantity -= fill;
                    remaining_quantity -= fill;
                    entry ++;
                }
                level ++;
            }
            if (remaining_quantity)
            {
                OrderEntry entry;
                std::memcpy(entry.id, order.id, sizeof order.id);
                entry.quantity = remaining_quantity;
                bid_map[order.price].push_back(entry);
            }
            break;
        }

        case OrderType::SELL:
        {
            auto level = bid_map.begin();
            while (level != bid_map.end() && level->first >= order.price && remaining_quantity){
                auto entry = level->second.begin();
                while (entry != level->second.end() && remaining_quantity){
                    unsigned int fill = std::min(remaining_quantity, entry->quantity);
                    entry->quantity -= fill;
                    remaining_quantity -= fill;
                    entry ++;
                }
                level ++;
            }
            if (remaining_quantity)
            {
                OrderEntry entry;
                std::memcpy(entry.id, order.id, sizeof order.id);
                entry.quantity = remaining_quantity;
                ask_map[order.price].push_back(entry);
            }
            break;
        }

    }
}

void Book::show_asks(){
    for (const auto& level: ask_map){
        unsigned int quantities = 0;
        for (const auto& entry: level.second){
            quantities += entry.quantity;
        }
        std::cout << "Price: " << level.first << " Quantity: " << quantities <<  ";";
    }
}

void Book::show_bids(){
    for (const auto& level: bid_map){
        unsigned int quantities = 0;
        for (const auto& entry: level.second){
            quantities += entry.quantity;
        }
        std::cout << "Price: " << level.first << " Quantity: " << quantities <<  ";";
    }
}

void Book::show_book(){
   	std::cout << "BIDS: ";
	show_bids();
	std::cout << std::endl;

	std::cout << "ASKS: ";
	show_asks();
	std::cout << std::endl;
}
