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
    
## **Some Technical Details**
### **Lexer.h Queue example for token storage**

Lexer.h

[

{T_IDENTIFIER, "x", 1},

{T_ASSIGN, "=", 1},

{T_NUMBER, "10", 1},

{T_SEMICOLON, ";", 1},

{T_IDENTIFIER, "y", 2},

{T_ASSIGN, "=", 2},

{T_IDENTIFIER, "x", 2},

{T_OPERATOR, "+", 2},

{T_NUMBER, "5", 2},

{T_SEMICOLON, ";", 2},

{T_PRINT, "print", 3},

{T_LPAREN, "(", 3},

{T_IDENTIFIER, "y", 3},

{T_RPAREN, ")", 3},

{T_SEMICOLON, ";", 3},

{T_EOF, "", 4}

]

### **Abstract Syntax Tree (AST) Nodes**

| Node Type | Description | Attributes | Example |
|---|---|---|---|
| NumberNode | Represents a numeric literal. | value (int) - The numeric value. lineNumber - Line number in the source code. | NumberNode(value=10, lineNumber=1) |
| VariableNode | Represents a variable in the code. | name (string) - Variable name. lineNumber - Line number in the source code. | VariableNode(name="x", lineNumber=1) |
| BinOpNode | Represents a binary operation (e.g., addition). | left (ASTNode*) - Left operand. op (string) - Operator (e.g., "+"). right (ASTNode*) - Right operand. lineNumber - Line number in the source code. | BinOpNode(left=VariableNode("x"), op="+", right=NumberNode(5), lineNumber=2) |
| AssignNode | Represents an assignment statement. | name (string) - Variable name. value (ASTNode*) - Value being assigned. lineNumber - Line number in the source code. | AssignNode(name="x", value=NumberNode(10), lineNumber=1) |
| PrintNode | Represents a print statement. | expression (ASTNode*) - Expression to print. lineNumber - Line number in the source code. | PrintNode(expression=VariableNode("y"), lineNumber=3) |
| BlockNode | Represents a block of statements. | statements (vector<ASTNode*>) - List of AST nodes within the block. lineNumber - Line number in the source code. | BlockNode(statements=[AssignNode, PrintNode], lineNumber=1) |

** AST example for sample programs
**Program1.txt**
```cpp
x = 10;
y = x + 5;
print(y);
```
BlockNode
├── AssignNode (x = 10)
│   └── NumberNode (10)
├── AssignNode (y = x + 5)
│   └── BinOpNode (+)
│       ├── VariableNode (x)
│       └── NumberNode (5)
└── PrintNode (print y)
└── VariableNode (y)

**Program2.txt**
```cpp
x = 5;
if (x > 0) {
print(x);
} else {
print(0);
}
```
BlockNode

├── AssignNode (x = 5)

│   └── NumberNode (5)

└── IfNode (x > 0)

├── Condition: BinOpNode (>)

│   ├── VariableNode (x)

│   └── NumberNode (0)

├── TrueBlock: PrintNode (print x)

│   └── VariableNode (x)

└── FalseBlock: PrintNode (print 0)

└── NumberNode (0)

**Program3.txt**
```cpp
x = 0;
while (x < 5) {
print(x);
x = x + 1;
}
```

BlockNode

├── AssignNode (x = 0)

│   └── NumberNode (0)

└── WhileNode (x < 5)

├── Condition: BinOpNode (<)

│   ├── VariableNode (x)

│   └── NumberNode (5)

└── BlockNode

├── PrintNode (print x)

│   └── VariableNode (x)

└── AssignNode (x = x + 1)

└── BinOpNode (+)

├── VariableNode (x)

└── NumberNode (1)

**Program4.txt**
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

BlockNode

├── AssignNode (x = 5)

│   └── NumberNode (5)

└── WhileNode (x > 0)

├── Condition: BinOpNode (>)

│   ├── VariableNode (x)

│   └── NumberNode (0)

└── BlockNode

├── IfNode (x % 2 == 0)

│   ├── Condition: BinOpNode (==)

│   │   ├── BinOpNode (%)

│   │   │   ├── VariableNode (x)

│   │   │   └── NumberNode (2)

│   │   └── NumberNode (0)

│   ├── TrueBlock: PrintNode (print x)

│   │   └── VariableNode (x)

│   └── FalseBlock: PrintNode (print -x)

│       └── BinOpNode (-)

│           ├── NumberNode (0)

│           └── VariableNode (x)

└── AssignNode (x = x - 1)

└── BinOpNode (-)

├── VariableNode (x)

└── NumberNode (1)

**Program5.txt**
```cpp
x = 10;
y = 0;
while (x > 0) {
y = y + x;
x = x - 1;
}
print(y);
```


BlockNode

├── AssignNode (x = 10)

│   └── NumberNode (10)

├── AssignNode (y = 0)

│   └── NumberNode (0)

├── WhileNode (x > 0)

│   ├── Condition: BinOpNode (>)

│   │   ├── VariableNode (x)

│   │   └── NumberNode (0)

│   └── BlockNode

│       ├── AssignNode (y = y + x)

│       │   └── BinOpNode (+)

│       │       ├── VariableNode (y)

│       │       └── VariableNode (x)

│       └── AssignNode (x = x - 1)

│           └── BinOpNode (-)

│               ├── VariableNode (x)

│               └── NumberNode (1)

└── PrintNode (print y)

└── VariableNode (y)
