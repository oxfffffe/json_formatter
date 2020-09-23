#include "json_formatter.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
<<<<<<< HEAD
 if (argc != 2) {
   throw std::invalid_argument
   ("Invalid count of arguments, please add ONE json file as first parameter.");
 }
 Json_formatter formatter(argv[1]);
  std::cout << formatter.format() << std::endl;
=======
  if (argc != 2) {
    throw std::invalid_argument
    ("Invalid count of arguments, please add ONE json file as first parameter.");
  }
  Json_formatter formatter(argv[1]);
  std::string formatted = formatter.format();
  std::cout << formatted << std::endl;
>>>>>>> eec0e41897978819419a53e4be56d97b0c3b04a9
}
