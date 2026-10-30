# Trees Master Roadmap & Problem Sheet

Welcome to the **Binary Trees & Binary Search Trees** paradigm. While linear structures like arrays and linked lists have a single successor, hierarchical trees branch in multiple directions. 

Mastering trees requires shifting away from iterative array thinking and internalizing **recursion archetypes**:
1. **Bottom-Up DFS (Information Gathering):** Asking children for information first, synthesizing the local state (e.g. arch diameter or balance), and passing a single branch contribution upward.
2. **Top-Down DFS (State & Constraint Passing):** Passing constraints, path journals, or prefix sums downwards from parent to child, backtracking before returning.
3. **Level-Order BFS (Horizontal Snapshots):** Freezing row widths via `q.size()` to capture rows, boundary views, and shortest radial paths.
4. **BST Invariant:** Exploiting $Left < Node < Right$ to achieve $O(H)$ search, in-place flattening via In-Order traversal, and $O(1)$ space validations.

---

## 1. Traversals & Views (Horizontal BFS & Coordinate Projections)
*Focus: Processing trees tier-by-tier, snapshot freezing, alternating directions, and coordinate mapping.*

* **[Problem 1: Binary Tree Level Order Traversal](traversals_and_views/binary_tree_level_order_traversal.md)** ([C++ Code](traversals_and_views/binary_tree_level_order_traversal.cpp)): The foundational BFS snapshot loop (`int levelSize = q.size()`) partitioning nodes strictly by horizontal rows.
* **[Problem 2: Binary Tree Zigzag Level Order Traversal](traversals_and_views/binary_tree_zigzag_level_order.md)** ([C++ Code](traversals_and_views/binary_tree_zigzag_level_order.cpp)): Alternating left-to-right and right-to-left placement using direct index mirroring ($O(1)$ extra reversal overhead).
* **[Problem 3: Binary Tree Right Side View](traversals_and_views/binary_tree_right_side_view.md)** ([C++ Code](traversals_and_views/binary_tree_right_side_view.cpp)): Capturing the last visible node of each tier using both level-snapshot BFS and reverse preorder DFS (`Root -> Right -> Left`).
* **[Problem 4: Vertical Order Traversal of a Binary Tree](traversals_and_views/vertical_order_traversal.md)** ([C++ Code](traversals_and_views/vertical_order_traversal.cpp)): 2D coordinate assignment `(col, row, val)` with multi-key sorting and column grouping.

---

## 2. Bottom-Up DFS (Information Gathering & Dimensions)
*Focus: Passing subproblem depths/gains upwards while updating global maximums that arch across the root.*

* **[Problem 5: Maximum Depth of Binary Tree](bottom_up_dfs/maximum_depth_of_binary_tree.md)** ([C++ Code](bottom_up_dfs/maximum_depth_of_binary_tree.cpp)): The foundational height recurrence $1 + \max(\text{depth}(L), \text{depth}(R))$.
* **[Problem 6: Diameter of Binary Tree](bottom_up_dfs/diameter_of_binary_tree.md)** ([C++ Code](bottom_up_dfs/diameter_of_binary_tree.cpp)): The "Pass up height, update arch diameter" pattern calculating longest node-to-node path in $O(N)$ time.
* **[Problem 7: Balanced Binary Tree](bottom_up_dfs/balanced_binary_tree.md)** ([C++ Code](bottom_up_dfs/balanced_binary_tree.cpp)): Bottom-up short-circuiting with a `-1` error sentinel to verify height balance in $O(N)$ instead of naive $O(N^2)$.
* **[Problem 8: Binary Tree Maximum Path Sum](bottom_up_dfs/binary_tree_maximum_path_sum.md)** ([C++ Code](bottom_up_dfs/binary_tree_maximum_path_sum.cpp)): The flagship hard tree DP problem: pruning negative child branch contributions with $\max(0, \text{gain})$ and updating global arching sum.

---

## 3. Top-Down DFS & Paths (Path Finding & Backtracking)
*Focus: Downward state passing, root-to-leaf paths, running prefix sums, and backtrack vector sanitation.*

* **[Problem 9: Path Sum](top_down_dfs_and_paths/path_sum.md)** ([C++ Code](top_down_dfs_and_paths/path_sum.cpp)): Target sum deduction stopping strictly at validated leaf nodes (`!node->left && !node->right`).
* **[Problem 10: Path Sum II](top_down_dfs_and_paths/path_sum_ii.md)** ([C++ Code](top_down_dfs_and_paths/path_sum_ii.cpp)): Collecting full path vectors using top-down DFS and careful `pop_back()` backtracking.
* **[Problem 11: Path Sum III](top_down_dfs_and_paths/path_sum_iii.md)** ([C++ Code](top_down_dfs_and_paths/path_sum_iii.cpp)): Prefix sum hash map on trees reducing the $O(N^2)$ double DFS search down to $O(N)$ single pass with map backtracking.
* **[Problem 12: Sum Root to Leaf Numbers](top_down_dfs_and_paths/sum_root_to_leaf_numbers.md)** ([C++ Code](top_down_dfs_and_paths/sum_root_to_leaf_numbers.cpp)): Base-10 digit accumulation along branches ($\text{sum} \times 10 + \text{val}$).

---

## 4. Lowest Common Ancestor (LCA)
*Focus: Post-order ancestor scouting, split-point discovery, and reducing tree LCA to graph/list topologies.*

* **[Problem 13: Lowest Common Ancestor of a Binary Tree](lowest_common_ancestor/lowest_common_ancestor_binary_tree.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_binary_tree.cpp)): Bottom-up scouting bubbling discovered targets and detecting the exact convergence point where both subtrees return non-null.
* **[Problem 14: Lowest Common Ancestor of a Binary Search Tree](lowest_common_ancestor/lowest_common_ancestor_bst.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_bst.cpp)): Utilizing BST order property to find the split point in $O(H)$ time and $O(1)$ space.
* **[Problem 15: Lowest Common Ancestor with Parent Pointers](lowest_common_ancestor/lowest_common_ancestor_with_parent_pointers.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_with_parent_pointers.cpp)): Mathematical reduction from tree LCA to intersecting linked lists using two-pointer path equalization.

---

## 5. Binary Search Trees (BST Invariant & In-Order Flattening)
*Focus: Strictly ordered subtrees, monotonic in-order traversals, and structural updates.*

* **[Problem 16: Validate Binary Search Tree](binary_search_tree/validate_binary_search_tree.md)** ([C++ Code](binary_search_tree/validate_binary_search_tree.cpp)): Top-down mathematical range propagation $(low, high)$ vs. in-order strictly increasing invariant checks.
* **[Problem 17: Kth Smallest Element in a BST](binary_search_tree/kth_smallest_in_bst.md)** ([C++ Code](binary_search_tree/kth_smallest_in_bst.cpp)): In-order traversal countdown ($k--$) with instant early pruning upon hitting target.
* **[Problem 18: Find Mode in Binary Search Tree](binary_search_tree/find_mode_in_bst.md)** ([C++ Code](binary_search_tree/find_mode_in_bst.cpp)): In-order frequency streaming tracking duplicate runs in $O(1)$ auxiliary space without hash maps.
* **[Problem 19: Convert Sorted Array to Binary Search Tree](binary_search_tree/convert_sorted_array_to_bst.md)** ([C++ Code](binary_search_tree/convert_sorted_array_to_bst.cpp)): Divide-and-conquer middle element root assignment guaranteeing height balance.
* **[Problem 20: Delete Node in a BST](binary_search_tree/delete_node_in_a_bst.md)** ([C++ Code](binary_search_tree/delete_node_in_a_bst.cpp)): The 3 fundamental deletion cases (leaf, single child, two children using in-order successor overwrite).

---

## 6. Tree Construction & Serialization
*Focus: Preserving and reconstructing tree shapes from linear sequences and in-place transformations.*

* **[Problem 21: Construct Binary Tree from Preorder and Inorder Traversal](construction_and_serialization/construct_binary_tree_from_preorder_and_inorder.md)** ([C++ Code](construction_and_serialization/construct_binary_tree_from_preorder_and_inorder.cpp)): Preorder root selection + $O(1)$ Inorder boundary partitioning with hash maps.
* **[Problem 22: Serialize and Deserialize Binary Tree](construction_and_serialization/serialize_and_deserialize_binary_tree.md)** ([C++ Code](construction_and_serialization/serialize_and_deserialize_binary_tree.cpp)): Preorder DFS with null delimiters (`#`) and stringstream reconstruction.
* **[Problem 23: Flatten Binary Tree to Linked List](construction_and_serialization/flatten_binary_tree_to_linked_list.md)** ([C++ Code](construction_and_serialization/flatten_binary_tree_to_linked_list.cpp)): In-place flattening using Morris-style rightmost splicing in $O(1)$ auxiliary space.

---

## 7. Tree DP & Radial Distance Queries
*Focus: Converting tree hierarchies into bidirectional graphs and dual-choice dynamic programming.*

* **[Problem 24: All Nodes Distance K in Binary Tree](tree_dp_and_distances/all_nodes_distance_k_in_binary_tree.md)** ([C++ Code](tree_dp_and_distances/all_nodes_distance_k_in_binary_tree.cpp)): Parent pointer mapping followed by radial breadth-first search from the target node.
* **[Problem 25: House Robber III](tree_dp_and_distances/house_robber_iii.md)** ([C++ Code](tree_dp_and_distances/house_robber_iii.cpp)): State-pair tree DP returning `{rob_curr, skip_curr}` to resolve adjacency theft constraints without overlapping subproblems.

