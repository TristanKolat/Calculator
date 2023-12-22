#include "Infix_To_Postfix.h"

template <typename T>
Infix_To_Postfix<T>::Infix_To_Postfix() {}

template <typename T>
Infix_To_Postfix<T>::~Infix_To_Postfix() {}

template <typename T>
bool Infix_To_Postfix<T>::convert(const std::string & infix, Stack_Expr_Command_Factory & factory, Array<Expr_Command *> & postfix) {
    // Tokenize the infix expression.
    Array<std::string> tokens = this->tokenize(infix);

    // Temporary stack to hold operator commands.
    Stack<Expr_Command *> oper;

    // Iterate over each token to convert infix expression to postfix.
    for (Array_Iterator<std::string> iter(tokens); !iter.is_done(); iter.advance()) {
        std::string token = *iter;
        
        // Use the factory to create the appropriate command based on the token.
        Expr_Command *cmd = factory.create_command(token);
        
        // If a command was created, handle the stack.
        if (cmd) {
            cmd->handle_stack(oper, postfix);
        }
        else {
            throw std::runtime_error("Invalid token encountered");
        }
    }

    // Pop any remaining operator commands from the stack and add to postfix.
    while (!oper.is_empty()) {
        Expr_Command *cmd = oper.peekPop();
        if (cmd) {
            postfix.push_back(cmd);
        }
    }

    return true;
}

template <typename T>
Array<T> Infix_To_Postfix<T>::tokenize(const std::string& expression) const {
    // Stream used for tokenizing the string
    std::istringstream iss(expression);    
    //array to hold tokens
    Array<std::string> tokens;
    // String to hold the individual token while streaming from iss
    std::string token;

    // Extract tokens and add them to the array
    while (iss >> token) {
        tokens.push_back(token); // Add each token to the Array
    }
    // Return the array of tokens
    return tokens;
}

// Explicitly instantiate the Infix_To_Postfix template for std::string usage.
template class Infix_To_Postfix<std::string>;



