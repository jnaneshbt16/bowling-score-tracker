# Bowling Score Tracker (Single Player) - C++

This project is a simple **command-line bowling score tracker** implemented in C++. 
It follows official bowling rules for **scoring**, including handling of **strikes**, **spares**, 
and the special case in the **10th frame**.

---

## Features

-  Validates user input (0–10 pins per roll)
-  Handles spares and strikes, including 10th frame bonus logic
-  Real-time scoring using correct rules
-  Displays **frame-wise scorecard**
-  Runs in any standard C++ compiler

---

## Example Output

Frame 1: Enter first roll (0 to 10): 10 Strike!

Frame 2: Enter first roll (0 to 10): 7 Enter second roll (0 to 3): 3

...

Total score: 187

Frame-wise Score: +--------+--------+--------+--------+--------+--------+--------+--------+
| Frame | 1  | 2  | 3  | 4  | 5  | 6   | 7   | 8   | 9   | 10  | 
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+ 
| Score | 20 | 39 | 55 | 72 | 89 | 108 | 127 | 147 | 165 | 187 | 
+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+


### 1. Compile
g++ -o BowlingGame BowlingGame.cpp

### 2. Run
./BowlingGame


bowling-score-tracker/
├── BowlingGame.cpp       # Main C++ code file
└── README.md         # Project documentation
