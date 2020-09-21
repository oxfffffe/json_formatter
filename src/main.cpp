#include "json_formatter.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    throw std::invalid_argument
    ("Invalid count of arguments, please add ONE json file as first parameter.");
  }
  Json_formatter formatter(argv[1]);
  std::string formatted = formatter.format();
  std::cout << formatted << std::endl;
}
