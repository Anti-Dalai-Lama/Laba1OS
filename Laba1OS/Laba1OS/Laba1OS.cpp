// Laba1OS.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	TCHAR * Names[] = { _T("�������� ������� �����������"), _T("������� ������ �����������"), _T("��������� ������� ����������"), _T("������� ����� ������������") };
	printf("sizeof(names): %d\n", sizeof(Names));
	printf("sizeof(names[0]): %d\n", sizeof(Names[0]));
	printf("���-�� ��������� � �������: %d\n", sizeof(Names) / sizeof(Names[0]));
	for (int i = 0; i < sizeof(Names) / sizeof(Names[0]); i++)
		/*_tprintf("%c\n", Names[i]);*/


}