cmake_minimum_required(VERSION 3.5)

project (pybind-example)

find_package(pybind11)

# adds a library pybindings that can be called by python
pybind11_add_module(pybindings bindings.cpp)

message("${pybind11_VERSION}")
message("${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")

enable_testing()

add_test(NAME pybindings_test
    COMMAND python3 ${CMAKE_SOURCE_DIR}/bindings.py)
#need pythonpath to import module
set_tests_properties (pybindings_test PROPERTIES ENVIRONMENT
    "PYTHONPATH=${pybind-example_BINARY_DIR}")
