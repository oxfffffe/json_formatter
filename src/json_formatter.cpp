#include "json_formatter.hpp"

Json_formatter::Json_formatter(std::string filename) {
    std::ifstream file_stream(filename);
    std::string content((std::istreambuf_iterator<char>(file_stream))
                       , std::istreambuf_iterator<char>());
    file_content = content;
}

std::string Json_formatter::format() {
    std::string formatted;
    uint8_t count_of_tabs = 0;
    const char* tab = "  ";
    for (uint64_t i = 0; i < file_content.size(); i++) {
        if (file_content[i] == '{') {                   //`{` case
            formatted.push_back('{');
            formatted.push_back('\n');
            ++count_of_tabs;
            for (uint8_t i = 0; i < count_of_tabs; i++) {
                formatted.append(tab);
            }
        } else if (file_content[i] == '}') {            //`}` case
            formatted.push_back('\n');
            for (uint8_t i = 0; i < count_of_tabs - 1; i++) {
                formatted.append(tab);
            }
          --count_of_tabs;
            formatted.push_back('}');
        } else if (file_content[i] == '[') {            //`[` case
            formatted.push_back('[');
            formatted.push_back('\n');
          ++count_of_tabs;
            for (uint8_t i = 0; i < count_of_tabs; i++) {
                formatted.append(tab);
            }
        } else if (file_content[i] == ']') {            //`]` case
            formatted.push_back('\n');
            for (uint8_t i = 0; i < count_of_tabs - 1; i++) {
                formatted.append(tab);
            }
          --count_of_tabs;
            formatted.push_back(']');
        } else if (file_content[i] == ',') {           //`,` case
            formatted.push_back(',');
            formatted.push_back('\n');
            for (uint8_t i = 0; i < count_of_tabs; i++) {
                formatted.append(tab);
            }
        } else {
            formatted.push_back(file_content[i]);
        }
    }
    return formatted;
}
