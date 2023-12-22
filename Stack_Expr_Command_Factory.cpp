#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack<int>& stack)
    : stack_(stack) 
{}

Num_Command* Stack_Expr_Command_Factory::create_num_command(int num) {
    return new Num_Command(this->stack_, num);
}

Add_Command* Stack_Expr_Command_Factory::create_add_command()  {
    return new Add_Command(this->stack_);
}

Sub_Command* Stack_Expr_Command_Factory::create_sub_command()  {
    return new Sub_Command(this->stack_);
}

Div_Command* Stack_Expr_Command_Factory::create_div_command()  {
    return new Div_Command(this->stack_);
}

Mult_Command* Stack_Expr_Command_Factory::create_mult_command()  {
    return new Mult_Command(this->stack_);
}

Mod_Command* Stack_Expr_Command_Factory::create_mod_command()  {
    return new Mod_Command(this->stack_);
}

Open_Paren_Command* Stack_Expr_Command_Factory::create_open_paren_command()  {
    return new Open_Paren_Command();
}

Close_Paren_Command* Stack_Expr_Command_Factory::create_close_paren_command()  {
    return new Close_Paren_Command();
}

Expr_Command* Stack_Expr_Command_Factory::create_command(const std::string& token) {
    if (token == "+") {
        return this -> create_add_command();
    } 
    else if (token == "-") {
        return this -> create_sub_command();
    } 
    else if (token == "*") {
        return this -> create_mult_command();
    } 
    else if (token == "/") {
        return this -> create_div_command();
    }
    else if (token == "%") {
        return this -> create_mod_command();
    }
    else if (token == "(") {
        return this -> create_open_paren_command();
    }
    else if (token == ")") {
        return this -> create_close_paren_command();
    }
    else if (is_operand(token)) {
        return this -> create_num_command(std::stoi(token));
    }
    // Handle the case where the operator is not recognized
    throw std::invalid_argument("Unrecognized operator: " + token);
}

bool Stack_Expr_Command_Factory::is_operand(const std::string& token) const {
    // Create a string stream from the token
    std::istringstream iss(token);
    int num;
    // Attempt to parse the token as an integer
    iss >> num; 

    // Check if the parsing was successful (iss.fail() is false) 
    // and if the entire token was consumed (iss.eof() is true)
    return !iss.fail() && iss.eof();
}