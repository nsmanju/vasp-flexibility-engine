// Python binding using pybind11 - Bridge between C++ speed and Python ease
#include <pybind11/pybind11.h>
#include "screener.h"

namespace py = pybind11; // Shortcut

// This creates a Python module named 'vasp_core'
// When you do 'import vasp_core' in Python, this code runs
PYBIND11_MODULE(vasp_core, m) {
  m.doc() = "High-performance VASP screening engine (SFC compliant)"; // Module description
  
  // Expose C++ class Screener to Python
  py::class_<Screener>(m, "Screener")
    .def(py::init<>()) // Allow Python to create Screener() objects
    .def("load_blacklist", &Screener::load_blacklist, "Load blacklisted wallets from file")
    .def("is_risky", &Screener::is_risky, "Check if wallet is risky")
    .def("needs_travel_rule", &Screener::needs_travel_rule, "Check if SFC Travel Rule applies (>= HKD 8000)");
}
