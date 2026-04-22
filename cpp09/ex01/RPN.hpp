#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int evaluate(const std::string &expression);

private:
	std::stack<int> _stack;
	bool _isOperator(const std::string &token) const;
	int  _applyOperator(int a, int b, const std::string &op) const;
};

#endif
