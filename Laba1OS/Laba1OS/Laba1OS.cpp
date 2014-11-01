// Laba1OS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include "Windows.h"


int _tmain(int argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, _T("Russian"));
	int result = sizeof(TCHAR);
	if (result == 2)
		printf("%s. Size of TCHAR = %d\n", "UNICODE", sizeof(TCHAR));//2 bytes
	else
		printf("%s. Size of TCHAR = %d\n", "ANSI", sizeof(TCHAR)); //1 byte

	char Names[][35] = { "Васильев Дмитрий Геннадьевич", "Журавок Мишаил Мишаилович" }; // 2 строки по 35 символов
	printf("sizeof(char) = %d\n", sizeof(char)); //
	printf("Размер массива = %d, размер элемента массива = %d\n", sizeof(Names), sizeof(Names[0])); //

	for (int i = 0; i < sizeof(Names) / sizeof(Names[0]); i++)
		printf("%s\n", Names[i]);
	wchar_t ChangedNames[sizeof(Names) / sizeof(Names[0])][35];
	for (int i = 0; i < sizeof(Names) / sizeof(Names[0]); i++)
	{
		MultiByteToWideChar(CP_ACP, 0, Names[i], sizeof(Names[i]), ChangedNames[i], sizeof(Names[i]) * 2);
	}
	printf("Размер массива = %d, размер элемента массива = %d\n", sizeof(ChangedNames), sizeof(ChangedNames[0])); //
	printf("Вывод с помощью wprintf():\n");
	for (int i = 0; i < sizeof(ChangedNames) / sizeof(ChangedNames[0]); i++)
		wprintf(L"%s\n", ChangedNames[i]);
	printf("Вывод с помощью _tprintf():\n");
	for (int i = 0; i < sizeof(ChangedNames) / sizeof(ChangedNames[0]); i++)
		_tprintf(_T("%s\n"), ChangedNames[i]);
	for (int i = 0; i < sizeof(ChangedNames) / sizeof(ChangedNames[0]); i++)
		//MessageBoxW(0, ChangedNames[i], L"Test", MB_OK);//работает с 2 кодировками
		MessageBox(0, ChangedNames[i], _T("Test"), MB_OK); //только в Unicode, в ANSI ошибка ((LPCSTR)ChangedNames[i]), но отобразится некорректно
	//Сделано все до 8 задания
	return 0;
}