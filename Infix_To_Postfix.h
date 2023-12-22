/**
 * @brief Infix_To_Postfix
 *        Tristan Kolat
 * 
 *  Each command inherently returns its precedence level, 
 *  when the precidence() function is called the command returns its precidence value as an int 
 *  The hierarchy of precedence is as follows:
 *
 *                      Parentheses:    0
 *                      Numbers:        1
 *                      Add/Subtract:   2
 *                      Mult/Div/Mod:   3
 *
 *  This precedence system encapsulates the management of the operator stack 
 *  during the conversion from infix to postfix notation. 
 *  eliminating the need for extensive conditional logic. 
 *
 *   I also have extended the command pattern to include parenthesis commands, 
 *   further encapsulating the handling of the operator stack during the evaluation process. 
 *  
 *   I added a virtual function `handle_stack` in each command class allows for an automated, precedence-based sorting of the stack.
 * 
 *   The Factory was also changed to add a create_command class that was used in the infix to postfix but is now encapsulated in the factory.
 *   It allows for less logical checks as any token is sent into the factory. where it is the factoriees job to a figure out what the token is and make a command for it
*/

#ifndef _INFIX_TO_POSTFIX_H_
#define _INFIX_TO_POSTFIX_H_

#include "Array/Array.h"
#include "Stack/Stack.h"
#include "Iterator/Array/Array_Iterator.h"
#include "Stack_Expr_Command_Factory.h"
#include "Commands/Interface/Expr_Command.h"

/**
 * @class Infix_To_Postfix
 *
 * Converts infix expressions to postfix expressions 
 * It supports expressions with operators, parentheses, and integers. 
 * All tokens in an expression must be separated by spaces.
 */
template <typename T>
class Infix_To_Postfix {
public:
    /**
     * Default constructor.
     */
    Infix_To_Postfix();

    /**
     * Destructor.
     */
    virtual ~Infix_To_Postfix();

    /**
     * Converts an infix expression to a postfix expression.
     * 
     * @param[in]   infix   The string representing the infix expression.
     * @param[in]   factory   The factory for making commands
     * @param[in]   postfix   the array for the postfix
     * @return      An Array containing the tokens of the postfix expression.
     */
    bool convert(const std::string &infix,
                 Stack_Expr_Command_Factory &factory,
                 Array<Expr_Command *> &postfix);

private:
    /**
     * Splits the input expression into tokens.
     * 
     * @param[in]   expression  The expression to be tokenized.
     * @return      An Array of tokens.
     */
    Array<T> tokenize(const std::string& expression) const;    
};

#include "Infix_To_Postfix.cpp"
#endif // _INFIX_TO_POSTFIX_H_





