#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>

class AccountsMerge {
private:
    class DSU {
        std::vector<int> parent;
    public:
        DSU(int n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
        }
        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionNodes(int u, int v) {
            int rootU = findUPar(u), rootV = findUPar(v);
            if (rootU != rootV) {
                parent[rootU] = rootV;
            }
        }
    };

public:
    static std::vector<std::vector<std::string>> accountsMerge(const std::vector<std::vector<std::string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        std::unordered_map<std::string, int> emailToId;

        // 1. Union accounts that share emails
        for (int i = 0; i < n; ++i) {
            for (size_t j = 1; j < accounts[i].size(); ++j) {
                const std::string& email = accounts[i][j];
                if (!emailToId.count(email)) {
                    emailToId[email] = i;
                } else {
                    dsu.unionNodes(i, emailToId[email]);
                }
            }
        }

        // 2. Group emails by representative parent account
        std::unordered_map<int, std::vector<std::string>> mergedEmails;
        for (const auto& [email, id] : emailToId) {
            int root = dsu.findUPar(id);
            mergedEmails[root].push_back(email);
        }

        // 3. Format final result with sorted emails
        std::vector<std::vector<std::string>> result;
        for (auto& [root, emails] : mergedEmails) {
            std::sort(emails.begin(), emails.end());
            std::vector<std::string> account;
            account.push_back(accounts[root][0]); // Name
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<std::string>> acc = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    auto res = AccountsMerge::accountsMerge(acc);
    assert(res.size() == 3);

    std::cout << "All Accounts Merge tests passed successfully!\n";
    return 0;
}

