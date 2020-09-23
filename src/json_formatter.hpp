#if not defined (JSON_FORMATTER_HPP)
#define JSON_FORMATTER_HPP

#include <fstream> //string included
#include <cassert>

class Json_formatter
{
public:
  Json_formatter() = delete;
<<<<<<< HEAD
  Json_formatter(Json_formatter&) = delete;
  Json_formatter(Json_formatter&&) = delete;
  Json_formatter operator=(Json_formatter&) = delete;
  Json_formatter(const char* filename);
  std::string format() const;

private:
  std::string data;
  const char* tab = "  ";
  mutable bool is_inside_quotes = false;
#if defined (__linux__)
  std::string end_of_color = "\e[0m";
  std::string grey = "\e[38;5;240m";
  std::string mint = "\e[38;5;72m";
  std::string purple = "\e[38;5;176m";
#else
  std::string end_of_color("");
  std::string grey("");
  std::string mint("");
  std::string purple("");
#endif
  bool file_has_json_ext(std::string filename);
  void append_brace(char brace, std::string& text, uint8_t& tabs, const std::string& color) const;
  void append_comma(std::string& text, uint8_t& tabs) const;
  void append_semicolon(std::string& text) const;
  void append_quote(std::string& text) const;
  void append_digit(std::string& text, char digit) const;
=======
    Json_formatter(const char* filename);
    Json_formatter operator=(Json_formatter&) = delete;
    std::string format() const;
private:
    bool file_has_json_ext(std::string filename);
    std::string data;
    const char* tab = "  ";
>>>>>>> eec0e41897978819419a53e4be56d97b0c3b04a9
};

#endif // JSON_FORMATTER_HPP
