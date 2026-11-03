# Month to Season Mapping (Control Flow & Range Partitioning)

## Problem Statement

Given an integer input representing a month ($1$ to $12$), determine and return the corresponding season based on the following meteorological calendar mapping:

- **March (3) to May (5):** `Spring`
- **June (6) to August (8):** `Summer`
- **September (9) to November (11):** `Autumn`
- **December (12), January (1), February (2):** `Winter`

### Output Format
- Return the string: `"Season: [Name]"` (e.g., `"Season: Spring"`).
- If the input is outside the valid range $[1, 12]$, return `"Invalid month"`.

---

## Examples

### Example 1
- **Input:** `month = 4`
- **Output:** `"Season: Spring"`

### Example 2
- **Input:** `month = 12`
- **Output:** `"Season: Winter"`

### Example 3
- **Input:** `month = 15`
- **Output:** `"Invalid month"`

---

## Algorithmic Paradigm: Guard Clauses & Interval Partitioning

1. **Guard Clause:** Check boundary validity immediately:
   `if (month < 1 || month > 12) return "Invalid month";`
2. **Cascading Conditions:**
   - `if (month >= 3 && month <= 5) return "Season: Spring";`
   - `if (month >= 6 && month <= 8) return "Season: Summer";`
   - `if (month >= 9 && month <= 11) return "Season: Autumn";`
   - `else return "Season: Winter";` (covers 12, 1, 2 cleanly).

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(1)$ constant-time condition checks |
| **Space Complexity** | $\mathcal{O}(1)$ auxiliary memory |

