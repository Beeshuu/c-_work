// Postfix.cpp
// CSCI 235 -- Exercise 8: Shunting-Yard Trace
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.
// You may add your own helper functions here, but do not change the
// signatures of the four required functions.

#include "Postfix.hpp"

#include <cctype>
#include <cstddef>
#include <stack>
#include <stdexcept>

// ---- Provided helpers: you may use them, keep them as they are ------------
static bool isOp(const std::string& t) {
    return t == "+" || t == "-" || t == "*" || t == "/";
}

static int prec(const std::string& op) {
    if (op == "*" || op == "/") { return 2; }
    return 1;                                  // "+" and "-"
}

// Task A
std::vector<std::string> tokenize(const std::string& text) {
    // TODO: walk through text with an index.
    //   * skip a space;
    //   * if you see a digit, keep reading digits and push the WHOLE number
    //     as one token;
    //   * otherwise push the single character as a token.
    std::vector<std::string> tokens;
    for (size_t i = 0; i < text.size(); i++) {
        if (std::isspace(text[i])) {
            continue;
        } else if (std::isdigit(text[i])) {
            size_t j = i;
            while (j < text.size() && std::isdigit(text[j])) {
                j++;
            }
            tokens.push_back(text.substr(i, j - i));
            i = j - 1;
        } else {
            tokens.push_back(std::string(1, text[i]));
        }
    }
    return tokens;
}

// Task B
double evalPostfix(std::queue<std::string> postfix) {
    // TODO: use a std::stack<double>.
    //   * a number: convert it with std::stod and push it;
    //   * an operator: pop the right operand, then the left operand, apply
    //     the operator, and push the result;
    //   * "/" by zero: throw std::runtime_error("division by zero").
    // When the queue is empty, one value is left: return it.
    std::stack<double> s;
    while (!postfix.empty()) {
        std::string token = postfix.front();
        postfix.pop();
        if (isOp(token)) {
            double right = s.top(); s.pop();
            double left = s.top(); s.pop();
            if (token == "+") {
                s.push(left + right);
            } else if (token == "-") {
                s.push(left - right);
            } else if (token == "*") {
                s.push(left * right);
            } else if (token == "/") {
                if (right == 0) {
                    throw std::runtime_error("division by zero");
                }
                s.push(left / right);    
            }
        } else {
            s.push(std::stod(token));
        }
    }
    return s.top();
}

// Task C
std::queue<std::string> toPostfix(const std::vector<std::string>& tokens) {
    // TODO: an output queue and a std::stack<std::string> of operators.
    //   * a number goes straight to the output;
    //   * an operator: first move to the output every operator on top of the
    //     stack that should leave before it (see prec), then push it;
    //   * "(" is pushed; ")" moves operators to the output until the "(" is
    //     found, and that "(" is discarded;
    //   * at the end, move whatever is left on the stack to the output.
    std::queue<std::string> output;
    std::stack<std::string> ops;
    for (const std::string& token : tokens) {
        if (std::isdigit(token[0])) {
            output.push(token);
        } else if (isOp(token)) {
            while (!ops.empty() && isOp(ops.top()) && prec(ops.top()) >= prec(token)) {
            output.push(ops.top());
            ops.pop();
            }
            ops.push(token);
        } else if (token == "(") {
            ops.push(token);
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != "(") {
                output.push(ops.top());
                ops.pop();
            }
            if (!ops.empty() && ops.top() == "(") {
                ops.pop();
            }
        }
    }
    while (!ops.empty()) {
        output.push(ops.top());
        ops.pop();
    }
    return output;
}

// Task D
double evaluate(const std::string& text) {
    // TODO: three calls, one per earlier task.
    std::vector<std::string> tokens = tokenize(text);
    std::queue<std::string> postfix = toPostfix(tokens);
    return evalPostfix(postfix);
}