#include "OrderBeverageHandler.h"
#include "../gen-cpp/WeatherService.h"
#include "../gen-cpp/BeveragePreferenceService.h"
#include "../ClientPool.h"
#include "../utils.h"
#include "../logger.h"

namespace vending_machine {

void OrderBeverageHandler::placeOrder(std::string& _return, const int64_t city) {
  // 1) call weather-service
  auto weatherClient = ClientPool<WeatherServiceClient>::getClient("weather-service");
  auto wtype         = weatherClient->GetWeather(city);
  ClientPool<WeatherServiceClient>::returnClient("weather-service", weatherClient);

  // 2) determine beverage-type
  BeverageType::type btype = (wtype == WeatherType::type::WARM)
                             ? BeverageType::type::HOT
                             : BeverageType::type::COLD;

  // 3) call beverage-preference-service
  auto bevClient = ClientPool<BeveragePreferenceServiceClient>::getClient("beverage-preference-service");
  std::string bevName;
  bevClient->getBeverage(bevName, btype);
  ClientPool<BeveragePreferenceServiceClient>::returnClient("beverage-preference-service", bevClient);

  // 4) return the beverage name to nginx
  _return = bevName;
}

} // namespace vending_machine
