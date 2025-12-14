#include "RPN.hpp"
 
// CANONICAL ORTODOXICAL FORM
RPN::RPN() : 
numbers_stack(), 
OPERATORS("+-*/")
{}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->numbers_stack = other.numbers_stack;
    return (*this);
}

void	RPN::errMessage(int d_count, int o_count)
{
	 if (d_count == 0 && o_count == 0)
        throw std::invalid_argument("Error: no operands and no operators");
    else if (d_count == 0 && o_count != 0)
        throw std::invalid_argument("Error: no operands");
    else if (d_count != 0 && o_count == 0)
        throw std::invalid_argument("Error: no operators");
    else if (o_count != d_count - 1)
        throw std::invalid_argument("Error: insufficient operands for operator");
}

void	RPN::parseExpression(const std::string &expression)
{
    if (expression.empty())
        throw std::invalid_argument("Error: empty input");

    std::istringstream	iss(expression);
    std::string			token;
    int d_count = 0;
    int o_count = 0;

    while (iss >> token)
	{
        if (token.length() == 1 && isdigit(static_cast<unsigned char>(token[0])))
            d_count++;
        else if (token.length() == 1 && OPERATORS.find(token[0]) != std::string::npos)
            o_count++;
        else if (token.length() > 1) 
            throw std::invalid_argument("Error: invalid number (allowed: 0 to 9)");
        else
            throw std::invalid_argument("Error: invalid character '" + std::string(1,token[0]) + "'");
    }
	errMessage(d_count, o_count);
}

int  RPN::process(const std::string &expression)
{
	while (!numbers_stack.empty())
    	numbers_stack.pop();

    parseExpression(expression);
    
    std::istringstream	iss(expression);
    std::string			token;

    while (iss >> token)
	{
        if (isdigit(token[0]))
            numbers_stack.push(strToInt(token));
        else
		{
            if (numbers_stack.size() < 2)
                throw std::invalid_argument("Error: not enough operands in stack for operator [" + token + "]");
            int	first_num = numbers_stack.top(); numbers_stack.pop();
            int	second_num = numbers_stack.top(); numbers_stack.pop();
            switch (token[0])
			{
                case '+': numbers_stack.push(second_num + first_num);
                    break;
                case '-': numbers_stack.push(second_num - first_num);
                    break;
                case '*': numbers_stack.push(second_num * first_num);
                    break;
                case '/':
                    if (first_num == 0)
                        throw std::invalid_argument("Error: division by zero is not allowed");
                    numbers_stack.push(second_num / first_num);
                    break;
            }
        }
    }
	if (numbers_stack.size() != 1)
    	throw std::invalid_argument("Error: invalid RPN expression");
    return (numbers_stack.top());
}

int	RPN::strToInt(const std::string &str) const
{
    return (std::atoi(str.c_str()));
}
