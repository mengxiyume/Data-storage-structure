#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<stdio.h>

int main()
{
	int buttonRet = MessageBox(NULL, "Hello", "MessageBox", MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON1);

	switch (buttonRet)
	{
	case IDOK:
		printf("IDOK");
		break;
	case IDCANCEL:
		printf("IDCALCEL");
		break;
	default:
		printf("NULL");
		break;
	}

	return 0;
}