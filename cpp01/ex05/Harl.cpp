#include "Harl.hpp"

void Harl::complain(string level)
{
	int	j;
	fpoint fp[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string type[4] = {"1", "2", "3", "4"};

	j = -1;
	while (++j < 5)
		if (type[j] == level)
			break ;
	switch (j)
	{
		case 0:
			cout << endl;
			(this->*fp[0])();
			break ;
		case 1:
			cout << endl;
			(this->*fp[1])();
			break ;
		case 2:
			cout << endl;
			(this->*fp[2])();
			break ;
		case 3:
			cout << endl;
			(this->*fp[3])();
			break ;
		default:
			cout << endl;
			cout << "You can only choosing '1', '2', '3', '4'." << endl;
	}
}

void Harl::debug(void)
{
	cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << endl;
}

void Harl::info(void)
{
	cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim!" << endl;
}

void Harl::warning(void)
{
	cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << endl;
}

void Harl::error(void)
{
	cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << endl;
}
