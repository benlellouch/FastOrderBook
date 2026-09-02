#pragma once
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <string>

enum OrderType{
  BUY,
  SELL
};

struct Order
{
    boost::uuids::uuid id;
    std::string symbol;
    OrderType order_type;
    int quantity;
    float price;
};

class OrderCreator
{
    boost::uuids::random_generator uuid_generator;

    public:
        Order create_order(std::string symbol, OrderType order_type, int quantity, float price)
        {
            return Order{
                uuid_generator(),
                symbol,
                order_type,
                quantity,
                price
            };
        }
};
