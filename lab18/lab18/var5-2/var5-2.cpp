#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	FILE* F1;
	FILE* F2;
	int k, i = 0;
	char str[255];
	errno_t err, err1, err2, err3;
	err = fopen_s(&F1, "f1.txt", "w");
	for (int i = 0; i < 6; i++)
	{
		printf("введите строку %d : \n", i + 1);
		gets_s(str);
		fputs(str, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	err1 = fopen_s(&F1, "f1.txt", "r");
	err2 = fopen_s(&F2, "f2.txt", "w");

	for (int i = 0; i < 10 && fgets(str, 255, F1) != NULL; i++)
	{
		if ( str[0] == 'A')
			fputs(str, F2);
	}
	fclose(F1);
	fclose(F2);
}
