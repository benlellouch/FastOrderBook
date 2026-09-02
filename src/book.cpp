#include "book.hpp"
#include "order.hpp"
#include <algorithm>
#include <iostream>



void Book::place_order(const Order& order)
{

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

template <typename PriceOrder>
void Book::match_orders_(RestingMap<PriceOrder>& resting_map, const Order& order, unsigned int& remaining_quantity)
{
    PriceOrder comp = resting_map.key_comp();
    auto level = resting_map.begin();
    while (level != resting_map.end() && !comp(order.price, level->first) && remaining_quantity){
        auto entry = level->second.begin();
        while (entry != level->second.end() && remaining_quantity){
            unsigned int fill = std::min(remaining_quantity, entry->quantity);
            entry->quantity -= fill;
            remaining_quantity -= fill;

            if (!entry->quantity)
            {
                order_map.erase(entry->id);
                entry = level->second.erase(entry);
            }
            else{
                entry ++;
            }
        }

        if(!level->second.size())
        {
            level = resting_map.erase(level);
        }
        else{
            level ++;
        }
    }
}

template <typename PriceOrder>
void Book::push_entry_(RestingMap<PriceOrder>& resting_map, const Order& order, unsigned int quantity)
{
    OrderEntry entry {order.id, quantity};
    resting_map[order.price].push_back(entry);
    order_map[order.id] = &entry;
}

void Book::show_asks()
{
    for (const auto& level: ask_map)
    {
        unsigned int quantities = 0;
        for (const auto& entry: level.second)
        {
            quantities += entry.quantity;
        }
        std::cout << "Price: " << level.first << " Quantity: " << quantities <<  ";";
    }
}

void Book::show_bids(){
    for (const auto& level: bid_map)
    {
        unsigned int quantities = 0;
        for (const auto& entry: level.second)
        {
            quantities += entry.quantity;
        }
        std::cout << "Price: " << level.first << " Quantity: " << quantities <<  ";";
    }
}

void Book::show_book()
{
   	std::cout << "BIDS: ";
	show_bids();
	std::cout << std::endl;

	std::cout << "ASKS: ";
	show_asks();
	std::cout << std::endl;
}
