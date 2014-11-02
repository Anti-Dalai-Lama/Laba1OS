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
	char Names[][35] = { "Васильев Дмитрий Геннадьевич", "Иванов Иван Иванович", "Журавок Мишаил Мишаилович", "Васильев Артур Дмитриевич" };
	printf("Размер массива = %d, размер элемента массива = %d\n", sizeof(Names), sizeof(Names[0])); 
	const int CONST1 = sizeof(Names) / sizeof(Names[0]);
	for (int i = 0; i < CONST1; i++)
		printf("%s\n", Names[i]);

	printf("-----------Task 6, 7------------\n");
	wchar_t NamesToUnicode[CONST1][35];
	for (int i = 0; i < CONST1; i++)
	{
		int temp = sizeof(Names[i]); // обьект является локальным и уничтожается при выходе из области видимости 
		MultiByteToWideChar(CP_ACP, 0, Names[i], temp, NamesToUnicode[i], temp * 2);
	}
	/*printf("Размер массива = %d, размер элемента массива = %d\n", sizeof(NamesToUnicode), sizeof(NamesToUnicode[0])); */
	/*printf("Вывод с помощью wprintf():\n");*/
	const int CONST2 = sizeof(NamesToUnicode) / sizeof(NamesToUnicode[0]);
	/*for (int i = 0; i < CONST2; i++)
		wprintf(L"%s\n", NamesToUnicode[i]);*/
	//original_locale();
	//if (original_locale() == "Russian")
	printf("Вывод с помощью _tprintf():\n");
	for (int i = 0; i < CONST2; i++)
		_tprintf(_T("%s\n"), NamesToUnicode[i]);
	for (int i = 0; i < CONST2; i++)
		//MessageBoxW(0, ChangedNames[i], L"Test", MB_OK);//работает с 2 кодировками
		MessageBox(0, NamesToUnicode[i], _T("Имя члена семьи"), MB_OK | MB_ICONINFORMATION); //только в Unicode, в ANSI ошибка ((LPCSTR)ChangedNames[i]), но отобразится некорректно

	printf("-----------Task 8------------\n");
	qsort(NamesToUnicode, CONST2, sizeof(NamesToUnicode[0]), Сompare);

	printf("Вывод с помощью wprintf() отсортированого массива:\n");
	for (int i = 0; i < CONST2; i++)
		wprintf(L"%s\n", NamesToUnicode[i]);

	printf("-----------Task 9, 10------------\n");

	char NamesToAnsi[sizeof(Names) / sizeof(Names[0])][35];
	for (int i = 0; i < CONST2; i++)
	{
		int temp = sizeof(NamesToUnicode[i]);
		WideCharToMultiByte(CP_ACP, 0, NamesToUnicode[i], temp / 2, NamesToAnsi[i], temp, NULL, NULL);
	}
	for (int i = 0; i < CONST2; i++)
		printf("%s\n", NamesToAnsi[i]);
	return 0;

	printf("-------------LAST BOSS---------------\n");
}

int Сompare(const void * a, const void * b) //компаратор
{
	return wcscmp((wchar_t*)a, (wchar_t*)b); //смысл этой строчки я не очень понимаю с точки зрения синтаксиса, но все работает
}

//char *getLocale(void)
//{
//	char* temp, *copy;
//	temp = setlocale(LC_ALL, NULL); // возвращает текущую установку
//	if (temp == NULL)
//		return NULL;
//	copy = (char *)malloc(strlen(temp) + 1);
//	if (copy == NULL) // если память не была выделена
//		return NULL;
//	strncpy(copy, temp, 15);
//	return copy;
//}

FILE *open_input(const char *filename)
{
	FILE *f;
	errno = 0; // поле для записи ошибок
	if (filename == NULL) 
		filename = "\0";
	f = fopen(filename, "a+t");
	if (f == NULL)
		fprintf(stderr,
		"open_input(\"%s\") с ошибкой: %s\n",
		filename, strerror(errno));
	return f;		
}

int closeFile(FILE *f)
{
	int s = 0;
	if (f == NULL)
		return 0; 
	errno = 0;
	s = fclose(f);
	if (s == EOF) perror("Закрытие завершилось ошибкой");
	return s;
}

FILE *fopen_wide(
	const char* filename,
	const char *mode,
	const char *locale)
{
	FILE *f = fopen(filename, mode);
	if (f != NULL)
	{
		char *old_locale = setlocale(LC_CTYPE, locale); // получаем старый регион локализации
		if (old_locale == NULL || fwide(f, 1) <= 0) // либо не назначен регион либо нельзя сделать широкую ориентацию
		{
			fclose(f); // закрываем и обнуляем поток
			f = NULL;
		}
		setlocale(LC_CTYPE, old_locale); // Выставляем регион обратно. Зачем пока не пойму
	}
	return f;
}