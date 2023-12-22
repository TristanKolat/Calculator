// Mult_Command.h
//
// The `Mult_Command` class inherits from `Expr_Command` and represents a multiplication
// operation in a calculator expression. 

#ifndef _MULT_COMMAND_H_
#define _MULT_COMMAND_H_

#include "../Interface/Expr_Command.h"

class Mult_Command : public Expr_Command {
    public:
    /**
     * Constructor for the Mult_Command class.
     * Initializes the command with a reference to the stack which will be used in the execute method.
     * @param s A reference to the Stack<int> that this command will use for performing operations.
    */
        Mult_Command(Stack<int>& s);
        virtual void execute(void);
        /**
         * Retrieve the precedence level for the multiplication command.
         *
         * This method is overridden in the Mult_Command class to return a precedence level unique to multiplication operations.
         *
         * @return Integer representing the fixed precedence level of multiplication, which is 2.
        */
        int precedence() const;

        /**
         * Handle the precedence and stack operations for the multiplication command within an infix to postfix conversion.
         * Ensures that commands with higher or equal precedence are popped from the operator stack and added
         * to the postfix array before pushing the current multiplication command onto the stack.
        */
        virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);

    private:
        Stack<int>& s_;
};

#endif // _Mult_COMMAND_H_