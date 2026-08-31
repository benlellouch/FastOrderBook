#pragma once
#include <string>
#include <uuid/uuid.h>

enum OrderType{
  BUY,
  SELL
};

struct Order{
    uuid_t id;
    std::string symbol;
    OrderType order_type;
    int quantity;
    float price;
};

Order create_order(std::string symbol, OrderType order_type, int quantity, float price);
