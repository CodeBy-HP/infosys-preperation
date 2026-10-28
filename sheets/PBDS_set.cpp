#include <iostream>
// 1. Include the PBDS headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; // 2. Include the PBDS namespace

// 3. Define the ordered set macro (memorize this block or keep it in your template)
typedef tree<
    pair<int, int>,          // Type of elements (pair used to handle duplicates)
    null_type,               // Mapped type (null_type means it acts like a set, not a map)
    less<pair<int, int>>,    // Comparison function (use greater<> for descending)
    rb_tree_tag,             // Underlying data structure (Red-Black Tree)
    tree_order_statistics_node_update // The policy that enables the two magic functions
> ordered_set;

int main() {
    ordered_set st;
    
    // Inserting elements {value, unique_id}
    st.insert({10, 1});
    st.insert({50, 2});
    st.insert({30, 3});
    st.insert({50, 4}); // Duplicate 50, but unique ID makes it valid

    // Magic Function 1: find_by_order (0-indexed)
    // Find the 2nd smallest element (index 1)
    auto it = st.find_by_order(1); 
    cout << "2nd smallest is: " << it->first << "\n"; // Outputs 30

    // Magic Function 2: order_of_key
    // Find how many elements are strictly less than {50, 0}
    int count_smaller = st.order_of_key({50, 0}); 
    cout << "Elements smaller than 50: " << count_smaller << "\n"; // Outputs 2 (10 and 30)

    // Erasing an element
    st.erase({30, 3});

    return 0;
}