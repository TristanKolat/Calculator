#include "Open_Paren_Command.h"

Open_Paren_Command::Open_Paren_Command() 
{}

void Open_Paren_Command::execute() {
    // no operation
}

int Open_Paren_Command::precedence() const {
    return 0;
}

void Open_Paren_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    oper.push(this);
}
