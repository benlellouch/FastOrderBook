#include <iostream>
#include "order.hpp"
#include "book.hpp"



int main()
{

    Book order_book;

	Order new_order {"APPL", OrderType::BUY, 5, 3.5f};

	std::cout << "NEW ORDER ----  " << std::endl;
	std::cout << "Symbol: " << new_order.symbol << std::endl;
	std::cout << "Order Type: " << new_order.order_type << std::endl;
	std::cout << "Quantity: " << new_order.quantity << std::endl;
	std::cout << "Price: " << new_order.price << std::endl;

	order_book.place_order(new_order);
	order_book.place_order(new_order);

	std::cout << "Quantity at Level 3.5: " << order_book.get_quantity_at_level(3.4f) << std::endl;
}
