#include "order.hpp"
#include <uuid/uuid.h>
#include <iostream>

Order create_order(std::string symbol, OrderType order_type, int quantity, float price)
{
    Order order;
    uuid_generate(order.id);
    order.symbol = symbol;
    order.order_type = order_type;
    order.quantity = quantity;
    order.price = price;
    return order;
}
