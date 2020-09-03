#ifndef JSON_FORMATTER_HPP
#define JSON_FORMATTER_HPP

#include <fstream>
#include <string>
#include <streambuf>

class Json_formatter
{
public:
    Json_formatter(std::string filename);
    std::string format();
private:
    std::string file_content;
};

#endif // JSON_FORMATTER_HPP
