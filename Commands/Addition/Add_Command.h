// Add_Command.h
//
// The `Add_Command` class extends `Expr_Command` to represent an addition operation
// in a calculator expression. This class encapsulates the action of adding two
// numbers and follows the Command Pattern to allow operations to be represented
// as objects.

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "../Interface/Expr_Command.h"

class Add_Command : public Expr_Command {
    public:
        Add_Command(Stack<int>& s);

         /**
          * Execute the addition command.
          *  Performs the addition of the two topmost elements on the stack, pushes the
          *  result back on the stack, and handles any potential arithmetic errors that
          *  might occur during the operation.
          * 
          * @throws std::exception If there are not enough elements on the stack or if an arithmetic overflow occurs.
        */
        virtual void execute(void);

        /**
         * Retrieve the precedence level for the addition command.
         * @return Integer representing the fixed precedence level of addition, which is 1
        */
        virtual int precedence(void) const;

         /**
         * Handle the precedence and stack operations for the addition command within an infix to postfix conversion.
         * This method ensures that commands with higher or equal precedence are popped from the stack and added
         * to the postfix array before pushing the current command onto the stack. It encapsulates the infix to postfix
         * conversion logic specific to the addition command, following the Command Pattern to defer execution.
         * 
         * @param oper The operator stack to manipulate, which may contain other Expr_Command objects.
         * @param postfix The postfix array where the converted postfix expression is being constructed.
        */
        virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);

    private:
        Stack<int>& s_;
};

#endif // _ADD_COMMAND_H_