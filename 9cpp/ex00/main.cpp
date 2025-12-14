#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cerr << "Error: wrong number of arguments." << std::endl;
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }
    
    std::ifstream input_file(av[1]);
    if (!input_file.is_open())
	{
        std::cerr << "Error: failed to open the input file: " << av[1] << std::endl;
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }
    else if (input_file.peek() == EOF)
	{
        std::cerr << "Error: empty file: " << av[1] << std::endl;
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }

    // create object with data file
    BitcoinExchange data = BitcoinExchange("data.csv");
    data.BtcExchange(input_file);

    return (0);
}
