# VASP Compliance Screener - Day 1
Hong Kong SFC compliant risk engine in C++ with Python binding.

## Day 1 Achievements
✅ Built C++ Screener class with O(1) blacklist check
✅ Implemented SFC Travel Rule (HKD 8000 threshold)
✅ Created pybind11 bridge (vasp_core module)
✅ Compiled to 285K shared library

## Build (Linux)
```bash
python3 -m venv venv && source venv/bin/activate
pip install pybind11
c++ -O3 -Wall -shared -std=c++17 -fPIC $(python3 -m pybind11 --includes) src/screener.cpp src/binding.cpp -o vasp_core$(python3-config --extension-suffix)
import vasp_core
s = vasp_core.Screener()
s.needs_travel_rule(9000) # True - SFC requires ID collection

