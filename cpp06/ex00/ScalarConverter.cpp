
#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <limits>


static bool isDecimalNotation(const std::string &s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.size())
		return false;
	bool seenDigit = false;
	bool seenDot = false;
	for (; i < s.size(); i++)
	{
		const unsigned char ch = static_cast<unsigned char>(s[i]);
		if (std::isdigit(ch)){
			seenDigit = true;
			continue;
		}
		if (s[i] == '.')
		{
			if (seenDot)
				return false;
			seenDot = true;
			continue;
		}
		return false;
	}
	return seenDigit;
}
static bool isNan(double x)
{
	return x != x;
}
static bool isInf(double x)
{
	const double inf = std::numeric_limits<double>::infinity();
	return x == inf || x == -inf;
}
static bool isPseudoLiteral(const std::string &s, double &out)
{
	if (s == "nan" || s == "nanf")
	{
		out = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	if (s == "+inf" || s == "inf" || s == "+inff" || s == "inff")
	{
		out = std::numeric_limits<double>::infinity();
		return true;
	}
	if (s == "-inf" || s == "-inff")
	{
		out = -std::numeric_limits<double>::infinity();
		return true;
	}
	return false;
}
static bool parseNumeric(const std::string &literal, bool &hasTrailingF, double &out)
{
	hasTrailingF = false;
	std::string s = literal;
	if (s.empty())
		return false;
	if (s[s.size() - 1] == 'f' || s[s.size() - 1] == 'F')
	{
		hasTrailingF = true;
		s = s.substr(0, s.size() - 1);
		if (s.empty())
			return false;
	}
	if (!isDecimalNotation(s))
		return false;
	errno = 0;
	char *end = 0;
	out = std::strtod(s.c_str(), &end);
	if (end == s.c_str() || *end != '\0')
		return false;
	// If parsing itself overflowed to +/-inf, treat as invalid input (only pseudo-literals may be inf).
	if (errno == ERANGE && isInf(out))
		return false;
	return true;
}


void ScalarConverter::convert(const std::string &literal)
{
	// 1) Pseudo-literals
	double value = 0.0;
	bool hasTrailingF = false;
	if (isPseudoLiteral(literal, value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (isNan(value) ? "nanf" : (value < 0 ? "-inff" : "+inff")) << std::endl;
		std::cout << "double: " << (isNan(value) ? "nan" : (value < 0 ? "-inf" : "+inf")) << std::endl;
		return;
	}

	// 2) Char literal (common CLI input: a, *, etc. OR actual C++ form: 'a')
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		const char c = literal[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		const char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	// 3) Numeric literals (int/float/double)
	if (!parseNumeric(literal, hasTrailingF, value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// char
	if (isNan(value) || isInf(value) || value < 0.0 || value > 127.0)
		std::cout << "char: impossible" << std::endl;
	else
	{
		const char c = static_cast<char>(static_cast<int>(value));
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// int
	if (isNan(value) || isInf(value) || value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	// float
	if (isNan(value))
		std::cout << "float: nanf" << std::endl;
	else if (isInf(value))
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
	else if (value != 0.0 && std::fabs(value) > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

	// double
	if (isNan(value))
		std::cout << "double: nan" << std::endl;
	else if (isInf(value))
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
	else
		std::cout << "double: " << static_cast<double>(value) << std::endl;
}