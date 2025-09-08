#ifndef SED_H
# define SED_H

#include <iostream>
#include <string>
#include <fstream>

class	Sed
{
	private:
		std::string		filename;
		std::string		outfile;
		std::string		s1;
		std::string		s2;
	
	public:
		Sed(const std::string& file, const std::string& getS1, const std::string& getS2);
		~Sed();	
		
		void	Replace(void);
};

#endif
