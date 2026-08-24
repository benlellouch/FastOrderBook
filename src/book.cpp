#include "book.hpp"
#include "order.hpp"

void Book::place_order(Order& order){
    switch (order.order_type) {
        case OrderType::BUY:
            bid_map[order.price] += order.quantity;
            break;
        case OrderType::SELL:
            ask_map[order.price] += order.quantity;
            break;
    }
}

unsigned int Book::get_quantity_at_level(float price){
    if (bid_map.contains(price)){
        return bid_map[price];
    }
    return 0;
}
