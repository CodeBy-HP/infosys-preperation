    
### Problem Statement

A mobile phone uses the traditional keypad layout where multiple letters share the same numeric key. Because of thumb fatigue, a user records only the sequence of key presses instead of the intended message.

Given a string consisting of digits **'2'** to **'9'**, determine the number of different messages that could have produced the given sequence.

### Rules

* Keys **2, 3, 4, 5, 6, and 8** each represent **3 letters**. Therefore, **at most 3 consecutive presses** of these keys can correspond to a single character.


* Keys **7 and 9** each represent **4 letters**. Therefore, **at most 4 consecutive presses** of these keys can correspond to a single character.


* Consecutive identical digits may be grouped into valid key presses in different ways.


* Different groupings correspond to different possible messages.



Return the total number of possible messages **modulo $10^9 + 7$**.

---

### Input Format

* A single string **$S$** consisting of digits from **'2'** to **'9'**.



### Output Format

* Print a single integer representing the number of possible messages modulo **$10^9 + 7$**.



---

### Sample Test Case

* **Sample Input:** `22233`

* **Sample Output:** `8`


---