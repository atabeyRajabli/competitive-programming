# Competitive programming

Solutions I wrote in contest to olympiad problems. The original statements are in Azerbaijani, so each file starts with a short English summary of the problem and the idea behind the solution.

- **Codeforces:** [a1abay](https://codeforces.com/profile/a1abay) (max rating 1630, Expert)
- **ICPC South USA Regional 2025:** 1st place out of 96 universities
- **Meta Hacker Cup 2023:** world quarter-finalist
- **Azerbaijan National Olympiad in Informatics:** silver 2024 and 2025, bronze 2023, IOI national team contender 2024

## Azerbaijan Republican Olympiad in Informatics 2024, semifinal

| # | Problem | Idea | Complexity |
|---|---|---|---|
| 1 | [Candies](azerbaijan-olympiad-2024-semifinal/1-candies.cpp) | Implementation: maximize the change left from a single purchase | O(n) |
| 2 | [Lost Pen](azerbaijan-olympiad-2024-semifinal/2-lost-pen.cpp) | n ≤ 2·10⁶ with a **5 MB** memory limit, so one bit per color | O(n) time, n bits |
| 3 | [Build the Array](azerbaijan-olympiad-2024-semifinal/3-build-the-array.cpp) | Fewest range-chmax operations: coordinate compression, segment tree range minimum, greedy merging | O(n log n) |
| 4 | [LCS of k Permutations](azerbaijan-olympiad-2024-semifinal/4-lcs-of-permutations.cpp) | Precedence DAG across all permutations, then the longest path | O(n²k) |

## IOI training camp selection exam, 2023

| Problem | Idea | Complexity |
|---|---|---|
| [Hopping](ioi-camp-selection-2023/hopping.cpp) | Turn the jump limit into a_i = h_i − i·m, keep the longest non-increasing subsequence | O(n log n) |
| [iwin ioi](ioi-camp-selection-2023/iwin-ioi.cpp) | Fibonacci-like string recursion, index into S_n without building it (length ~10¹⁶) | O(n · (r − l)) |
| [Starfall](ioi-camp-selection-2023/starfall.cpp) | Line–circle intersection as a quadratic in time, then a sweep over integer-second intervals | O(n log n) |

## Running

Each file is a standalone C++ program that reads stdin and writes stdout:

```bash
g++ -std=c++17 -O2 -o sol ioi-camp-selection-2023/hopping.cpp
./sol < input.txt
```

All solutions pass the sample tests from their problem statements.
