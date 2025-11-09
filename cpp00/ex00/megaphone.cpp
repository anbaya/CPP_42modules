#include <iostream>


int main (int ac, char **av)
{
	if (ac > 1) {
		char **input = av + 1;
		while (*input) {
			char *str = *input;
			while (*str) {
				std::cout << (char)(std::toupper(*str));
				str++;
			}
			input++;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}