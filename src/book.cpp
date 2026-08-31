#include "book.hpp"
#include "order.hpp"
#include <iostream>


void Book::place_order(const Order& order){

    unsigned int remaining_quantity = order.quantity;

    switch (order.order_type) {
        case OrderType::BUY:
        {
            auto level = ask_map.begin();
            while (level != ask_map.end() && level->first <= order.price && remaining_quantity){
                unsigned int temp = remaining_quantity > level->second ? remaining_quantity - level-> second : 0;
                level->second = remaining_quantity > level->second ? 0 :  level-> second - remaining_quantity;
                remaining_quantity = temp;
                level ++;
            }
            if (remaining_quantity) bid_map[order.price] += remaining_quantity;
            break;
        }

        case OrderType::SELL:
        {
            auto level = bid_map.begin();
            while (level != bid_map.end() && level->first >= order.price && remaining_quantity){
                unsigned int temp = remaining_quantity > level->second ? remaining_quantity - level-> second : 0;
                level->second = remaining_quantity > level->second ? 0 :  level-> second - remaining_quantity;
                remaining_quantity = temp;
                level ++;
            }
            if (remaining_quantity) ask_map[order.price] += remaining_quantity;
            break;
        }

    }
}

void Book::show_asks(){
    for (const auto& level: ask_map){
        std::cout << "Price: " << level.first << ", Quantity: " << level.second << ";";
    }
}

void Book::show_bids(){
    for (const auto& level: bid_map){
        std::cout << "Price: " << level.first << ", Quantity: " << level.second << ";";
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
