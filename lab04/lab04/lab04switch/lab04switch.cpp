#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choose;
	puts("Вы платник или Бесплатник? (1-Платник, 2-Бесплатник)");
	cin >> choose;
	switch (choose)
	{
	case 1: {
		puts("Сколько вы платите за год? (1-7000BYN, 2-6500BYN, 3-5000$");
		cin >> choose;
		switch (choose)
		{
		case 1: puts("Вы обычный студент"); break;
		case 2: puts("Вы хорошо учитесь"); break;
		case 3: puts("Вы иностранец"); break;
		
		default: puts("Некорректный вариант");  break;
		}
		break;
	}
	case 2: {
		puts("Какая у вас стипендия? (1-100BYN, 2-70BYN, 3-120BYN)");
		cin >> choose;
		switch (choose)
		{
		case 1: puts("Вы обычный студент и живёте в копейке"); break;
		case 2: puts("Вы обычный студент и живёте в пятёрке"); break;
		case 3: puts("Вы хорошо учитесь"); break;
		default: puts("Некорректный вариант");  break;
		}
		break;
	}
	default: puts("Некорректный вариант");  break;
	}
	return 0;
}
