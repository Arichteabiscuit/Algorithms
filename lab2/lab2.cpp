#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "stack.h"
#include "vector.h"

bool is_operator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int apply_operator(const std::string& op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return b == 0 ? throw std::runtime_error("ZERO") : a / b;
    throw std::runtime_error("Unknown operator");
}

std::string evaluate_rpn(const std::string& expression) {
    Stack* stack = stack_create();
    std::istringstream tokens(expression);
    std::string token;

    try {
        while (tokens >> token) {
            if (is_operator(token)) {
                if (stack_empty(stack) || stack_size(stack) < 2) {
                    stack_delete(stack);
                    return "UNDERFLOW";
                }

                int b = stack_get(stack);
                stack_pop(stack);

                int a = stack_get(stack);
                stack_pop(stack);

                int result = apply_operator(token, a, b);
                stack_push(stack, result);
            }
            else {
                int number = std::stoi(token);
                stack_push(stack, number);
            }
        }

        if (stack_size(stack) > 1) {
            stack_delete(stack);
            return "OVERFLOW";
        }

        stack_delete(stack);
        return "OK";
    }
    catch (const std::runtime_error& e) {
        stack_delete(stack);
        return e.what();
    }
}

int main(int argc, char** argv) {
    std::string expression1;
    std::string expression2; 
    if (argc > 1) {
        std::ifstream input(argv[1]);
        if (!input.is_open()) {
            std::cerr << "cant open file: " << argv[1] << '\n';
            return 1;
        }
        input >> expression1;
        input >> expression2;
    }
    else {
        std::cout << "argc <= 1. Please enter two expressions:\n";
        std::cin >> expression1 >> expression2;
    }

    std::cout << "Expression: " << expression1 << "\nResult: " << evaluate_rpn(expression1) << "\n";
    std::cout << "Expression: " << expression2 << "\nResult: " << evaluate_rpn(expression2) << "\n";

    return 0;
}