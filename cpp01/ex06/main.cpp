#include "Harl.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}
	Harl harl;

	harl.complain("DEBUG", av[1]);
	harl.complain("INFO", av[1]);
	harl.complain("WARNING", av[1]);
	harl.complain("ERROR", av[1]);
	harl.complain("UNKNOWN", av[1]);

	return 0;
}