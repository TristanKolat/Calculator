#include "Sub_Command.h"

Sub_Command::Sub_Command(Stack<int>& s) : s_(s) {}

// Executes the subtraction operation on the stack.
void Sub_Command::execute() {
    int n2 = s_.peekPop();
    int n1 = s_.peekPop();
    //return the subtracted result on the stack
    s_.push(n1 - n2);
}

int Sub_Command::precedence() const {
        return 2;
}

void Sub_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    while (!oper.is_empty() && oper.top()->precedence() >= this->precedence()) {
        postfix.push_back(oper.peekPop());
    }
    oper.push(this);
}