#ifndef Brain_HPP
# define Brain_HPP

# include "iostream"

using	std::cout;
using	std::endl;
using	std::string;

class Brain
{
	protected:
		string	ideas[100];
	public:
		Brain();
		Brain(Brain const &src);
		Brain &operator=(Brain const &src);
		~Brain();
		void setIdea(int index, string const idea);
		string getIdea(int index) const;
};

#endif