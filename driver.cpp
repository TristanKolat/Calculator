#include "Array.h"
#include "Stack.h"
#include "Array_Iterator.h"
#include "Infix_To_Postfix.h"
#include "Stack_Expr_Command_Factory.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    std::string infix;

    // Loop until the user enters "QUIT"
    while (true) {
        std::cout << "Enter an infix expression (with spaces between each token)\n\n--Type QUIT to exit--\n\n";
        std::getline(std::cin, infix); // Read the full line including spaces

        // Check if the user wants to quit the program
        if (infix == "QUIT") {
            break;
        }

        // Create a stack to be used in the factory & evaluation
        Stack<int> result;

        // Create a command factory
        // use stack for construction
        Stack_Expr_Command_Factory command_factory(result);

        // Array to hold the postfix commands created from factory
        Array<Expr_Command*> postfix;

        // Instantiate Infix_To_Postfix object for string conversion
        Infix_To_Postfix<std::string> convrtInfix;

        // Convert the infix expression to postfix
        // convert() passes a infix and a reference to factory & postfix
        // so a string infix goes through the factory and the product is an array of commands
        // infix -> factory -> command array
        if (convrtInfix.convert(infix, command_factory, postfix)) {
            //iterate through command array
            for (Array_Iterator<Expr_Command*> iter(postfix); !iter.is_done(); iter.advance()) {
                // Execute the commands in the postfix array.
                (*iter)->execute();
            }

            // Output the result of the evaluation.
            if (!result.is_empty()) {
                std::cout << "The result of the expression is: " << result.top() << std::endl << std::endl;
            } 
            else {
                std::cerr << "The stack is empty after evaluation, which should not happen." << std::endl;
            }
        } 
        else {
            std::cerr << "There was an error converting the infix expression to postfix." << std::endl;
        }
    }

    return 0; // Successful execution.
}




