#ifndef _MOC_BYTE
#define _MOC_BYTE

#include "vector"
#include "string"

namespace moc {
typedef unsigned char byte;

class bytes : public std::vector<byte> {
 public:
  int ptr;
  bytes();
  bytes(int _len);
  bytes(std::string _src);
  bytes(const void* _addr, int _len);
  bytes range(int start, int end);
  std::string to_string();
  bytes operator+(const bytes& other);
  void operator+=(const bytes& other);
  void operator+=(byte other);
  std::string to_hex_str();
  bool has_next();
  std::string next_string();
  long next_int32();
  void print_as_hex();
  void println_as_hex();
  void to_mem(void* _addr, int _len);
};
}  // namespace moc

#endif