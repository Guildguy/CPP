#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <algorithm>

class RPN
{

    private:
        std::stack<int>		numbers_stack;
        const std::string	OPERATORS;

        void    parseExpression(const std::string &expression);
        int     strToInt(const std::string &str) const;

    public:
        //CANONICAL ORTODOXICAL FORM
        RPN();
        RPN(const RPN &other);
        RPN&	operator=(const RPN &other);
        ~RPN();

        // AUX
        int 	process(const std::string &expression);
		void	errMessage(int d_count, int o_count);
};

#endif