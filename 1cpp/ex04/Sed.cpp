#include "Sed.hpp"

Sed::Sed(const std::string& file, const std::string& getS1, const std::string& getS2) : filename(file), s1(getS1), s2(getS2)
{
	this->outfile = this->filename + ".replace";
}

Sed::~Sed() {}

void	Sed::Replace(void)
{
	size_t			position;
	std::string		line;
	std::ifstream	infile(this->filename.c_str());
	
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open input file " << this->filename << std::endl;
		return ;
	}

	std::ofstream	outfile(this->outfile.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not create output file" << this->outfile << std::endl;
		return ;
	}
	while (getline(infile, line))
	{
		position = line.find(this->s1);
		while (position != std::string::npos)
		{
			line.erase(position, this->s1.length());
			line.insert(position, this->s2);
			position = line.find(this->s1, position + this->s2.length());
		}
		outfile << line << std::endl;
	}
}
