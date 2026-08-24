#pragma once
#include <string>

enum OrderType{
  BUY,
  SELL
};

struct Order{
    std::string symbol;
    OrderType order_type;
    int quantity;
    float price;
};
