#include "json_formatter.hpp"

Json_formatter::Json_formatter(const char* filename) {
  assert(file_has_json_ext(filename) && "You specified non-JSON file, please try again.");
  std::ifstream file_stream(filename);
  std::string content((std::istreambuf_iterator<char>(file_stream))
                     , std::istreambuf_iterator<char>());
  data = content;
}

bool Json_formatter::file_has_json_ext(std::string filename)
{
  std::string json_ext = ".json";
  return filename.substr(filename.size() - json_ext.size()) == json_ext;
}

std::string Json_formatter::format() const {
  std::string formatted;
  uint8_t tabs = 0;
  bool is_first_quote = true;
  bool is_first_digit = true;
  std::string end_of_color("\e[0m");
  std::string gray("\e[38;5;240m");
  std::string mint("\e[38;5;72m");
  std::string purple("\e[38;5;176m");
  for (uint64_t i = 0; i < data.size(); i++) {
    switch (data[i]) {
      case static_cast<int>('{'): {
        formatted.append(gray);
        formatted.push_back('{');
        formatted.append(end_of_color);
        formatted.push_back('\n');
        ++tabs;
        for (uint8_t i = 0; i < tabs; i++) {
          formatted.append(tab);
        }
        break;
      }
      case static_cast<int>('}'): {
        formatted.push_back('\n');
        for (uint8_t i = 0; i < tabs - 1; i++) {
          formatted.append(tab);
        }
        --tabs;
        formatted.append(gray);
        formatted.push_back('}');
        formatted.append(end_of_color);
        break;
      }
      case static_cast<int>('['): {
        formatted.append(gray);
        formatted.push_back('[');
        formatted.append(end_of_color);
        formatted.push_back('\n');
        ++tabs;
        for (uint8_t i = 0; i < tabs; i++) {
          formatted.append(tab);
        }
        break;
      }
      case static_cast<int>(']'): {
        formatted.push_back('\n');
        for (uint8_t i = 0; i < tabs - 1; i++) {
          formatted.append(tab);
        }
        --tabs;
        formatted.append(gray);
        formatted.push_back(']');
        formatted.append(end_of_color);
        break;
      }
      case static_cast<int>(','): {
        formatted.push_back(',');
        formatted.push_back('\n');
        for (uint8_t i = 0; i < tabs; i++) {
          formatted.append(tab);
        }
        break;
      }
      case static_cast<int>(':'): {
        formatted.push_back(':');
        formatted.push_back(' ');
        break;
      }
      case static_cast<int>('"'): {
        if (is_first_quote) {
          formatted.append(mint + "\"");
        } else {
          formatted.append("\"");
          formatted.append(end_of_color);
        }
        is_first_quote = !is_first_quote;
        break;
      }
      case static_cast<int>('0'):
      case static_cast<int>('1'):
      case static_cast<int>('2'):
      case static_cast<int>('3'):
      case static_cast<int>('4'):
      case static_cast<int>('5'):
      case static_cast<int>('6'):
      case static_cast<int>('7'):
      case static_cast<int>('8'):
      case static_cast<int>('9'): {
        if (is_first_quote) {
          if (is_first_digit) {
            formatted.append(purple);
            formatted.push_back(data[i]);
          } else {
            formatted.append(end_of_color);
            is_first_digit = !is_first_digit;
          }
          break;
        }
      }
      default: {
        formatted.push_back(data[i]);
        break;
      }
    }
  }
  return formatted;
}

