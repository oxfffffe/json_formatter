#include "json_formatter.hpp"

Json_formatter::Json_formatter(const char* filename) {
  assert(file_has_json_ext(filename) && "You specified non-JSON file, please try again.");
  std::ifstream stream(filename);
  std::string content((std::istreambuf_iterator<char>(stream)),
                       std::istreambuf_iterator<char>());
  data = content;
}

bool Json_formatter::file_has_json_ext(std::string filename) {
  std::string json_ext = ".json";
  return filename.substr(filename.size() - json_ext.size()) == json_ext;
}

void Json_formatter::append_tabs() const noexcept {
  for (uint8_t i = 0; i < tabs; i++) {
    json.append(tab);
  }
}

void Json_formatter::append_brace(char brace, const std::string& color) const noexcept {
  if (quoted) {
    json.push_back(brace);
    return;
  }
  if (brace == '}' || brace == ']') {
    --tabs;
    json.push_back('\n');
    append_tabs();
  }

  json.append(color);
  json.push_back(brace);
  json.append(end_of_color);

  if (brace == '{' || brace == '[') {
    ++tabs;
    json.push_back('\n');
    append_tabs();
    block = true;
  }
}

void Json_formatter::append_comma() const noexcept {
  json.push_back(',');
  if (!quoted) {
    json.push_back('\n');
    append_tabs();
  }
  comma = true;
}

void Json_formatter::append_semicolon() const noexcept {
  json.push_back(':');
  if (!quoted) {
    json.push_back(' ');
  }
  semicolon = true;
}

void Json_formatter::append_quote(const std::string& color) const noexcept {
  if ((!comma && semicolon && !block)) {
    json.append(red);
  }
  else if (!quoted) {
    json.append(color);
  }
  json.push_back('\"');

  if (quoted) {
    json.append(end_of_color);
  }
  quoted    = !quoted;
  comma     = false;
  semicolon = false;
  block     = false;
}

void Json_formatter::append_digit(char digit, const std::string& color) const noexcept {
  if (!quoted) {
    json.append(color + digit);
    json.append(end_of_color);
  } else {
    json.push_back(digit);
  }
}

std::string Json_formatter::format() const {
  for (uint64_t i = 0; i < data.size(); i++) {
    switch (data[i]) {
      case '{':
        append_brace('{', grey);
        break;

      case '}':
        append_brace('}', grey);
        break;

      case '[':
        append_brace('[', grey);
        break;

      case ']':
        append_brace(']', grey);
        break;

      case ',':
        append_comma();
        break;

      case ':':
        append_semicolon();
        break;

      case '"':
        append_quote(purple);
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
        append_digit(data[i], mint);
        break;

      default:
        json.push_back(data[i]);
        break;
    }
  }
  return json;
}
