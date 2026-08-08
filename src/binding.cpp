#include <pybind11/pybind11.h>
#include "screener.h"

namespace py = pybind11;

PYBIND11_MODULE(vasp_core, m) {
    m.doc() = "VASP Screener Core - O(1) Flexibility Engine";
    
    py::class_<Screener>(m, "Screener")
        .def(py::init<>())
        .def("load_blacklist", &Screener::load_blacklist)
        .def("is_risky", &Screener::is_risky)
        .def("needs_travel_rule", &Screener::needs_travel_rule)
        .def("blacklist_size", &Screener::blacklist_size)
        .def("set_policy", &Screener::set_policy)
        .def_static("default_policy", &Screener::default_policy)
        .def_static("strict_policy", &Screener::strict_policy);
}
