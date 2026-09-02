#include <iostream>
#include "order.hpp"
#include "book.hpp"



int main()
{

    Book order_book;
    OrderCreator order_creator;
	// order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 50, 3.5f));
	// order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 30, 2.5f));
	// order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 5, 1.5f));
	//

	order_book.place_order(order_creator.create_order("APPL", OrderType::SELL, 30, 6.2f));
	order_book.place_order(order_creator.create_order("APPL", OrderType::SELL, 20, 6.3f));
	order_book.place_order(order_creator.create_order("APPL", OrderType::SELL, 5, 7.2f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();

	order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 30, 6.3f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();

	order_book.place_order(order_creator.create_order("APPL", OrderType::SELL, 5, 6.3f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();

	order_book.place_order(order_creator.create_order("APPL", OrderType::SELL, 10, 6.3f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();


	order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 30, 6.3f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();


	order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 30, 6.3f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();

	order_book.place_order(order_creator.create_order("APPL", OrderType::SELL, 30, 6.2f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();


	order_book.place_order(order_creator.create_order("APPL", OrderType::BUY, 30, 7.2f));

	std::cout << "-----" <<std::endl ;
	order_book.show_book();

}
