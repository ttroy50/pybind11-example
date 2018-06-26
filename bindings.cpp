#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

// Simple function to export
int add(int x, int y) { return x + y; }

// Class with properties and a function
class Adder {
public:
  Adder(int x) : x_(x){};
  int add(int y) { return x_ + y; }

  void setAddition(int x) { x_ = x; }
  int getAddition() { return x_; }

private:
  int x_;
};

// using the stl
std::string join(std::vector<std::string> tojoin) {
  std::string ret;
  for (auto c : tojoin) {
    ret += c;
  }
  return ret;
}

// define a module to be imported by python
PYBIND11_MODULE(pybindings, mymodule) {
  using namespace pybind11::literals; // for _a literal to define arguments
  mymodule.doc() = "example module to export code";

  // export the add function
  mymodule.def("add", &add, "Add 2 numbers together", "x"_a, "y"_a);

  // export the Adder class
  pybind11::class_<Adder>(mymodule, "Adder")
      .def(pybind11::init<int>())
      .def("add", &Adder::add)
      .def_property("addition", &Adder::getAddition, &Adder::setAddition);

  // export the join method
  mymodule.def("join", &join, "Join a list into a string", "tojoin"_a);
}
