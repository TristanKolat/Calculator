// Sub_Command.cpp
//
// Implements the `Sub_Command` class defined in `Sub_Command.h`. This class encapsulates a
// subtraction operation as part of a calculator expression

#ifndef _SUB_COMMAND_H_
#define _SUB_COMMAND_H_

#include "Expr_Command.h"

class Sub_Command : public Expr_Command {
    public:

    /**
     * Constructor for the Sub_Command class
     * Initializes the command with a reference to the stack
     * @param s A reference to the Stack<int>
    */
        Sub_Command(Stack<int>& s);
        // Executes the subtraction operation on the stack.
        virtual void execute(void);

        /**
         * Retrieve the precedence level for the subtraction command.
         * @return Integer representing the fixed precedence level of subtraction, which is 1
        */
        virtual int precedence(void) const;

        /**
         * Handle the precedence and stack operations for the subtraction command within an infix to postfix conversion.
         * Ensures that commands with higher or equal precedence are popped from the operator stack and added
         * to the postfix array before pushing the current subtraction command onto the stack.
        */
        virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);
    private:
        Stack<int>& s_;
};

#endif // _Sub_COMMAND_H_