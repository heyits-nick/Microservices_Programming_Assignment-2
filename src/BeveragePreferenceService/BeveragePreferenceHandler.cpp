#include "BeveragePreferenceHandler.h"
#include <random>
#include <vector>

namespace vending_machine {

void BeveragePreferenceHandler::getBeverage(std::string& _return, const BeverageType::type btype)  {
  // Hot drinks vs cold drinks
  std::vector<std::string> options;
  if (btype == BeverageType::HOT) {
    options = { "cappuccino", "latte", "espresso" };
  } else {
    options = { "lemonade", "ice tea", "soda" };
  }

  // Random pick
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, options.size() - 1);
  _return = options[dis(gen)];
}

} // namespace vending_machine
