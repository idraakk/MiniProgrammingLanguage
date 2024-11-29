Mini Compiler
=============

Overview
--------

Mini Compiler is a simplified interpreter designed to process and execute source code files containing basic programming constructs. It supports variable assignments, arithmetic and logical expressions, control flow statements (if-else and while loops), and print statements. This project serves as an educational tool to understand the fundamental components of a compiler, including lexical analysis, parsing, and interpretation.

Features
--------

-   Variable Assignment: Define variables and assign integer values.\
    Example: x = 10;

-   Arithmetic and Logical Expressions:\
    Supported operators:

-   Arithmetic: +, -, *, /, %

-   Relational: <, <=, >, >=, ==, !=

-   Logical: !\
    Example: y = x + 5;

-   Print Statements: Output the result of an expression to the console.\
    Example: print(x);

-   if-else Statements: Execute code blocks conditionally based on logical expressions.\
    Example:
    ```cpp
    if (x > 0) {
        print(x);
    } else {
        print(0);
    }
    ```

-   while Loops: Repeat execution of a code block as long as a condition holds true.\
    Example:
  ```cpp
     while (x < 5) {
         print(x);
         x = x + 1;
     }
  ```

File Structure
--------------

.

    ├── main.cpp             # Entry point of the compiler

    ├── Lexer.h              # Handles lexical analysis

    ├── Queue.h              # Simple queue implementation for tokens

    ├── Parser.h             # Parses tokens and builds the AST

    ├── Interpreter.h        # Interprets and executes the AST

    ├── sample_programs

        ├── program1.txt         # Sample Program 1: Variable Assignment and Expression

        ├── program2.txt         # Sample Program 2: If-Else Statement

        ├── program3.txt         # Sample Program 3: While Loop

        ├── program4.txt         # Sample Program 4: Nested If-Else and While Loop

        ├── program5.txt         # Sample Program 5: Summation Using Loops

    └── README.md            # Project Documentation

Installation
------------

### Prerequisites

-   C++ Compiler: Ensure you have a C++ compiler installed (e.g., g++).

-   C++11 Standard: The project uses C++11 features. Make sure your compiler supports it.

### Steps

Clone the Repository
    ```bash
    git clone https://github.com/yourusername/mini-compiler.git
    cd mini-compiler
    ```

1.  Compile the Project
    ```bash
    g++ -std=c++11 -o mini_compiler main.cpp
    ```

3.  This command compiles main.cpp along with the header files and produces an executable named mini_compiler.

Usage
-----

Run the compiler by providing a source code file as an argument:

```bash
./mini_compiler <source_file>
```

### Example

```bash
./mini_compiler program1.txt
```

Sample Programs
---------------

### Program 1: Variable Assignment and Arithmetic

```cpp
x = 10;
y = x + 5;
print(y);
```

Expected Output:

```
15
```

### Program 2: If-Else Statement

```cpp
x = 5;
if (x > 0) {
    print(x);
} else {
    print(0);
}
```

Expected Output:
```
5
```
### Program 3: While Loop

```cpp
x = 0;
while (x < 5) {
    print(x);
    x = x + 1;
}
```

Expected Output:
```
0

1

2

3

4
```

### Program 4: Nested If-Else and While Loop
```cpp
x = 5;
while (x > 0) {
    if (x % 2 == 0) {
        print(x);
    } else {
        print(-x);
    }
    x = x - 1;
}
```

Expected Output:
```
-5

4

-3

2

-1
```

### Program 5: Summation Using Loops

```cpp
x = 10;
y = 0;
while (x > 0) {
    y = y + x;
    x = x - 1;
}
print(y);
```

Expected Output:
```
55
```

Error Handling
--------------

The compiler detects and reports various errors to help you debug your programs effectively.

### Syntax Errors

Missing Semicolons: Every statement must end with a semicolon (;).\
Example:
```cpp
x = 10
print(x);
```
```
Error: Expected token ';' at line 1.
```
Unmatched Parentheses or Braces: Ensure all opening parentheses/braces have corresponding closing ones.\
Example:
```cpp
if (x > 0) {
    print(x);
```
```
Error: Expected token '}' at end of file.
```

### Runtime Errors

Division by Zero: Attempting to divide by zero will throw an error.\
Example:
```cpp
x = 10 / 0;
print(x);
```
```
Error: Division by zero at line 1.
```

Undefined Variables: Using variables that have not been defined will result in an error.\
Example:
```cpp
print(y);
```
```
Error: Undefined variable 'y' at line 1.
```

Modulo by Zero: Using the modulo operator with zero as the divisor.\
Example:
```cpp
x = 10 % 0;
print(x);
```
```
Error: Modulo by zero at line 1.
```

Contributing
------------

Contributions are welcome! If you have suggestions for improvements or want to add new features, feel free to create an issue or submit a pull request.

### Steps to Contribute

1.  Fork the Repository
    Click the "Fork" button at the top-right corner of the repository page.

2.  Clone Your Fork
    ```bash
    git clone https://github.com/yourusername/mini-compiler.git
    ```
    ```bash
    cd mini-compiler
    ```

1.  Create a New Branch
    ```bash
    git checkout -b feature-name
    ```

3.  Make Your Changes
    Edit the codebase to add your feature or fix bugs.

4.  Commit Your Changes
    ```bash
    git add .
    ```
    ```bash
    git commit -m "Description of your changes"
    ```

1.  Push to Your Fork
    ```bash
    git push origin feature-name
    ```

3.  Create a Pull Request
    ```bash
    Navigate to the original repository and click "Compare & pull request" to submit your changes.
    ```
