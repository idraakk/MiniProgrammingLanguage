### **Lexer.h queue**

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

**Program1.txt**

x = 10;

y = x + 5;

print(y);

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

x = 5;

if (x > 0) {

print(x);

} else {

print(0);

}

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

x = 0;

while (x < 5) {

print(x);

x = x + 1;

}

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

x = 5;

while (x > 0) {

if (x % 2 == 0) {

print(x);

} else {

print(-x);

}

x = x - 1;

}

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

x = 10;

y = 0;

while (x > 0) {

y = y + x;

x = x - 1;

}

print(y);

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
