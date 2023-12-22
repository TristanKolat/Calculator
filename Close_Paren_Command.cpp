#include "Close_Paren_Command.h"

Close_Paren_Command::Close_Paren_Command() 
{}

void Close_Paren_Command::execute() {
    // no operation
}

int Close_Paren_Command::precedence() const {
    return 0;
}

void Close_Paren_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    // Pop the stack until an open parenthesis is encountered (parenthesis are marked as 0 precidence)
    while (!oper.is_empty() && oper.top()->precedence() != 0) {
        postfix.push_back(oper.peekPop());
    }
    if (!oper.is_empty()) {
        oper.pop(); // Pop the open parenthesis itself
    }
}
