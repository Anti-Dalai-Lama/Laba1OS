// Laba1OS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>


int _tmain(int argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, _T("Russian"));
	int result = sizeof(TCHAR);
	if (result == 2)
		printf("%s", "UNICODE\n");
	else
		printf("%s", "ANSI\n");

	TCHAR * Names[] = { _T("Васильев Дмитрий Геннадиевич"), _T("Журавок Михаил Геннадиевич"), _T("Васильева Татьяна Михайловна"), _T("Журавок Елена Владимировна") };
	printf("sizeof(names): %d\n", sizeof(Names));
	printf("sizeof(names[0]): %d\n", sizeof(Names[0]));
	printf("Кол-во элементов в массиве: %d\n", sizeof(Names) / sizeof(Names[0]));
	for (int i = 0; i < sizeof(Names) / sizeof(Names[0]); i++)
		/*_tprintf("%c\n", Names[i]);*/


}