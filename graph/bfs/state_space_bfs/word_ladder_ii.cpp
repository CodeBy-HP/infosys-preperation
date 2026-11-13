#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cassert>

class WordLadderII {
private:
    static void dfsBacktrack(const std::string& word, const std::string& beginWord,
                             const std::unordered_map<std::string, int>& dist,
                             std::vector<std::string>& path,
                             std::vector<std::vector<std::string>>& results) {
        path.push_back(word);
        if (word == beginWord) {
            std::vector<std::string> fullPath = path;
            std::reverse(fullPath.begin(), fullPath.end());
            results.push_back(fullPath);
            path.pop_back();
            return;
        }

        int currDist = dist.at(word);
        std::string temp = word;

        for (size_t i = 0; i < word.length(); ++i) {
            char orig = temp[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                temp[i] = ch;
                auto it = dist.find(temp);
                if (it != dist.end() && it->second == currDist - 1) {
                    dfsBacktrack(temp, beginWord, dist, path, results);
                }
            }
            temp[i] = orig;
        }
        path.pop_back();
    }

public:
    static std::vector<std::vector<std::string>> findLadders(const std::string& beginWord,
                                                              const std::string& endWord,
                                                              const std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        // Phase 1: BFS to compute distances
        std::unordered_map<std::string, int> dist;
        std::queue<std::string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            std::string word = q.front();
            q.pop();

            if (word == endWord) break;

            int currentDist = dist[word];
            std::string temp = word;

            for (size_t i = 0; i < word.length(); ++i) {
                char orig = temp[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    if (dict.count(temp) && !dist.count(temp)) {
                        dist[temp] = currentDist + 1;
                        q.push(temp);
                    }
                }
                temp[i] = orig;
            }
        }

        if (!dist.count(endWord)) return {};

        // Phase 2: DFS backward reconstruction
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> path;
        dfsBacktrack(endWord, beginWord, dist, path, results);
        return results;
    }
};

int main() {
    std::string begin = "hit", end = "cog";
    std::vector<std::string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    auto paths = WordLadderII::findLadders(begin, end, words);
    assert(paths.size() == 2);
    // Two paths of length 5:
    // hit -> hot -> dot -> dog -> cog
    // hit -> hot -> lot -> log -> cog
    for (const auto& p : paths) {
        assert(p.size() == 5);
        assert(p.front() == "hit" && p.back() == "cog");
    }

    std::cout << "All Word Ladder II tests passed successfully!\n";
    return 0;
}

