#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::_isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::_applyOperator(int a, int b, const std::string &op) const
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		return a / b;
	}
	throw std::runtime_error("Error: unknown operator");
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (_stack.size())
		_stack.pop();

	while (iss >> token)
	{
		if (_isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(_applyOperator(a, b, token));
		}
		else
		{
			// Validate that the token is a valid number (single digit, 0-9)
			// Numbers used in the operation must be less than 10
			if (token.length() > 1 || !std::isdigit(token[0]))
				throw std::runtime_error("Error");
			_stack.push(token[0] - '0');
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}
