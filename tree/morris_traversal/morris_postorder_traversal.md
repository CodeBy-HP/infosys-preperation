

### Morris Postorder Traversal (The Mirror + Reverse Trick)

True **Postorder** (`Left → Right → Root`) cannot be collected directly in one forward pass because after finishing `curr->right`, there is no thread pointing back up to `curr`.

However, remember the exact same symmetry you noticed earlier with tree reconstruction:

* **Standard Postorder:** `Left → Right → Root`
* **Reversed Postorder:** `Root → Right → Left`

`Root → Right → Left` is just **Mirrored Preorder**! You run the exact same Morris Preorder algorithm, except you swap `left` and `right` everywhere (finding the **leftmost** node of `curr->right` and threading `prev->left = curr`), and then call `reverse()` on the output array at the very end.

