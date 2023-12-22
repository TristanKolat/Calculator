#ifndef _CLOSE_PAREN_COMMAND_H_
#define _CLOSE_PAREN_COMMAND_H_

#include "Expr_Command.h"

// Close_Parenthesis_Command class extends Expr_Command to handle close parenthesis ')'
// in an arithmetic expression. This class specifically manages the operator stack
// during infix to postfix conversion, signaling the end of a sub-expression.
class Close_Paren_Command : public Expr_Command {
public:
    Close_Paren_Command();

    /**
     * Executes the command specific to a close parenthesis.
     * In the context of postfix conversion, this operation is a no-op.
     */
    virtual void execute(void) override;

    /**
     * Retrieves the precedence level for a close parenthesis.
     * Close parentheses do not have a precedence because they trigger the stack to unwind.
     * @return Integer representing the precedence level.
     */
    virtual int precedence(void) const;

    /**
     * Handles the stack operations for a close parenthesis during infix to postfix conversion.
     * Pops commands from the operator stack and adds them to the postfix array until the corresponding
     * open parenthesis command is encountered.
     * @param oper The operator stack.
     * @param postfix The postfix array being constructed.
     */
    virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);
};

#endif // _CLOSE_PARENTHESIS_COMMAND_H_
