#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "iostream"

using std::string;
using std::cout;
using std::endl;

class Weapon
{
	private:
		string	type;
	public:
		Weapon();
		Weapon(string w);
		void setType(string w);
		const string& getType();
};

#endif