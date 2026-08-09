# VASP Flexibility Engine - 460K checks/sec + Pluggable Policies

Extensible VASP compliance engine - Function pointer architecture.

![Architecture Comparison](https://raw.githubusercontent.com/nsmanju/vasp-flexibility-engine/main/docs/architecture.png)

## Benchmark
| Metric | Value |
|--------|-------|
| Throughput | 460,163 checks/sec |
| Architecture | Function pointer RiskPolicy |
| Blacklist | 5,000 entries |
| Policies | default_policy, strict_policy |
| Compliance | SFC Travel Rule HKD 8000 |
| Target | OSL \| HashKey - Staff Engineer |

## Build
```bash
make clean && make && make test
EOF
