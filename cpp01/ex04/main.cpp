#include "iostream"
#include "fstream"
#include "string"

using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;
using std::cout;
using std::endl;

int main(int ac, char **av)
{
	string	file;
	string	oldstr;
	string	newstr;
	string	line;
	string	temp;
	size_t	x;
	int		i;

	if (ac < 4)
		return (cout << "Invalid argument. Please use like './<output> <filename> <string 1> <string 2>'" << endl, 1);
	i = -1;
	file = av[1];
	oldstr = av[2];
	newstr = av[3];
	ifstream	infile(file);
	if (!infile.is_open())
		return (cout << "File cannot be opened." << endl, 1);
	while (getline(infile, line))
		temp += line + '\n';
	infile.close();
	ofstream	newfile("newfile");
	if (!(newfile.is_open()))
		return (cout << "File cannot be create." << endl, 1);
	x = 0;
	while ((x = temp.find(oldstr)) != string::npos)
	{
		newfile << temp.substr(0, x);
		newfile << newstr;
		temp = temp.substr(x + oldstr.length());
	}
	newfile << temp;
	newfile.close();
	cout << "Changed succesfully." << endl;
}
