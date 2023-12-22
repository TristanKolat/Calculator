// Num_Command.h
//
// The `Num_Command` class inherits from `Expr_Command` and represents the encapsulation
// of a numerical operand within a calculator expression.
#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"

class Num_Command : public Expr_Command {
public:

    /**
     * Constructor initializes the numeric command with the value to be pushed onto the stack.
     * @param s A reference to the Stack<int> which the command will manipulate.
     * @param num The integer number that this command represents.
    */
    Num_Command(Stack<int> & s, int n);    
    virtual void execute();

    /**
         * Retrieve the precedence level for the number command.
         *  @return Integer representing the fixed precedence level of number, which is 0.
        */
        int precedence() const;

    /**
     * Handle the placement of the number command within an infix to postfix conversion.
     * Since numbers do not participate in operator precedence, this method simply adds
     * the number command to the postfix array without manipulating the operator stack.
    */
    virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);


private:
    Stack<int> & s_;
    int n_;
};

#endif // _NUM_COMMAND_H_

