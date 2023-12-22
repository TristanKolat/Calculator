#include "Mult_Command.h"

Mult_Command::Mult_Command(Stack<int>& s) : s_(s) {}

// Executes the multiplication operation.
void Mult_Command::execute() {
    int n2 = s_.peekPop();
    int n1 = s_.peekPop();

    // Push the result of the multiplication back onto the stack.
    s_.push(n1 * n2);
}

int Mult_Command::precedence() const {
        return 3;
}

void Mult_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    while (!oper.is_empty() && oper.top()->precedence() >= this->precedence()) {
        postfix.push_back(oper.peekPop());
    }
    oper.push(this);
}