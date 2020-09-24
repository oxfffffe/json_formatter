#if not defined (JSON_FORMATTER_HPP)
#define JSON_FORMATTER_HPP

#include <fstream> //string included
#include <cassert>

class Json_formatter
{
public:
  Json_formatter() = delete;
  Json_formatter(Json_formatter&) = delete;
  Json_formatter(Json_formatter&&) = delete;
  Json_formatter operator=(Json_formatter&) = delete;
  Json_formatter(const char* filename);
  std::string format() const;

private:
  std::string data;
  mutable std::string formatted;
  const char* tab = "  ";
  mutable bool is_inside_quotes = false;
  mutable uint8_t tabs = 0;
#if defined (__linux__)
  const std::string end_of_color = "\e[0m";
  const std::string grey   = "\e[38;5;240m";
  const std::string mint   = "\e[38;5;72m";
  const std::string purple = "\e[38;5;176m";
  const std::string red    = "\e[38;5;174m";
#else
  const std::string end_of_color("");
  const std::string grey("");
  const std::string mint("");
  const std::string purple("");
#endif
  bool file_has_json_ext(std::string filename);
  void append_brace(char brace, const std::string& color) const;
  void append_comma() const;
  void append_quote(const std::string& color) const;
  void append_digit(char digit, const std::string& color) const;
  void append_semicolon() const;
};

#endif // JSON_FORMATTER_HPP
