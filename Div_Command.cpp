#include "Div_Command.h"

Div_Command::Div_Command(Stack<int>& s) : s_(s) {}

// Executes the division operation on the stack
void Div_Command::execute() {
    int n2 = s_.peekPop();
    int n1 = s_.peekPop();

    // Check for division by zero
    if(n2 == 0) {
        throw std::runtime_error("Divide by zero error.");
    }
    
    s_.push(n1 / n2);
}

int Div_Command::precedence() const {
        return 3;
}

void Div_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    while (!oper.is_empty() && oper.top()->precedence() >= this->precedence()) {
        postfix.push_back(oper.peekPop());
    }
    oper.push(this);
}