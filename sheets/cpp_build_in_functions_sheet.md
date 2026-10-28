## Searching & Binary Search Magic

Writing your own binary search under time pressure often leads to infinite loops. These `<algorithm>` functions handle it flawlessly on **sorted** arrays.

* **`std::lower_bound`**: Finds the first element that is **greater than or equal to** (`>=`) your target.
* **`std::upper_bound`**: Finds the first element that is **strictly greater than** (`>`) your target.

```cpp
vector<int> v = {10, 20, 20, 30, 40};
// Returns an iterator, so subtract v.begin() to get the index.
int idx1 = lower_bound(v.begin(), v.end(), 20) - v.begin(); // idx1 = 1
int idx2 = upper_bound(v.begin(), v.end(), 20) - v.begin(); // idx2 = 3

// Quick trick: upper_bound - lower_bound gives you the count of that element
int count = upper_bound(v.begin(), v.end(), 20) - lower_bound(v.begin(), v.end(), 20); // count = 2

```

## Fast Math & Bit Manipulation

Stop writing loops to count bits or find the Greatest Common Divisor.

* **`__builtin_popcount(x)`**: Returns the number of `1`s (set bits) in an integer. It maps directly to a hardware instruction, making it insanely fast. (Use `__builtin_popcountll(x)` for `long long`).

```cpp
int bits = __builtin_popcount(11); // 11 is 1011 in binary. Returns 3.

```

* **`std::gcd(a, b)`**: Finds the Greatest Common Divisor (requires `<numeric>`).

```cpp
int hcf = std::gcd(12, 18); // Returns 6
// Quick trick: LCM is just (a * b) / gcd(a, b)
int lcm = (12 * 18) / std::gcd(12, 18); // Returns 36

```

## Iteration & Accumulation Savers

These save you from writing standard `for` loops, reducing off-by-one errors and saving typing time.

* **`std::accumulate`**: Sums up an entire vector or array (requires `<numeric>`).

```cpp
vector<int> v = {1, 2, 3, 4, 5};
// The 0 is the starting sum. 
int sum = accumulate(v.begin(), v.end(), 0); // Returns 15

// CRITICAL EXAM TIP: If the sum might exceed standard int size, use 0LL
long long big_sum = accumulate(v.begin(), v.end(), 0LL); 

```

* **`std::max_element` & `std::min_element**`: Finds the largest/smallest item.

```cpp
vector<int> v = {4, 1, 9, 3};
// Returns an iterator, use '*' to get the actual value
int highest = *max_element(v.begin(), v.end()); // Returns 9
int lowest = *min_element(v.begin(), v.end());  // Returns 1

```

* **`std::count`**: Counts how many times a specific element appears.

```cpp
vector<int> v = {1, 4, 4, 4, 2};
int fours = count(v.begin(), v.end(), 4); // Returns 3

```

## Combinatorics (The Backtracking Killer)

When a problem asks you to check "all possible arrangements" or "permutations" of a string or array, do not write a recursive backtracking function.

* **`std::next_permutation`**: Rearranges the elements into the next lexicographically greater permutation. It returns `true` if a next one exists, and `false` if it just cycled back to the lowest arrangement.

```cpp
string s = "abc";
// IMPORTANT: The sequence MUST be sorted ascending before starting this loop
sort(s.begin(), s.end()); 

do {
    cout << s << "\n";
} while(next_permutation(s.begin(), s.end()));
// Prints: abc, acb, bac, bca, cab, cba

```


Here are the built-in C++ conversion and string parsing tools that save the most time in coding assessments.

## Number & String Conversions

These prevent you from writing custom `while` loops to extract digits or build numbers.

* **`std::stoll(str, nullptr, base)`**: Converts a string to a `long long`. **CP Tip:** Always use `stoll` instead of `stoi` in coding contests to avoid integer overflow, since test cases often include numbers larger than $2^{31}-1$.
* **`std::to_string(num)`**: Instantly converts any numeric type (int, float, long long) into a `std::string`.

```cpp
// String to Number (Base 10)
string s1 = "123456789012";
long long big_num = stoll(s1); 

// String to Number (Base 2 / Binary Parsing)
string bin = "1010";
int val = stoi(bin, nullptr, 2); // val = 10

// Number to String
int x = 456;
string s2 = to_string(x); // s2 = "456"

```

## Binary <-> String Conversions

As we touched on earlier, `<bitset>` is the absolute fastest way to convert back and forth without writing division/modulo loops.

* **`std::bitset<N>(string).to_ullong()`**: Converts a binary string directly to an integer (unsigned long long).
* **`std::bitset<N>(number).to_string()`**: Converts an integer to a binary string padded with zeros.

```cpp
// Binary String -> Integer
string bin_str = "1101";
unsigned long long num = bitset<32>(bin_str).to_ullong(); // num = 13

// Integer -> Binary String
int n = 13;
string b = bitset<8>(n).to_string(); // b = "00001101"

```

## Entire String Case Manipulation

Do not write `for` loops checking ASCII values to convert strings to lowercase or uppercase. Use `<algorithm>`'s `transform`.

* **`std::transform`**: Applies an operation to every element in a range. Combined with `::tolower` or `::toupper`, it changes the case of a string in one line.

```cpp
string s = "HeLLo WoRLd";

// Convert entire string to lowercase
transform(s.begin(), s.end(), s.begin(), ::tolower); 
// s is now "hello world"

// Convert entire string to uppercase
transform(s.begin(), s.end(), s.begin(), ::toupper); 
// s is now "HELLO WORLD"

```

## Character Classification (`<cctype>`)

When iterating through a string to check for specific character types, never write manual checks like `if(c >= '0' && c <= '9')`. These built-in functions handle edge cases and read cleanly.

* **`isdigit(c)`**: Returns true if the character is '0'-'9'.
* **`isalpha(c)`**: Returns true if the character is 'a'-'z' or 'A'-'Z'.
* **`isalnum(c)`**: Returns true if the character is alphanumeric (letter or number).
* **`tolower(c)` / `toupper(c)**`: Converts a *single character*.

```cpp
char c1 = '7';
char c2 = 'A';

if (isdigit(c1)) { /* True, it's a number */ }
if (isalpha(c2)) { /* True, it's a letter */ }

char lower = tolower(c2); // lower = 'a'

```

## The String Splitter (`<sstream>`)

C++ does not have a built-in `string.split()` function like Python or Java. If a problem gives you a sentence of words separated by spaces, `std::stringstream` is the fastest way to extract them.

* **`std::stringstream`**: Treats a string like `cin`, allowing you to extract formatted data from it effortlessly.

```cpp
#include <sstream>

string sentence = "apple 100 banana 250";
stringstream ss(sentence);
string word;
int price;

// Extracts alternating strings and integers automatically!
while (ss >> word >> price) {
    cout << "Item: " << word << ", Cost: " << price << "\n";
}
// Output: 
// Item: apple, Cost: 100
// Item: banana, Cost: 250

```

Here are the only ASCII values you actually need to memorize for coding assessments, followed by the standard arithmetic tricks used to manipulate them instantly.

## The Core ASCII Values

You do not need to memorize the whole table. Because characters in C++ are just integers under the hood, memorizing these three starting points lets you calculate any other character's value.

* **`'0'`** = **48** *(so '1' is 49, '9' is 57)*
* **`'A'`** = **65** *(so 'Z' is 90)*
* **`'a'`** = **97** *(so 'z' is 122)*
* **`' '` (Space)** = **32**

---

## Char <-> Int Conversion Tricks (Digits)

When a problem gives you a string of numbers (e.g., `"739"`), you often need to loop through and do math with the individual characters. Do not use `stoi()` on a single character.

**1. Character Digit to Integer**
Subtracting the character `'0'` (which is 48) from any numeric character gives you its actual integer value.

```cpp
char c = '7'; // ASCII 55
int val = c - '0'; // 55 - 48 = 7

```

**2. Integer to Character Digit**
Adding `'0'` to a single-digit integer converts it back to its character representation.

```cpp
int val = 4;
char c = val + '0'; // 4 + 48 = 52 (which is ASCII '4')

```

---

## Alphabet Indexing (Frequency Arrays & Tries)

In string problems (like checking for anagrams or finding the most frequent letter), you almost always map the 26 letters to an array of size 26 (indices 0 to 25).

**1. Lowercase letter to Index (0-25)**
Subtract `'a'`.

```cpp
char c = 'd';
int index = c - 'a'; // 'd' (100) - 'a' (97) = 3. 
// 'a' is 0, 'b' is 1, 'c' is 2, 'd' is 3.

```

**2. Uppercase letter to Index (0-25)**
Subtract `'A'`.

```cpp
char c = 'F';
int index = c - 'A'; // 70 - 65 = 5.

```

**3. Index back to Letter**
Add the base letter back to the index.

```cpp
int index = 10;
char lower = index + 'a'; // Returns 'k'
char upper = index + 'A'; // Returns 'K'

```

---

## The "32" Case Conversion Trick

Notice that `'a'` (97) and `'A'` (65) are exactly **32** apart. This is not an accident—32 is a power of 2, which allows for incredibly fast bitwise case swapping in C++ without needing `tolower()` or `toupper()`.

Since the space character `' '` has an exact ASCII value of 32, you can use it with bitwise operations:

* **Flip Case (XOR `^`):** `char flipped = 'a' ^ ' ';` // Becomes 'A'
* **Force Lowercase (OR `|`):** `char lower = 'G' | ' ';` // Becomes 'g'
* **Force Uppercase (AND `&`):** `char upper = 'm' & '_';` // Becomes 'M' (underscore is 95, which clears the 32-bit)


## 1. Reading a Full Line (And the Trailing Newline Trap)

When you use `cin >>`, it leaves a hidden newline character (`\n`) in the input buffer. If you call `getline()` right after `cin >>`, it reads that leftover newline and instantly stops, leaving you with an empty string.

**The Fix:** Use `std::ws` to consume whitespace before reading the line.

```cpp
int n;
string sentence;

cin >> n; // Reads the number, leaves '\n' in the buffer
// getline(cin, sentence); // BUG: Will read the '\n' and be empty

// CORRECT: 'ws' clears any trailing spaces or newlines first
getline(cin >> ws, sentence); 

```

## 2. Array of Unknown Size on a Single Line

Assessments often give you a single line of space-separated integers, but they don't tell you how many there are. You cannot use a standard `for` loop because you don't know the bound.

**The Fix:** Read the entire line with `getline`, then use `stringstream` to extract the numbers one by one.

```cpp
#include <sstream>
#include <vector>

string line;
getline(cin >> ws, line); // Get the whole line

stringstream ss(line);
vector<int> nums;
int temp;

// ss >> temp automatically skips spaces and extracts integers
while (ss >> temp) {
    nums.push_back(temp);
}
// nums now contains all the integers from that line

```

## 3. Comma-Separated Inputs

Instead of spaces, the input looks like this: `10,20,30,40`. `cin >>` will fail because it stops at spaces, not commas.

**The Fix (Method A - Stringstream):** Use `getline` with a custom delimiter.

```cpp
string line = "10,20,30,40";
stringstream ss(line);
string token;
vector<int> nums;

// Read from 'ss' into 'token', stopping at ','
while (getline(ss, token, ',')) {
    nums.push_back(stoi(token)); // Convert the string chunk to an integer
}

```

**The Fix (Method B - Char parsing):** If you know it's always `Number,Number...` you can just read the comma directly into a dummy `char` variable.

```cpp
int a, b, c;
char comma;
// Reads: 10 into a, ',' into comma, 20 into b...
cin >> a >> comma >> b >> comma >> c; 

```

## 4. Reading Until End of File (EOF)

Sometimes the problem says "Process test cases until the end of input" without giving you a variable `T` for the number of test cases.

**The Fix:** Wrap your `cin` statement in a `while` loop. It automatically returns `false` when there is no more data to read.

```cpp
int a, b;

// Will keep running as long as it successfully reads two integers
while (cin >> a >> b) {
    cout << "Sum: " << a + b << "\n";
}

```

## 5. Fast I/O (Preventing Time Limit Exceeded)

In strict platforms like HackerRank or standard CP platforms, standard `cin` and `cout` are too slow for test cases with $10^5$ or more inputs.

**The Fix:** Add these two lines at the very beginning of your `main()` function. This disables the synchronization between C and C++ standard streams, making `cin`/`cout` as fast as `scanf`/`printf`.

```cpp
int main() {
    // 1. Unsyncs C and C++ streams
    ios_base::sync_with_stdio(false); 
    // 2. Unties cin from cout (so cout doesn't flush before every cin)
    cin.tie(NULL); 
    
    // ... write the rest of your code here ...
    
    // BONUS TIP: Never use 'endl' with Fast I/O. 
    // 'endl' flushes the output buffer and slows you down. 
    // ALWAYS use "\n" instead.
    cout << "Answer\n"; 
}

```
---

### What is `getline(ss, word, ',')`?

Most people are familiar with `getline(cin, line)`, which reads an entire line from the standard input until it hits a newline (`\n`).

However, `std::getline` actually works with **any input stream** (`std::istream`), including a `std::stringstream` (`ss`). It takes three arguments in this form:


$$\text{getline}(\text{stream}, \text{destination\_string}, \text{delimiter})$$

---

### Step-by-Step Breakdown of the Parameters

1. **`ss` (The Stream)**: The input stream containing the text you want to read from (in your code, this holds the full line of comma-separated words).
2. **`word` (The Destination)**: The `string` variable where the extracted chunk of text will be saved.
3. **`','` (The Delimiter)**: The character that tells `getline` where to stop reading.

---

