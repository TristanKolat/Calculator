#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "../Interface/Expr_Command_Factory.h"
#include "../../Stack/Stack.h"
#include <string>
#include <sstream>

// This factory is tailored for commands that work with integer values.
class Stack_Expr_Command_Factory : public Expr_Command_Factory {
    public:
        // Constructor accepts a reference to a Stack of integers that the commands will operate on
        Stack_Expr_Command_Factory(Stack<int>& stack);

        // Create a command for operators or operands
        virtual Num_Command * create_num_command(int num);
        virtual Add_Command * create_add_command(void);
        virtual Sub_Command * create_sub_command(void);
        virtual Div_Command * create_div_command(void);
        virtual Mult_Command * create_mult_command(void);
        virtual Mod_Command * create_mod_command(void);
        virtual Open_Paren_Command * create_open_paren_command(void);
        virtual Close_Paren_Command * create_close_paren_command(void);

        virtual Expr_Command* create_command(const std::string& token);
    private:

        /**
         * Determines if the token is a number.
         * 
         * @param[in]   token   The token to be checked.
         * @return      True if the token is a number, false otherwise.
         */
        bool is_operand(const std::string& token) const;

        // Reference to the Stack on which the commands will operate.
        Stack<int>& stack_;
};

#endif // _STACK_EXPR_COMMAND_FACTORY_H_