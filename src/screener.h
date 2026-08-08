#pragma once
#include <string>
#include <unordered_set>

using RiskPolicy = bool(*)(const std::string&, const std::unordered_set<std::string>&);

class Screener {
public:
    Screener();
    bool load_blacklist(const std::string& file_path);
    bool is_risky(const std::string& wallet) const;
    void set_policy(RiskPolicy policy);
    size_t blacklist_size() const { return blacklist.size(); }
    bool needs_travel_rule(double amount) const { return amount >= 8000.0; }
    
    static bool default_policy(const std::string& wallet, const std::unordered_set<std::string>& blacklist);
    static bool strict_policy(const std::string& wallet, const std::unordered_set<std::string>& blacklist);
private:
    std::unordered_set<std::string> blacklist;
    RiskPolicy current_policy;
};
