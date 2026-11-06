# Trees Master Roadmap & Problem Sheet

Welcome to the **Binary Trees & Binary Search Trees** paradigm. While linear structures like arrays and linked lists have a single successor, hierarchical trees branch in multiple directions. 

Mastering trees requires internalizing the fundamental **recursion and traversal archetypes**:
1. **Traversals & Views (Horizontal BFS & Coordinate Projections):** Freezing level widths, alternating directions, and vertical coordinate mapping $(col, row)$.
2. **Bottom-Up DFS (Information Gathering & Synthesis):** Asking children for information first, calculating local arch properties (diameter, balance, path sum), and passing a single branch contribution upward.
3. **Top-Down DFS & Paths (Backtracking & State Passing):** Passing constraints, prefix sums, or path histories downward from parent to child.
4. **Lowest Common Ancestor (LCA):** Post-order scouting bubbling discovered targets to detect convergence points.
5. **Tree DP & Radial Distance Queries:** Transforming hierarchies into radial graphs and dynamic programming states.
6. **Construction & Serialization:** Rebuilding unique trees from linear orderings and in-place transformations.
7. **Morris Traversals ($O(1)$ Space):** Threaded binary tree traversal without recursion or explicit stacks.
8. **Binary Search Trees (BST Invariant):** Exploiting $Left < Node < Right$ for logarithmic search, validation, and in-order operations.

---

## 1. Traversals & Views (Horizontal BFS & Coordinate Projections)
*Focus: Processing trees tier-by-tier, snapshot freezing, alternating directions, and coordinate mapping.*

* **[Introduction to Binary Trees](traversals_and_views/introduction_to_binary_trees.md)**: Tree definitions, types (Full, Complete, Perfect, Balanced, Degenerate), and mathematical invariants ($n_0 = n_2 + 1$, maximum nodes at depth $d$).
* **[Inorder Traversal](traversals_and_views/inorder_traversal.md)** ([C++ Code](traversals_and_views/inorder_traversal.cpp)): Left $\to$ Root $\to$ Right traversal via both recursive DFS and explicit stack.
* **[Preorder Traversal](traversals_and_views/preorder_traversal.md)** ([C++ Code](traversals_and_views/preorder_traversal.cpp)): Root $\to$ Left $\to$ Right traversal via recursion and explicit stack with right-child pre-pushing.
* **[Postorder Traversal](traversals_and_views/postorder_traversal.md)** ([C++ Code](traversals_and_views/postorder_traversal.cpp)): Left $\to$ Right $\to$ Root traversal via recursion, 2-stack reversal, and 1-stack last-visited pointer tracking.
* **[Binary Tree Level Order Traversal](traversals_and_views/binary_tree_level_order_traversal.md)** ([C++ Code](traversals_and_views/binary_tree_level_order_traversal.cpp)): Foundational BFS level-freezing loop (`int levelSize = q.size()`) partitioning nodes strictly by horizontal rows.
* **[Preorder, Inorder, and Postorder in One Traversal](traversals_and_views/all_traversals_in_one.md)** ([C++ Code](traversals_and_views/all_traversals_in_one.cpp)): Single stack with a 3-state machine (`state 1: pre`, `state 2: in`, `state 3: post`) capturing all three orderings in $O(N)$ time.
* **[Binary Tree Zigzag Level Order Traversal](traversals_and_views/binary_tree_zigzag_level_order.md)** ([C++ Code](traversals_and_views/binary_tree_zigzag_level_order.cpp)): Alternating left-to-right and right-to-left placement using direct index mirroring ($O(1)$ reversal overhead).
* **[Boundary Traversal of Binary Tree](traversals_and_views/boundary_traversal.md)** ([C++ Code](traversals_and_views/boundary_traversal.cpp)): Anti-clockwise boundary: root $\to$ left boundary (excl leaves) $\to$ leaves left-to-right $\to$ reverse right boundary.
* **[Vertical Order Traversal](traversals_and_views/vertical_order_traversal.md)** ([C++ Code](traversals_and_views/vertical_order_traversal.cpp)): 2D coordinate assignment `(col, row, val)` with multi-key sorting and column grouping.
* **[Top View of Binary Tree](traversals_and_views/top_view_of_binary_tree.md)** ([C++ Code](traversals_and_views/top_view_of_binary_tree.cpp)): Level-order BFS capturing the topmost node encountered at each vertical column coordinate.
* **[Bottom View of Binary Tree](traversals_and_views/bottom_view_of_binary_tree.md)** ([C++ Code](traversals_and_views/bottom_view_of_binary_tree.cpp)): Level-order BFS with overwrite semantics tracking the lowest node at each vertical column coordinate.
* **[Left and Right View of Binary Tree](traversals_and_views/left_and_right_view.md)** ([C++ Code](traversals_and_views/left_and_right_view.cpp)): First and last nodes visible at each horizontal depth via DFS and level-size BFS.
* **[Maximum Width of Binary Tree](traversals_and_views/maximum_width_of_binary_tree.md)** ([C++ Code](traversals_and_views/maximum_width_of_binary_tree.cpp)): Complete binary tree coordinate indexing with level offset normalization to prevent 64-bit integer overflow.

---

## 2. Bottom-Up DFS (Information Gathering & Structural Properties)
*Focus: Passing subproblem depths/gains upwards while updating global maximums that arch across the root.*

* **[Maximum Depth of Binary Tree](bottom_up_dfs/maximum_depth_of_binary_tree.md)** ([C++ Code](bottom_up_dfs/maximum_depth_of_binary_tree.cpp)): Foundational height recurrence $1 + \max(\text{depth}(L), \text{depth}(R))$.
* **[Check if Two Binary Trees are Identical](bottom_up_dfs/identical_binary_trees.md)** ([C++ Code](bottom_up_dfs/identical_binary_trees.cpp)): Simultaneous structural and value validation across two trees in $O(\min(N, M))$ time.
* **[Balanced Binary Tree](bottom_up_dfs/balanced_binary_tree.md)** ([C++ Code](bottom_up_dfs/balanced_binary_tree.cpp)): Bottom-up short-circuiting with a `-1` error sentinel to verify height balance in $O(N)$ instead of naive $O(N^2)$.
* **[Diameter of Binary Tree](bottom_up_dfs/diameter_of_binary_tree.md)** ([C++ Code](bottom_up_dfs/diameter_of_binary_tree.cpp)): "Pass up height, update arch diameter" calculating longest node-to-node path in $O(N)$ time.
* **[Binary Tree Maximum Path Sum](bottom_up_dfs/binary_tree_maximum_path_sum.md)** ([C++ Code](bottom_up_dfs/binary_tree_maximum_path_sum.cpp)): Flagship hard tree DP: pruning negative branch contributions with $\max(0, \text{gain})$ and updating global arching sum.
* **[Symmetric Binary Tree](bottom_up_dfs/symmetric_binary_tree.md)** ([C++ Code](bottom_up_dfs/symmetric_binary_tree.cpp)): Mirror-image verification ensuring left and right subtrees reflect each other.
* **[Children Sum Property in Binary Tree](bottom_up_dfs/children_sum_property.md)** ([C++ Code](bottom_up_dfs/children_sum_property.cpp)): Validation and two-pass greedy conversion (top-down propagation, bottom-up reassignment).
* **[Count Complete Tree Nodes](bottom_up_dfs/count_nodes_in_complete_binary_tree.md)** ([C++ Code](bottom_up_dfs/count_nodes_in_complete_binary_tree.cpp)): Sub-linear $O(\log^2 N)$ counting exploiting perfect subtree boundaries ($2^h - 1$).

---

## 3. Top-Down DFS & Paths (Backtracking & State Passing)
*Focus: Downward state passing, root-to-leaf paths, running prefix sums, and backtrack vector sanitation.*

* **[Root to Leaf Paths](top_down_dfs_and_paths/root_to_leaf_paths.md)** ([C++ Code](top_down_dfs_and_paths/root_to_leaf_paths.cpp)): Collecting all paths from root to leaves with vector and string formatting using backtracking.
* **[Path Sum](top_down_dfs_and_paths/path_sum.md)** ([C++ Code](top_down_dfs_and_paths/path_sum.cpp)): Target sum deduction stopping strictly at validated leaf nodes (`!node->left && !node->right`).
* **[Path Sum II](top_down_dfs_and_paths/path_sum_ii.md)** ([C++ Code](top_down_dfs_and_paths/path_sum_ii.cpp)): Collecting full path vectors matching target sum with backtrack cleanup.
* **[Path Sum III](top_down_dfs_and_paths/path_sum_iii.md)** ([C++ Code](top_down_dfs_and_paths/path_sum_iii.cpp)): Prefix sum hash map on trees reducing the $O(N^2)$ double DFS down to $O(N)$ single pass.
* **[Sum Root to Leaf Numbers](top_down_dfs_and_paths/sum_root_to_leaf_numbers.md)** ([C++ Code](top_down_dfs_and_paths/sum_root_to_leaf_numbers.cpp)): Base-10 digit accumulation along branches ($\text{sum} \times 10 + \text{val}$).

---

## 4. Lowest Common Ancestor (LCA)
*Focus: Post-order ancestor scouting, split-point discovery, and reducing tree LCA to graph/list topologies.*

* **[Lowest Common Ancestor of a Binary Tree](lowest_common_ancestor/lowest_common_ancestor_binary_tree.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_binary_tree.cpp)): Bottom-up scouting bubbling discovered targets to detect convergence points.
* **[Lowest Common Ancestor of a Binary Search Tree](lowest_common_ancestor/lowest_common_ancestor_bst.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_bst.cpp)): Utilizing BST order property to find the split point in $O(H)$ time and $O(1)$ space.
* **[Lowest Common Ancestor with Parent Pointers](lowest_common_ancestor/lowest_common_ancestor_with_parent_pointers.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_with_parent_pointers.cpp)): Mathematical reduction from tree LCA to intersecting linked lists using two-pointer path equalization.

---

## 5. Tree DP & Radial Distance Queries
*Focus: Converting tree hierarchies into bidirectional graphs, radial BFS, and multi-state dynamic programming.*

* **[All Nodes Distance K in Binary Tree](tree_dp_and_distances/all_nodes_distance_k_in_binary_tree.md)** ([C++ Code](tree_dp_and_distances/all_nodes_distance_k_in_binary_tree.cpp)): Parent pointer mapping followed by radial breadth-first search from the target node.
* **[Minimum Time Taken to Burn Binary Tree](tree_dp_and_distances/minimum_time_to_burn_binary_tree.md)** ([C++ Code](tree_dp_and_distances/minimum_time_to_burn_binary_tree.cpp)): Radial fire propagation using parent mapping and multi-source BFS in $O(N)$ time.
* **[House Robber III](tree_dp_and_distances/house_robber_iii.md)** ([C++ Code](tree_dp_and_distances/house_robber_iii.cpp)): State-pair tree DP returning `{rob_curr, skip_curr}` to resolve adjacency theft constraints.

---

## 6. Construction & Serialization
*Focus: Reconstructing unique tree topologies from traversal pairs and linear sequence conversions.*

* **[Requirements Needed to Construct a Unique Binary Tree](construction_and_serialization/requirements_to_construct_unique_binary_tree.md)**: Proofs of why Inorder is mandatory for arbitrary trees, Catalan enumeration, and the Full Binary Tree exception.
* **[Construct Binary Tree from Preorder and Inorder Traversal](construction_and_serialization/construct_binary_tree_from_preorder_and_inorder.md)** ([C++ Code](construction_and_serialization/construct_binary_tree_from_preorder_and_inorder.cpp)): Preorder root selection + $O(1)$ Inorder boundary partitioning with hash maps.
* **[Construct Binary Tree from Postorder and Inorder Traversal](construction_and_serialization/construct_binary_tree_from_postorder_and_inorder.md)** ([C++ Code](construction_and_serialization/construct_binary_tree_from_postorder_and_inorder.cpp)): Postorder tail root identification + Inorder left/right partitioning in $O(N)$ time.
* **[Serialize and Deserialize Binary Tree](construction_and_serialization/serialize_and_deserialize_binary_tree.md)** ([C++ Code](construction_and_serialization/serialize_and_deserialize_binary_tree.cpp)): Preorder DFS with null delimiters (`#`) and stringstream reconstruction.
* **[Flatten Binary Tree to Linked List](construction_and_serialization/flatten_binary_tree_to_linked_list.md)** ([C++ Code](construction_and_serialization/flatten_binary_tree_to_linked_list.cpp)): In-place flattening using Morris-style rightmost splicing in $O(1)$ auxiliary space.

---

## 7. Constant Space Traversals (Morris Traversal)
*Focus: Threaded binary tree traversal achieving $O(N)$ time and strictly $O(1)$ auxiliary memory.*

* **[Morris Inorder Traversal](morris_traversal/morris_inorder_traversal.md)** ([C++ Code](morris_traversal/morris_inorder_traversal.cpp)): Establishing temporary predecessor threads and visiting nodes during thread removal ($\text{Left} \to \text{Root} \to \text{Right}$).
* **[Morris Preorder Traversal](morris_traversal/morris_preorder_traversal.md)** ([C++ Code](morris_traversal/morris_preorder_traversal.cpp)): Visiting root nodes at thread creation before diving left ($\text{Root} \to \text{Left} \to \text{Right}$) in $O(1)$ space.

---

## 8. Binary Search Trees (BST Invariant & Operations)
*Focus: Strictly ordered subtrees ($Left < Node < Right$), logarithmic search, floor/ceil boundaries, and in-order algorithms.*

### A. Theory and Fundamentals
* **[Introduction to Binary Search Trees](binary_search_tree/introduction_to_bst.md)**: BST definition, mathematical invariants, monotonic in-order property, and $O(H)$ operation complexity analysis.
* **[Search in a Binary Search Tree](binary_search_tree/search_in_bst.md)** ([C++ Code](binary_search_tree/search_in_bst.cpp)): Iterative and recursive logarithmic search pruning half the tree at each comparison in $O(H)$ time and $O(1)$ space.
* **[Floor and Ceil in a BST](binary_search_tree/floor_and_ceil_in_bst.md)** ([C++ Code](binary_search_tree/floor_and_ceil_in_bst.cpp)): Greatest value $\le X$ and smallest value $\ge X$ via directional binary boundary tightening in $O(H)$ time and $O(1)$ space.
* **[Minimum and Maximum in a BST](binary_search_tree/min_and_max_in_bst.md)** ([C++ Code](binary_search_tree/min_and_max_in_bst.cpp)): Navigating along the leftmost and rightmost branches to extract extremal keys in $O(H)$ time.

### B. Core BST Modifications & Invariants
* **[Insert a Node into a BST](binary_search_tree/insert_into_bst.md)** ([C++ Code](binary_search_tree/insert_into_bst.cpp)): Recursive and iterative insertion down to empty leaf slots in $O(H)$ time.
* **[Delete Node in a BST](binary_search_tree/delete_node_in_a_bst.md)** ([C++ Code](binary_search_tree/delete_node_in_a_bst.cpp)): The 3 fundamental deletion cases (leaf, single child, two children using in-order successor overwrite) in $O(H)$ time.
* **[K-th Smallest and Largest in BST](binary_search_tree/kth_smallest_and_largest_in_bst.md)** ([C++ Code](binary_search_tree/kth_smallest_and_largest_in_bst.cpp)): In-order traversal ($k$-th smallest) and reverse in-order traversal ($k$-th largest) with instant early termination.
* **[Validate Binary Search Tree](binary_search_tree/validate_binary_search_tree.md)** ([C++ Code](binary_search_tree/validate_binary_search_tree.cpp)): Top-down range propagation $(low, high)$ vs in-order strictly increasing checks.
* **[Lowest Common Ancestor of a BST](lowest_common_ancestor/lowest_common_ancestor_bst.md)** ([C++ Code](lowest_common_ancestor/lowest_common_ancestor_bst.cpp)): Directional split-point discovery exploiting BST ordering in $O(H)$ time and $O(1)$ space.
* **[Construct BST from Preorder Traversal](binary_search_tree/construct_bst_from_preorder.md)** ([C++ Code](binary_search_tree/construct_bst_from_preorder.cpp)): Single-pass upper-bound propagation reconstructing the unique BST in $O(N)$ time.
* **[Inorder Successor and Predecessor in BST](binary_search_tree/inorder_successor_and_predecessor_in_bst.md)** ([C++ Code](binary_search_tree/inorder_successor_and_predecessor_in_bst.cpp)): Finding the next smaller and next larger node in $O(H)$ time without full tree traversal.

### C. Advanced BST Applications & FAQs
* **[Binary Search Tree Iterator](binary_search_tree/bst_iterator.md)** ([C++ Code](binary_search_tree/bst_iterator.cpp)): Controlled in-order stack traversal yielding amortized $O(1)$ `next()` calls and strictly $O(H)$ auxiliary memory.
* **[Two Sum in a BST](binary_search_tree/two_sum_in_bst.md)** ([C++ Code](binary_search_tree/two_sum_in_bst.cpp)): Dual bidirectional BST Iterators (forward and reverse) running two-pointer inward search in $O(H)$ auxiliary space.
* **[Recover Binary Search Tree (Two Nodes Swapped)](binary_search_tree/recover_bst_two_nodes_swapped.md)** ([C++ Code](binary_search_tree/recover_bst_two_nodes_swapped.cpp)): Identifying adjacent and non-adjacent in-order inversion anomalies and swapping back in $O(N)$ time.
* **[Largest BST in a Binary Tree](binary_search_tree/largest_bst_in_binary_tree.md)** ([C++ Code](binary_search_tree/largest_bst_in_binary_tree.cpp)): Bottom-up post-order tuple synthesis passing `(minNode, maxNode, maxSize)` in $O(N)$ time.
* **[Convert Sorted Array to Binary Search Tree](binary_search_tree/convert_sorted_array_to_bst.md)** ([C++ Code](binary_search_tree/convert_sorted_array_to_bst.cpp)): Divide-and-conquer middle element root assignment guaranteeing height balance.
