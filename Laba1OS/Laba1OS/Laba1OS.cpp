// Laba1OS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include "Windows.h"


int Сompare(const void * a, const void * b);

int _tmain(int argc, _TCHAR* argv[])
{
	printf("-----------Task 1------------\n");
	int result = sizeof(TCHAR);
	if (result == 2)
		printf("%s. Size of TCHAR = %d\n", "UNICODE", sizeof(TCHAR));//2 bytes
	else
		printf("%s. Size of TCHAR = %d\n", "ANSI", sizeof(TCHAR)); //1 byte

	printf("-----------Task 5------------\n");
	_tsetlocale(LC_ALL, _T("Russian"));
	char Names[][35] = { "Васильев Дмитрий Геннадьевич", "Иванов Иван Иванович", "Журавок Мишаил Мишаилович", "Васильев Артур Дмитриевич" }; // 2 строки по 35 символов
	printf("sizeof(char) = %d\n", sizeof(char)); //
	printf("Размер массива = %d, размер элемента массива = %d\n", sizeof(Names), sizeof(Names[0])); //
	const int CONST1 = sizeof(Names) / sizeof(Names[0]);
	for (int i = 0; i < CONST1; i++)
		printf("%s\n", Names[i]);

	printf("-----------Task 6, 7------------\n");
	wchar_t NamesToUnicode[CONST1][35];
	for (int i = 0; i < CONST1; i++)
	{
		MultiByteToWideChar(CP_ACP, 0, Names[i], sizeof(Names[i]), NamesToUnicode[i], sizeof(Names[i]) * 2);
	}
	printf("Размер массива = %d, размер элемента массива = %d\n", sizeof(NamesToUnicode), sizeof(NamesToUnicode[0])); //
	printf("Вывод с помощью wprintf():\n");
	const int CONST2 = sizeof(NamesToUnicode) / sizeof(NamesToUnicode[0]);
	for (int i = 0; i < CONST2; i++)
		wprintf(L"%s\n", NamesToUnicode[i]);
	printf("Вывод с помощью _tprintf():\n");
	for (int i = 0; i < CONST2; i++)
		_tprintf(_T("%s\n"), NamesToUnicode[i]);
	for (int i = 0; i < CONST2; i++)
		//MessageBoxW(0, ChangedNames[i], L"Test", MB_OK);//работает с 2 кодировками
		MessageBox(0, NamesToUnicode[i], _T("Test"), MB_OK); //только в Unicode, в ANSI ошибка ((LPCSTR)ChangedNames[i]), но отобразится некорректно

	printf("-----------Task 8------------\n");
	qsort(NamesToUnicode, CONST2, sizeof(NamesToUnicode[0]), Сompare);
	printf("Вывод с помощью wprintf() отсортированого массива:\n");
	for (int i = 0; i < CONST2; i++)
		wprintf(L"%s\n", NamesToUnicode[i]);

	printf("-----------Task 9, 10------------\n");
	char NamesToAnsi[sizeof(Names) / sizeof(Names[0])][35];
	for (int i = 0; i < CONST2; i++)
	{
		WideCharToMultiByte(CP_ACP, 0, NamesToUnicode[i], sizeof(NamesToUnicode[i]) / 2, NamesToAnsi[i], sizeof(NamesToUnicode[i]), NULL, NULL);
	}
	for (int i = 0; i < CONST2; i++)
		printf("%s\n", NamesToAnsi[i]);
	return 0;
}

int Сompare(const void * a, const void * b) //компаратор
{
	return wcscmp((wchar_t*)a, (wchar_t*)b); //смысл этой строчки я не очень понимаю с точки зрения синтаксиса, но все работает
}