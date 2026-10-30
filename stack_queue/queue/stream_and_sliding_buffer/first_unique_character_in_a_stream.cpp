#include <iostream>
#include <queue>
#include <vector>
#include <string>

class StreamFirstUnique {
private:
    int freq[256];
    std::queue<char> q;

public:
    StreamFirstUnique() {
        for (int i = 0; i < 256; ++i) freq[i] = 0;
    }

    void add(char c) {
        ++freq[(unsigned char)c];
        q.push(c);
    }

    char getFirstUnique() {
        // Lazily remove characters from the front that are no longer unique
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) {
            q.pop();
        }
        return q.empty() ? '#' : q.front();
    }
};

int main() {
    StreamFirstUnique stream;
    std::string s = "aabcba";

    std::cout << "Processing stream: " << s << "\n";
    for (char c : s) {
        stream.add(c);
        std::cout << "Added '" << c << "' -> First Unique: '" << stream.getFirstUnique() << "'\n";
    }

    return 0;
}
