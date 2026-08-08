#include "screener.h"
#include <fstream>
#include <algorithm>
#include <cctype>

Screener::Screener() : current_policy(default_policy) {}

bool Screener::load_blacklist(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) return false;
    std::string wallet;
    while (std::getline(file, wallet)) {
        if (wallet.empty()) continue;
        blacklist.insert(wallet);
    }
    return true;
}

bool Screener::is_risky(const std::string& wallet) const {
    return current_policy(wallet, blacklist);
}

void Screener::set_policy(RiskPolicy policy) {
    current_policy = policy;
}

bool Screener::default_policy(const std::string& wallet, const std::unordered_set<std::string>& blacklist) {
    return blacklist.find(wallet) != blacklist.end();
}

bool Screener::strict_policy(const std::string& wallet, const std::unordered_set<std::string>& blacklist) {
    std::string lower = wallet;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    for (const auto& entry : blacklist) {
        std::string e = entry;
        std::transform(e.begin(), e.end(), e.begin(), ::tolower);
        if (lower.find(e) != std::string::npos || e.find(lower) != std::string::npos) return true;
    }
    return blacklist.find(wallet) != blacklist.end();
}
