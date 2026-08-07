// VASP Screener - Hong Kong SFC Compliant Risk Engine
// Author: Nadkalpur Manjunath
// Purpose: High-performance AML + Travel Rule checks in C++

#pragma once
#include <string>
#include <unordered_set>

// Screener class: The core security guard for crypto transactions
// Why class? So we can create many screeners with different blacklists
class Screener {
  // unordered_set = Hash Table, O(1) lookup even for 1M entries
  // Used by OSL, HashKey for real-time screening
  std::unordered_set<std::string> blacklist;

public:
  // Load blacklisted wallets from file (e.g., OFAC, SFC watchlist)
  void load_blacklist(const std::string& path);

  // Check if wallet is risky - returns true if in blacklist
  bool is_risky(const std::string& wallet);

  // SFC Travel Rule: HKD 8000 threshold (as per SFC AML/CFT Guideline)
  // If amount >= 8000, VASP must collect and transmit originator/beneficiary info
  bool needs_travel_rule(double amount);
};
