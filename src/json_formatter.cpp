#include "json_formatter.hpp"
#include <iostream>

Json_formatter::Json_formatter(const char* filename) {
  assert(file_has_json_ext(filename) && "You specified non-JSON file, please try again.");
  std::ifstream file_stream(filename);
<<<<<<< HEAD
  std::string content((std::istreambuf_iterator<char>(file_stream)),
                       std::istreambuf_iterator<char>());
  data = content;
}

bool Json_formatter::file_has_json_ext(std::string filename) {
=======
  std::string content((std::istreambuf_iterator<char>(file_stream))
                     , std::istreambuf_iterator<char>());
  data = content;
}

bool Json_formatter::file_has_json_ext(std::string filename)
{
>>>>>>> eec0e41897978819419a53e4be56d97b0c3b04a9
  std::string json_ext = ".json";
  return filename.substr(filename.size() - json_ext.size()) == json_ext;
}

<<<<<<< HEAD
void Json_formatter::append_brace(char brace, std::string& formatted, uint8_t& tabs, const std::string& color) const {
  if (is_inside_quotes) {
    formatted.push_back(brace);
    return;
  }
  if (brace == '}' ||
      brace == ']') {
    formatted.push_back('\n');
    for (uint8_t i = 0; i < tabs - 1; i++) {
      formatted.append(tab);
    }
    --tabs;
    formatted.append(color);
    formatted.push_back(brace);
    formatted.append(end_of_color);
  }
  if (brace == '{' ||
      brace == '[') {
    formatted.append(color);
    formatted.push_back('{');
    formatted.append(end_of_color);
    formatted.push_back('\n');
    ++tabs;
    for (uint8_t i = 0; i < tabs; i++) {
      formatted.append(tab);
    }
  }
}

void Json_formatter::append_comma(std::string& text, uint8_t& tabs) const {
  text.push_back(',');
  if (!is_inside_quotes) {
    text.push_back('\n');
    for (uint8_t i = 0; i < tabs; i++) {
      text.append(tab);
    }
  }
}

void Json_formatter::append_semicolon(std::string& text) const {
  text.push_back(':');
  if (!is_inside_quotes) {
    text.push_back(' ');
  }
}

void Json_formatter::append_quote(std::string& text) const {
  if (!is_inside_quotes) {
    text.append(mint + "\"");
  } else {
    text.append("\"");
    text.append(end_of_color);
  }
  is_inside_quotes = !is_inside_quotes;
}

void Json_formatter::append_digit(std::string& text,  char digit) const {
  if (!is_inside_quotes) {
    text.append(purple + digit);
    text.append(end_of_color);
  } else {
    text.push_back(digit);
  }
}

std::string Json_formatter::format() const {
  std::string formatted;
  uint8_t tabs = 0;
  for (uint64_t i = 0; i < data.size(); i++) {
    switch (data[i]) {
      case '{':
        append_brace('{', formatted, tabs, grey);
        break;

      case '}':
        append_brace('}', formatted, tabs, grey);
        break;

      case '[':
        append_brace('[', formatted, tabs, grey);
        break;

      case ']':
        append_brace(']', formatted, tabs, grey);
        break;

      case ',':
        append_comma(formatted, tabs);
        break;

      case ':':
        append_semicolon(formatted);
        break;

      case '"':
        append_quote(formatted);
        break;

      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        append_digit(formatted, data[i]);
        break;

      default:
        formatted.push_back(data[i]);
        break;
    }
  }
  return formatted;
}

=======
std::string Json_formatter::format() const {
  std::string formatted;
  uint8_t tabs = 0;
  bool is_first_quote = true;
  bool is_first_digit = true;
#if defined (__linux__)
  std::string end_of_color("\e[0m");
  std::string grey("\e[38;5;240m");
  std::string mint("\e[38;5;72m");
  std::string purple("\e[38;5;176m");
#else
  std::string end_of_color("");
  std::string grey("");
  std::string mint("");
  std::string purple("");
#endif
  for (uint64_t i = 0; i < data.size(); i++) {
    switch (data[i]) {
      case static_cast<int>('{'): {
        formatted.append(grey);
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
        formatted.append(grey);
        formatted.push_back('}');
        formatted.append(end_of_color);
        break;
      }
      case static_cast<int>('['): {
        formatted.append(grey);
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
        formatted.append(grey);
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

>>>>>>> eec0e41897978819419a53e4be56d97b0c3b04a9
