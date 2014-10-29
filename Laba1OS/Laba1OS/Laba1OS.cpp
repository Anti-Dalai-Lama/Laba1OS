// Laba1OS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>


int _tmain(int argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, _T("Russian"));
	int result = sizeof(TCHAR);
	if (result == 2)
		printf("%s. Size of TCHAR = %d\n", "UNICODE", sizeof(TCHAR));//2 bytes
	else
		printf("%s. Size of TCHAR = %d\n", "ANSI", sizeof(TCHAR)); //1 byte

	char * Names[] = { "Васильев Дмитрий Геннадиевич", "Журавок Михаил Геннадиевич", "Васильева Татьяна Михайловна", "Журавок Елена Владимировна" };
	printf("sizeof(names): %d\n", sizeof("Васильев Дмитрий Геннадиевич"));
	printf("sizeof(names[0]): %d\n", sizeof(Names[0]));
	printf("Кол-во элементов в массиве: %d\n", sizeof(Names) / sizeof(Names[0]));
	for (int i = 0; i < sizeof(Names) / sizeof(Names[0]); i++)
		printf("%s\n", Names[i]);
}