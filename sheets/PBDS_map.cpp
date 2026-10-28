#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Notice the first two parameters: <Key_Type, Value_Type>
typedef tree<
    int,                     // Key type (e.g., player ID)
    int,                     // Value type (e.g., player Score) - THIS MAKES IT A MAP!
    less<int>,               // Comparison function (sorts by Key)
    rb_tree_tag,             
    tree_order_statistics_node_update 
> ordered_map;

int main() {
    ordered_map mpp;

    // 1. You can insert exactly like a normal map
    mpp[10] = 500; // Key 10, Value 500
    mpp[20] = 150; // Key 20, Value 150
    mpp[5]  = 900; // Key 5,  Value 900

    // 2. The magic functions still work perfectly!
    // They operate purely on the KEYS.
    
    // Find the 1st smallest KEY (0-indexed)
    auto it = mpp.find_by_order(1);
    cout << "Key: " << it->first << ", Value: " << it->second << "\n"; 
    // Outputs: Key: 10, Value: 500 (since keys are sorted 5, 10, 20)

    // Find how many keys are strictly less than 20
    cout << mpp.order_of_key(20) << "\n"; 
    // Outputs: 2 (Keys 5 and 10 are smaller)

    return 0;
}