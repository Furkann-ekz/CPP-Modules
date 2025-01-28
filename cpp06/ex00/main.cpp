#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Usage: ./convert <literal>" << endl;
		return 1;
	}

	Scalar::convert(argv[1]);
	return 0;
}