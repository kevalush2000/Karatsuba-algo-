README.txt

Karatsuba Multiplication - How to Compile and Run (MinGW64)
===========================================================

This project demonstrates standard and optimized Karatsuba multiplication for large integers using C++.

Project Structure:
------------------
.vscode\src\
    main.cpp
    karatsuba.cpp
    karatsuba.hpp

How to Compile and Run (using MinGW64):
---------------------------------------

1. **Open a terminal** (Command Prompt, PowerShell, or the VS Code terminal).

2. **Navigate to the source directory:**
   Example:
   cd "e:\C++ CODES\Optimizing Karatsuba Multiplication for Embedded Systems A Study on In-Place Recursion and Lazy Computation\.vscode\src"

3. **Compile the code using g++:**
   g++ -std=c++11 main.cpp karatsuba.cpp -o main.exe

   - This will create an executable named `main.exe` in the current directory.

4. **Run the program:**
   On Windows (MinGW64 terminal):
   ./main.exe

   Or simply:
   main.exe

5. **Expected Output:**
   The program will print the results of several Karatsuba multiplication test cases, showing both the standard and optimized results, and timing information.

Requirements:
-------------
- MinGW64 (with g++ in your PATH)
- C++11 or newer

Troubleshooting:
----------------
- If you get a "'g++' is not recognized" error, ensure MinGW64 is installed and its `bin` directory is added to your system PATH.
- If you get compilation errors, make sure all `.cpp` and `.hpp` files are in the same directory and named correctly.

Enjoy!
