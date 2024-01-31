#include <string>
#include <array>
#include <map>
#include <fstream>
#include <sstream>

// (a)
class Flag {
protected:
  std::string _name;
  bool _flagIsSet;
public:
  virtual void parseConfigLine(std::string line) = 0;
  virtual void parseArgs(std::pair<int, char**> args) = 0;
  Flag(std::string name): _name(name), _flagIsSet(false) {};
};

// (b)
// (i)
class BoolFlag : public Flag {
public:
  void parseConfigLine(std::string line) override {

  }
  void parseArgs(std::pair<int, char**> args) override {

  }
  bool get() {
    return _flagIsSet;
  }
};

// (ii)
class StringFlag : public Flag {
public:
  void parseConfigLine(std::string line) override {

  }
  void parseArgs(std::pair<int, char**> args) override {

  }
};

// (iii)
class RangeFlag : public Flag {
public:
  void parseConfigLine(std::string line) override {

  }
  void parseArgs(std::pair<int, char**> args) override {

  }
};

// (c)
class Flags {
private:
  std::string _path;
  std::pair<int, char**> _args;
public:
  // (i)
  Flags(int argc, char* argv[], std::string path): _path(path), _args(std::make_pair(argc, argv)) {}

  // (ii)
  void registerBool(std::string name) {

  }
  void registerString(std::string name) {

  }
  void registerRange(std::string name) {

  }

  // (iii)
  void readArgs() {

  }

  // (iv)
  void readConfig() {

  }

  // (v)
  bool getBool(std::string name) {

  }
  std::string getString(std::string name) {

  }
  std::array<double, 2> getRange(std::string name) {

  }
};