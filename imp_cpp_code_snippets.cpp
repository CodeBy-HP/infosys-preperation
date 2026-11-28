

// LOWER BOUND
vector<int> v = {1, 2, 2, 2, 4, 5, 7};

auto it = lower_bound(v.begin(), v.end(), 2);

cout << *it;  // 2
cout << (it - v.begin()); // 1 index

// if not found return v.end()


// UPPER BOUND
auto it = upper_bound(v.begin(), v.end(), 2);

cout << *it;  // 4
cout << (it - v.begin()); // 4

// BINARY SEARCH
// Check existence (sorted vector)
bool exists = binary_search(v.begin(), v.end(), x);

// USES
// First element >= x
auto lb = lower_bound(v.begin(), v.end(), x);

// First element > x
auto ub = upper_bound(v.begin(), v.end(), x);

// Number of elements equal to x
int count = ub - lb;

// Number of elements >= x
int countGreaterEqual = v.end() - lb;

// Number of elements > x
int countGreater = v.end() - ub;


// GCD
int ans = __gcd(12, 18);  // 6


// MAX & MIN ELEMENTS
// Maximum and minimum
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());

// SORTING 
// DESCENDING
sort(v.begin(), v.end(), greater<int>());
sort(v.rbegin(), v.rend());

