#include "Num_Command.h"
Num_Command::Num_Command(Stack<int> & s, int n) : s_(s), n_(n) {}

void Num_Command::execute() {
    // Executes the command to push the numeric value onto the stack.
    s_.push(n_);
}

int Num_Command::precedence() const {
        return 1;
}

void Num_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    // Numbers are directly added to the postfix array
    postfix.push_back(this);
}

