#ifndef _OPEN_PAREN_COMMAND_H_
#define _OPEN_PAREN_COMMAND_H_

#include "../Interface/Expr_Command.h"

// Open_Parenthesis_Command class extends Expr_Command to handle open parenthesis '('
// in an arithmetic expression. This class specifically manages the operator stack
// during infix to postfix conversion, signaling the start of a sub-expression.
class Open_Paren_Command : public Expr_Command {
public:
    Open_Paren_Command();

    /**
     * Executes the command specific to an open parenthesis.
     * In the context of postfix conversion, this operation is a no-op.
     */
    virtual void execute(void);

    /**
     * Retrieves the precedence level for an open parenthesis.
     * Open parentheses have a designated precedence when encountered on the operator stack.
     * @return Integer representing the precedence level.
     */
    virtual int precedence(void) const;

    /**
     * Handles the stack operations for an open parenthesis during infix to postfix conversion.
     * Pushes the open parenthesis command onto the operator stack to denote the start of a new sub-expression.
     * @param oper The operator stack.
     * @param postfix The postfix array being constructed.
     */
    virtual void handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix);
};

#endif // _OPEN_PARENTHESIS_COMMAND_H_
