#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <cassert>

class WordLadderI {
public:
    static int ladderLength(const std::string& beginWord, const std::string& endWord,
                            const std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            std::string original = word;
            for (size_t i = 0; i < word.length(); ++i) {
                char origChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (dict.count(word)) {
                        dict.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = origChar;
            }
        }
        return 0;
    }
};

int main() {
    std::string begin1 = "hit", end1 = "cog";
    std::vector<std::string> list1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    assert(WordLadderI::ladderLength(begin1, end1, list1) == 5); // hit -> hot -> dot -> dog -> cog

    std::string begin2 = "hit", end2 = "cog";
    std::vector<std::string> list2 = {"hot", "dot", "dog", "lot", "log"};
    assert(WordLadderI::ladderLength(begin2, end2, list2) == 0); // cog is not in list

    std::cout << "All Word Ladder I tests passed successfully!\n";
    return 0;
}

