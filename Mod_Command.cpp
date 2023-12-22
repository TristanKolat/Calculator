#include "Mod_Command.h"

Mod_Command::Mod_Command(Stack<int>& s) : s_(s) {}

// Executes the modulus operation on the stack provided during construction.
void Mod_Command::execute() {
    int n2 = s_.peekPop();
    int n1 = s_.peekPop();

    //push the modulus result onto the stack
    s_.push(n1 % n2);
}

int Mod_Command::precedence() const {
        return 3;
}

void Mod_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    while (!oper.is_empty() && oper.top()->precedence() >= this->precedence()) {
        postfix.push_back(oper.peekPop());
    }
    oper.push(this);
}