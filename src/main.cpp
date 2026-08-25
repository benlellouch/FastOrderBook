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

	order_book.place_order(Order({"APPL", OrderType::BUY, 50, 3.5f}));
	order_book.place_order(Order({"APPL", OrderType::BUY, 30, 2.5f}));
	order_book.place_order(Order({"APPL", OrderType::BUY, 5, 1.5f}));
	// order_book.place_order(new_order);

	order_book.place_order(Order({"APPL", OrderType::SELL, 30, 6.2f}));
	order_book.place_order(Order({"APPL", OrderType::SELL, 20, 6.3f}));
	order_book.place_order(Order({"APPL", OrderType::SELL, 5, 7.2f}));

	std::cout << "-----" <<std::endl ;

	std::cout << "BIDS: ";
	order_book.show_bids();
	std::cout << std::endl;


	std::cout << "ASKS: ";
	order_book.show_asks();
	std::cout << std::endl;

	order_book.place_order(Order({"APPL", OrderType::BUY, 30, 6.3f}));

	std::cout << "-----" <<std::endl ;


	std::cout << "BIDS: ";
	order_book.show_bids();
	std::cout << std::endl;


	std::cout << "ASKS: ";
	order_book.show_asks();
	std::cout << std::endl;

	order_book.place_order(Order({"APPL", OrderType::SELL, 5, 6.3f}));

	std::cout << "-----" <<std::endl ;


	std::cout << "BIDS: ";
	order_book.show_bids();
	std::cout << std::endl;


	std::cout << "ASKS: ";
	order_book.show_asks();
	std::cout << std::endl;

	order_book.place_order(Order({"APPL", OrderType::SELL, 10, 6.3f}));

	std::cout << "-----" <<std::endl ;

	std::cout << "BIDS: ";
	order_book.show_bids();
	std::cout << std::endl;


	std::cout << "ASKS: ";
	order_book.show_asks();
	std::cout << std::endl;



}
