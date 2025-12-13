#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>


class	BitcoinExchange
{
	private:
		const std::string L_DATE;
		const std::string H_DATE;

		std::map<std::string, float> exchange_rates;

		float                           findExchangeRate(const std::string &date) const;
		std::map<std::string, float>    parseDataFile(const std::string &arg) const;
		bool                            isDateValid(const std::string &date) const;
		bool                            isValueValid(const std::string &value, bool check_limits) const;
		int                             getFebruaryDays(int year) const;
		float                           strToFloat(const std::string &str) const;
		void                            printBadInputMessage(const std::string &msg, const std::string &error) const;
	public:
    	//CANONNICAL ORTODOXICAL FORM
    	BitcoinExchange();
    	BitcoinExchange(std::string data_file);
    	BitcoinExchange(const BitcoinExchange& copy);
    	~BitcoinExchange();
    	BitcoinExchange&	operator=(const BitcoinExchange& exchange);

    	//AUX
    	void    BtcExchange(std::ifstream& file);
};

#endif