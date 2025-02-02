#include <cstring>
#include <iostream>

class String {
public:
  String(const char *c) {
    std::cout << "Constructor\n";
    data_ = (char *)std::malloc(std::strlen(c) + 1);
    std::strcpy(data_, c);
  }
  ~String() { std::free(data_); }

  String(const String &s) {
    data_ = (char *)std::malloc(std::strlen(s.data()) + 1);
    std::strcpy(data_, s.data());
  }
  String &operator=(const String &s) {
    if (&s != this) {
      std::free(data_);
      data_ = (char *)std::malloc(std::strlen(s.data()) + 1);
      std::strcpy(data_, s.data());
    }
    return *this;
  }
  String(String &&s) noexcept {
    data_ = s.data();
    s.data() = nullptr;
  }
  String &operator=(String &&s) noexcept {
    if (&s != this) {
      std::free(data_);
      data_ = s.data();
      s.data() = nullptr;
    }
    return *this;
  }

  char *data() const { return data_; }

  char *&data() { return data_; }

private:
  char *data_{nullptr};
};
