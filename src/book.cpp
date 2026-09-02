#include "book.hpp"
#include "order.hpp"
#include <iostream>



void Book::place_order(const Order& order){

    unsigned int remaining_quantity = order.quantity;

    switch (order.order_type) {
        case OrderType::BUY:
        {
            match_orders_(ask_map, order, remaining_quantity);
            if (remaining_quantity)
                push_entry_(bid_map, order, remaining_quantity);

            break;
        }

        case OrderType::SELL:
        {
            match_orders_(bid_map, order, remaining_quantity);
            if (remaining_quantity)
                push_entry_(ask_map, order, remaining_quantity);

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
