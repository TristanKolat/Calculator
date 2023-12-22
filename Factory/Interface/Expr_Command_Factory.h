#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "../../Commands/Interface/Expr_Command.h"
#include "../../Commands/Addition/Add_Command.h"
#include "../../Commands/Subtraction/Sub_Command.h"
#include "../../Commands/Multiplication/Mult_Command.h"
#include "../../Commands/Division/Div_Command.h"
#include "../../Commands/Modulus/Mod_Command.h"
#include "../../Commands/Number/Num_Command.h"
#include "../../Commands/Open_Parenthesis/Open_Paren_Command.h"
#include "../../Commands/Close_Parenthesis/Close_Paren_Command.h"

// Abstract factory interface for creating command objects.
class Expr_Command_Factory {
    public:
        // Virtual destructor ensures derived class destructors are called correctly.
        virtual ~Expr_Command_Factory(void) = 0;

        // Create a command for operators or operands
        virtual Num_Command * create_num_command(int num) = 0;
        virtual Add_Command * create_add_command(void) = 0;
        virtual Sub_Command * create_sub_command(void) = 0;
        virtual Div_Command * create_div_command(void) = 0;
        virtual Mult_Command * create_mult_command(void) = 0;
        virtual Mod_Command * create_mod_command(void) = 0;
        virtual Open_Paren_Command * create_open_paren_command(void) = 0;
        virtual Close_Paren_Command * create_close_paren_command(void) = 0;

        virtual Expr_Command* create_command(const std::string& token) = 0;


    private:
        // Prevent the client from calling the copy construction and assignment for factory in all subclasses

        //idk how to implement this part without having error code saying theres no constructor in the interface
        //Expr_Command_Factory(const Expr_Command_Factory&);
        //const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

// Ensure destructor is defined even for a pure virtual function
inline Expr_Command_Factory::~Expr_Command_Factory() {}

#endif // _EXPR_COMMAND_FACTORY_H_
