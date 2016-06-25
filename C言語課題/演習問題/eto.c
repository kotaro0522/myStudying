#include <stdio.h>
int main(){

	int year;
	int eto;

	year=2013;
	eto=year%12;

//漢字で干支を入れると文字コード的な問題が発生するためひらがなに変更。

	switch(eto){
	case 0:
	printf("%d年はさる年です。\n", year);
	break;
	case 1:
	printf("%d年はとり年です。\n", year);
	break;
	case 2:
	printf("%d年はいぬ年です。\n", year);
	break;
	case 3:
	printf("%d年はいのしし年です。\n", year);
	break;
	case 4:
	printf("%d年はねずみ年です。\n", year);
	break;
	case 5:
	printf("%d年はうし年です。\n", year);
	break;
	case 6:
	printf("%d年はとら年です。\n", year);
	break;
	case 7:
	printf("%d年はうさぎ年です。\n", year);
	break;
	case 8:
	printf("%d年はりゅう年です。\n", year);
	break;
	case 9:
	printf("%d年はへび年です。\n", year);
	break;
	case 10:
	printf("%d年はうま年です。\n", year);
	break;
	case 11:
	printf("%d年はひつじ年です。\n", year);
	break;
	default:
	printf("なんかおかしいです。\n");
	}

	return 0;
}
	