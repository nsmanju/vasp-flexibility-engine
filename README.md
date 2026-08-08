# VASP Flexibility Engine - 460K checks/sec + Pluggable Policies 🔌

Extensible VASP compliance engine - Function pointer architecture.

## Benchmark
| Metric | Value |
|--------|-------|
| Throughput | **460,163 checks/sec** |
| Architecture | Function pointer `RiskPolicy` |
| Blacklist | 5,000 entries |
| Policies | `default_policy`, `strict_policy` (extensible) |
| Compliance | SFC Travel Rule HKD 8000 |
| Language | C++17 + pybind11 Python bindings |

## Why Flexibility?

```cpp
// Runtime policy injection
screener.set_policy(Screener::strict_policy);

// Add your own custom policies
bool my_custom_policy(const std::string& wallet, const auto& blacklist) {
    // Custom KYC/PEP logic
    return blacklist.find(wallet) != blacklist.end();
}
screener.set_policy(my_custom_policy);
