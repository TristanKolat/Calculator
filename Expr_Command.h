// Expr_Command.h
//
// Abstract base class for all expression commands. 
// This class follows the Command Pattern to
//  - allow operations to be encapsulated as objects 
//      enabling easy extension and management of operations.

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack/Stack.h"
#include "Array/Array.h"

class Expr_Command {
    public:
    /** Execute the command.
     * 
     * This method must be overridden by derived command classes to perform
     *   their specific operations.
     *
     * @param s The stack to perform the operation on.
     * @throws std::exception If the operation cannot be performed.
    */
    virtual void execute (void) = 0;
    
    /**
     * Retrieve the precedence level of the command.
     *
     * This method must be overridden by derived command classes to perform
     *   their specific operations.
     * 
     * The precedence level is used during the conversion from infix to postfix expression to respect the order of operations.
     *
     * @return Integer representing the precedence level of the command.
    */
    virtual int precedence() const = 0;

    // virtual method to handle the operator stack and postfix
    virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) = 0;

};

#endif   // !_EXPR_COMMAND_H_

