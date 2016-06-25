#include <stdio.h>

int main(){

int i;

for(i=1;i<=40;i++){

if(i%3==0){
	printf("AHO\n");
}
else{
	switch(i){
	case 3:
	printf("AHO\n");
	break;
	case 13:
	printf("AHO\n");
	break;
	case 23:
	printf("AHO\n");
	break;
	case 30:
	printf("AHO\n");
	break;
	case 31:
	printf("AHO\n");
	break;
	case 32:
	printf("AHO\n");
	break;
	case 33:
	printf("AHO\n");
	break;
	case 34:
	printf("AHO\n");
	break;
	case 35:
	printf("AHO\n");
	break;
	case 36:
	printf("AHO\n");
	break;
	case 37:
	printf("AHO\n");
	break;
	case 38:
	printf("AHO\n");
	break;
	case 39:
	printf("AHO\n");
	break;
	default:
	printf("%d\n",i);
	}
}

}

return 0;

}