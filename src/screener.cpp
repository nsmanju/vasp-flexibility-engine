// Implementation of VASP Screener - Optimized for speed
#include "screener.h"
#include <fstream> // For reading blacklist files

// Load blacklist from text file, one wallet per line
void Screener::load_blacklist(const std::string& path) {
  std::ifstream f(path); // Open file
  std::string line;
  // Read line by line, skip empty lines
  while (std::getline(f, line)) {
    if(!line.empty()) {
      blacklist.insert(line); // Insert into hash table - O(1)
    }
  }
}

// Risk check: Is this wallet in our blacklist?
// Complexity: O(1) average - critical for high-frequency trading
bool Screener::is_risky(const std::string& w) { 
  return blacklist.count(w); // count = 1 if exists, 0 if not
}

// SFC Travel Rule compliance check
// Hong Kong SFC requires Travel Rule for virtual asset transfers >= HKD 8000
// Equivalent to FATF Recommendation 16
bool Screener::needs_travel_rule(double amt) { 
  return amt >= 8000.0; // Threshold defined by SFC
}
