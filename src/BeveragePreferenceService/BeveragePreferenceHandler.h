#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCE_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCE_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void GetBeverage(std::string& _return, const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return, const BeverageType::type btype ) {
     // Your implementation goes here
     printf("GetBeverage\n");

    // randomly select a beverage
    std::vector<std::string> beverages;
    if (btype == BeverageType::type::HOT) {
        beverages = {"cappuccino", "latte", "espresso"};
    } else {
        beverages = {"lemonade", "ice tea", "soda"};
    }
    
    _return = beverages[rand()%3];
    
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H