#include "Add_Command.h"

//construct the referenced stack
Add_Command::Add_Command(Stack<int>& s) : s_(s) {}

// perform addition of the 2 numbers on top of the stack
void Add_Command::execute() {
    int n2 = s_.peekPop();
    int n1 = s_.peekPop();
    // Push result back onto the stack
    s_.push(n1 + n2);
}

int Add_Command::precedence() const {
        return 2;
}

//push the add command onto the stack but make sure to pop higher or equal precidence and add to array before pushing
void Add_Command::handle_stack(Stack<Expr_Command*>& oper, Array<Expr_Command*>& postfix) {
    while (!oper.is_empty() && oper.top()->precedence() >= this->precedence()) {
        postfix.push_back(oper.peekPop());
    }
    oper.push(this);
}