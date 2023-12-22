// Div_Command.h
//
// The `Div_Command` class inherits from `Expr_Command` and represents a division
// operation in a calculator expression. This command class specifically handles
// the division of two integers.

#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Expr_Command.h"

class Div_Command : public Expr_Command {
    public:

        /**
         * Constructor that takes a reference to the Stack to operate on
         * 
         * @param s A reference to a Stack<int>
        */
        Div_Command(Stack<int>& s);

        /**
         * Executes the division operation on the stack that was passed during construction.
         * The result of the division is pushed back onto the stack.
         * 
         * @throws std::exception If the stack does not have enough operands or if a division by zero is attempted.
        */
        virtual void execute(void);

        /**
         * Retrieve the precedence level for the division command.
         * @return Integer representing the fixed precedence level of division, which is 2.
        */
        virtual int precedence(void) const;

        /**
         * Handle the precedence and stack operations for the division command within an infix to postfix conversion.
         * Ensures that commands with higher or equal precedence are popped from the operator stack and added
         * to the postfix array before pushing the current division command onto the stack.
        */
        virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);

    private:
        Stack<int>& s_;
};

#endif // _Div_COMMAND_H_