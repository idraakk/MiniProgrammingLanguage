#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <cctype>
#include <stdexcept>
#include "Queue.h"

// Token types
enum TokenType {
    T_IDENTIFIER,
    T_NUMBER,
    T_OPERATOR,
    T_ASSIGN,
    T_SEMICOLON,
    T_LPAREN,
    T_RPAREN,
    T_LBRACE,
    T_RBRACE,
    T_IF,
    T_ELSE,
    T_WHILE,
    T_PRINT,
    T_EOF,
    T_UNKNOWN
};

// Token structure
struct Token {
    TokenType type;
    std::string value;
    int lineNumber;
};

class Lexer {
private:
    std::string input;
    size_t pos;
    char currentChar;
    int lineNumber;

    void advance() {
        if (currentChar == '\n')
            lineNumber++;
        pos++;
        if (pos < input.length())
            currentChar = input[pos];
        else
            currentChar = '\0';
    }

    void skipWhitespace() {
        while (currentChar != '\0' && isspace(currentChar))
            advance();
    }

    Token identifier() {
        std::string result;
        while (currentChar != '\0' && (isalnum(currentChar) || currentChar == '_')) {
            result += currentChar;
            advance();
        }
        if (result == "if")
            return Token{T_IF, result, lineNumber};
        else if (result == "else")
            return Token{T_ELSE, result, lineNumber};
        else if (result == "while")
            return Token{T_WHILE, result, lineNumber};
        else if (result == "print")
            return Token{T_PRINT, result, lineNumber};
        else
            return Token{T_IDENTIFIER, result, lineNumber};
    }

    Token number() {
        std::string result;
        while (currentChar != '\0' && isdigit(currentChar)) {
            result += currentChar;
            advance();
        }
        return Token{T_NUMBER, result, lineNumber};
    }

public:
    Lexer(const std::string& input) : input(input), pos(0), lineNumber(1) {
        if (!input.empty())
            currentChar = input[pos];
        else
            currentChar = '\0';
    }

    Queue<Token> generateTokens() {
        Queue<Token> tokens;
        while (currentChar != '\0') {
            if (isspace(currentChar)) {
                skipWhitespace();
                continue;
            }
            if (isalpha(currentChar)) {
                tokens.enqueue(identifier());
                continue;
            }
            if (isdigit(currentChar)) {
                tokens.enqueue(number());
                continue;
            }
            if (currentChar == '+') {
                tokens.enqueue(Token{T_OPERATOR, "+", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '-') {
                tokens.enqueue(Token{T_OPERATOR, "-", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '*') {
                tokens.enqueue(Token{T_OPERATOR, "*", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '/') {
                tokens.enqueue(Token{T_OPERATOR, "/", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '%') {
                tokens.enqueue(Token{T_OPERATOR, "%", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '=') {
                advance();
                if (currentChar == '=') {
                    tokens.enqueue(Token{T_OPERATOR, "==", lineNumber});
                    advance();
                } else {
                    tokens.enqueue(Token{T_ASSIGN, "=", lineNumber});
                }
                continue;
            }
            if (currentChar == '!') {
                advance();
                if (currentChar == '=') {
                    tokens.enqueue(Token{T_OPERATOR, "!=", lineNumber});
                    advance();
                } else {
                    tokens.enqueue(Token{T_OPERATOR, "!", lineNumber});
                }
                continue;
            }
            if (currentChar == '<' || currentChar == '>') {
                char prevChar = currentChar;
                advance();
                if (currentChar == '=') {
                    tokens.enqueue(Token{T_OPERATOR, std::string(1, prevChar) + "=", lineNumber});
                    advance();
                } else {
                    tokens.enqueue(Token{T_OPERATOR, std::string(1, prevChar), lineNumber});
                }
                continue;
            }
            if (currentChar == ';') {
                tokens.enqueue(Token{T_SEMICOLON, ";", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '(') {
                tokens.enqueue(Token{T_LPAREN, "(", lineNumber});
                advance();
                continue;
            }
            if (currentChar == ')') {
                tokens.enqueue(Token{T_RPAREN, ")", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '{') {
                tokens.enqueue(Token{T_LBRACE, "{", lineNumber});
                advance();
                continue;
            }
            if (currentChar == '}') {
                tokens.enqueue(Token{T_RBRACE, "}", lineNumber});
                advance();
                continue;
            }
            // Unknown character
            throw std::runtime_error("Unknown character '" + std::string(1, currentChar) + "' at line " + std::to_string(lineNumber));
        }
        tokens.enqueue(Token{T_EOF, "", lineNumber});
        return tokens;
    }
};

#endif // LEXER_H
