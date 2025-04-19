cmake_minimum_required(VERSION 3.5)
project(BeveragePreferenceService)

# Point at the generated C++ stubs
set(THRIFT_GEN_CPP_DIR "${CMAKE_SOURCE_DIR}/gen-cpp")
set(THRIFT_LIB thrift)

add_executable(
  BeveragePreferenceService
  BeveragePreferenceServer.cpp
  BeveragePreferenceHandler.cpp
  ${THRIFT_GEN_CPP_DIR}/BeveragePreferenceService.cpp
  ${THRIFT_GEN_CPP_DIR}/vending_machine_types.cpp
)

# in case you need includes
target_include_directories(BeveragePreferenceService PRIVATE
  ${THRIFT_GEN_CPP_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  BeveragePreferenceService
  nlohmann_json::nlohmann_json
  ${THRIFT_LIB}
  ${CMAKE_THREAD_LIBS_INIT}
  ${Boost_LIBRARIES}
  Boost::log
  Boost::log_setup
)

install(TARGETS BeveragePreferenceService DESTINATION /usr/local/bin)
