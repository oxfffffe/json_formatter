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
  for (uint64_t i = 0; i < data.size(); i++) {
    switch (data[i]) {
      case(int)'{': {
        formatted.push_back('{');
        formatted.push_back('\n');
        ++tabs;
        for (uint8_t i = 0; i < tabs; i++) {
          formatted.append(tab);
        }
        break;
      }
      case(int)'}': {
        formatted.push_back('\n');
        for (uint8_t i = 0; i < tabs - 1; i++) {
          formatted.append(tab);
        }
        --tabs;
        formatted.push_back('}');
        break;
      }
      case(int)'[': {
        formatted.push_back('[');
        formatted.push_back('\n');
        ++tabs;
        for (uint8_t i = 0; i < tabs; i++) {
          formatted.append(tab);
        }
        break;
      }
      case(int)']': {
        formatted.push_back('\n');
        for (uint8_t i = 0; i < tabs - 1; i++) {
          formatted.append(tab);
        }
        --tabs;
        formatted.push_back(']');
        break;
      }
      case(int)',': {
        formatted.push_back(',');
        formatted.push_back('\n');
        for (uint8_t i = 0; i < tabs; i++) {
          formatted.append(tab);
        }
        break;
      }
      case(int)':': {
        formatted.push_back(':');
        formatted.push_back(' ');
        break;
      }
      default: {
        formatted.push_back(data[i]); break;
      }
    }
  }
  return formatted;
}

