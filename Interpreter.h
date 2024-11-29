#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Parser.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <stdexcept>

class Interpreter {
private:
    ASTNode* root;
    std::unordered_map<std::string, int> variables;

    int visit(ASTNode* node) {
        switch (node->type) {
            case N_NUMBER:
                return static_cast<NumberNode*>(node)->value;
            case N_VARIABLE:
                return visitVariableNode(static_cast<VariableNode*>(node));
            case N_BIN_OP:
                return visitBinOpNode(static_cast<BinOpNode*>(node));
            case N_ASSIGN:
                return visitAssignNode(static_cast<AssignNode*>(node));
            case N_PRINT:
                return visitPrintNode(static_cast<PrintNode*>(node));
            case N_IF:
                return visitIfNode(static_cast<IfNode*>(node));
            case N_WHILE:
                return visitWhileNode(static_cast<WhileNode*>(node));
            case N_BLOCK:
                return visitBlockNode(static_cast<BlockNode*>(node));
            default:
                throw std::runtime_error("Unknown node type at line " + std::to_string(node->lineNumber));
        }
    }

    int visitVariableNode(VariableNode* node) {
        const std::string& varName = node->name;
        if (variables.find(varName) == variables.end())
            throw std::runtime_error("Undefined variable '" + varName + "' at line " + std::to_string(node->lineNumber));
        return variables[varName];
    }

    int visitBinOpNode(BinOpNode* node) {
        int left = visit(node->left);
        int right = visit(node->right);
        const std::string& op = node->op;
        if (op == "+") return left + right;
        if (op == "-") return left - right;
        if (op == "*") return left * right;
        if (op == "/") {
            if (right == 0)
                throw std::runtime_error("Division by zero at line " + std::to_string(node->lineNumber));
            return left / right;
        }
        if (op == "%") {
            if (right == 0)
                throw std::runtime_error("Modulo by zero at line " + std::to_string(node->lineNumber));
            return left % right;
        }
        if (op == "==") return left == right;
        if (op == "!=") return left != right;
        if (op == "<") return left < right;
        if (op == "<=") return left <= right;
        if (op == ">") return left > right;
        if (op == ">=") return left >= right;
        if (op == "!") return !right;
        throw std::runtime_error("Unknown operator '" + op + "' at line " + std::to_string(node->lineNumber));
    }

    int visitAssignNode(AssignNode* node) {
        int value = visit(node->value);
        variables[node->name] = value;
        return value;
    }

    int visitPrintNode(PrintNode* node) {
        int value = visit(node->expression);
        std::cout << value << std::endl;
        return value;
    }

    int visitIfNode(IfNode* node) {
        int condition = visit(node->condition);
        if (condition) {
            visit(node->trueBlock);
        } else if (node->falseBlock) {
            visit(node->falseBlock);
        }
        return 0;
    }

    int visitWhileNode(WhileNode* node) {
        while (visit(node->condition)) {
            visit(node->block);
        }
        return 0;
    }

    int visitBlockNode(BlockNode* node) {
        // Implement variable scoping if needed
        for (ASTNode* stmt : node->statements) {
            visit(stmt);
        }
        return 0;
    }

public:
    Interpreter(ASTNode* root) : root(root) {}

    void interpret() {
        visit(root);
    }
};

#endif // INTERPRETER_H
