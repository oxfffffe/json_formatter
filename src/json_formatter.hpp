#ifndef JSON_FORMATTER_HPP
#define JSON_FORMATTER_HPP

#include <fstream> //string included
#include <cassert>

class Json_formatter
{
public:
  Json_formatter() = delete;
    Json_formatter(const char* filename);
    Json_formatter operator=(Json_formatter&) = delete;
    std::string format() const;
private:
    bool file_has_json_ext(std::string filename);
    std::string data;
    const char* tab = "  ";
};

#endif // JSON_FORMATTER_HPP
