#include <stdio.h>
int main(){

	int year;
	int eto;

	year=2013;
	eto=year%12;

//�����Ŋ��x������ƕ����R�[�h�I�Ȗ�肪�������邽�߂Ђ炪�ȂɕύX�B

	switch(eto){
	case 0:
	printf("%d�N�͂���N�ł��B\n", year);
	break;
	case 1:
	printf("%d�N�͂Ƃ�N�ł��B\n", year);
	break;
	case 2:
	printf("%d�N�͂��ʔN�ł��B\n", year);
	break;
	case 3:
	printf("%d�N�͂��̂����N�ł��B\n", year);
	break;
	case 4:
	printf("%d�N�͂˂��ݔN�ł��B\n", year);
	break;
	case 5:
	printf("%d�N�͂����N�ł��B\n", year);
	break;
	case 6:
	printf("%d�N�͂Ƃ�N�ł��B\n", year);
	break;
	case 7:
	printf("%d�N�͂������N�ł��B\n", year);
	break;
	case 8:
	printf("%d�N�͂�イ�N�ł��B\n", year);
	break;
	case 9:
	printf("%d�N�͂ւєN�ł��B\n", year);
	break;
	case 10:
	printf("%d�N�͂��ܔN�ł��B\n", year);
	break;
	case 11:
	printf("%d�N�͂Ђ��N�ł��B\n", year);
	break;
	default:
	printf("�Ȃ񂩂��������ł��B\n");
	}

	return 0;
}
	