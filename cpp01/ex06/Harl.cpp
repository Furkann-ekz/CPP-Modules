#include "Harl.hpp"

void Harl::complain(string level)
{
	int	j;
	fpoint fp[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string type[8] = {"1", "2", "3", "4", "DEBUG", "INFO", "WARNING", "ERROR"};

	j = -1;
	while (++j < 5)
		if (type[j] == level)
			break ;
	if (j >= 0 && j < 4)
		cout << endl;
	switch (j)
	{
		case 0:
			while (j < 4)
			{
				cout << "[ " << type[j + 4] << " ]" << endl;
				(this->*fp[j])();
				cout << endl;
				j++;
			}
			break ;
		case 1:
			while (j < 4)
			{
				cout << "[ " << type[j + 4] << " ]" << endl;
				(this->*fp[j])();
				cout << endl;
				j++;
			}
			break ;
		case 2:
			while (j < 4)
			{
				cout << "[ " << type[j + 4] << " ]" << endl;
				(this->*fp[j])();
				cout << endl;
				j++;
			}
			break ;
		case 3:
			while (j < 4)
			{
				cout << "[ " << type[j + 4] << " ]" << endl;
				(this->*fp[j])();
				cout << endl;
				j++;
			}
			break ;
		default:
			cout << "\nYou can only choosing '1', '2', '3', '4'.\n" << endl;
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
