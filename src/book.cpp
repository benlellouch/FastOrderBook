#include "book.hpp"
#include "order.hpp"
#include <iostream>

void Book::place_order(const Order& order){

    unsigned int remaining_quantity = order.quantity;

    switch (order.order_type) {
        case OrderType::BUY:
            for (auto level = ask_map.lower_bound(order.price); level != ask_map.end(); ++level)
            {
                unsigned int temp = remaining_quantity > level->second ? remaining_quantity - level-> second : 0;
                level->second = remaining_quantity > level->second ? 0 :  level-> second - remaining_quantity;
                remaining_quantity = temp;
                if (!remaining_quantity)
                {
                    break;
                }
            }
            bid_map[order.price] += remaining_quantity;
            break;
        case OrderType::SELL:
            for (auto level = bid_map.lower_bound(order.price); level != bid_map.end(); ++level)
            {
                unsigned int temp = remaining_quantity > level->second ? remaining_quantity - level-> second : 0;
                level->second = remaining_quantity > level->second ? 0 :  level-> second - remaining_quantity;
                remaining_quantity = temp;
                if (!remaining_quantity)
                {
                    break;
                }
            }
            ask_map[order.price] += remaining_quantity;
            break;
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

unsigned int Book::get_quantity_at_level(float price){
    if (bid_map.contains(price)){
        std::cout << "BID ";
        return bid_map[price];
    }
    if (ask_map.contains(price)){
        std::cout << "ASK ";
        return ask_map[price];
    }
    return 0;
}
