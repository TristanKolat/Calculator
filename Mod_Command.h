// Mod_Command.h
//
// The `Mod_Command` class inherits from `Expr_Command` and represents a modulus
// operation in a calculator expression. This command class handles the modulus
// operation (remainder after division) between two integers.

#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Expr_Command.h"

class Mod_Command : public Expr_Command {
    public:
        /** Constructor initializes the modulus command with a reference to the stack.
        // @param s A reference to the Stack<int> which the command will operate on.
        */
    Mod_Command(Stack<int>& s);
        virtual void execute(void);
        /**
         * Retrieve the precedence level for the multiplication command.         *
         * @return Integer representing the fixed precedence level of multiplication, which is 2.
        */
        int precedence() const;

        /**
         * Handle the precedence and stack operations for the modulus command within an infix to postfix conversion.
         * Ensures that commands with higher or equal precedence are popped from the operator stack and added
         * to the postfix array before pushing the current modulus command onto the stack.
        */
        virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);

    private:
        Stack<int>& s_;
};

#endif // _Mod_COMMAND_H_