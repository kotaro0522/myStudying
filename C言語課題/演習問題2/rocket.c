#include <stdio.h>

int main(){

int i;
double rocket=0.999999;

for(i=1;i<1000000;i++){
	rocket=rocket*0.999999;
}

double rocket2=rocket*100;

printf("�Ƃ��郍�P�b�g��100���̕��i����Ȃ�B\n");
printf("�e���i��99.9999���̊m���Ő��������삷��B\n");
printf("���̃��P�b�g����̕��i�̌̏���Ȃ��m����%f���ł���B\n",rocket2);

return 0;

}
