#include <stdio.h>

int main(){

  double debt = 100000; //�؋���100000�~�����B
  double r = 1.15; //�N����15%�Ƃ���B

  printf("�ŏ���%f�~�؂肽�B\n", debt); //�ŏ��̎؋��\��
  debt = debt * r;
  printf("1�N�ڂ̎؋���%f�~�B\n", debt); //1�N�ڂ̎؋��\��
  debt = debt * r;
  printf("2�N�ڂ̎؋���%f�~�B\n", debt); //2�N�ڂ̎؋��\��
  debt = debt * r;
  printf("3�N�ڂ̎؋���%f�~�B\n", debt); //3�N�ڂ̎؋��\��
  debt = debt * r;
  printf("4�N�ڂ̎؋���%f�~�B\n", debt); //4�N�ڂ̎؋��\��
  debt = debt * r;
  printf("5�N�ڂ̎؋���%f�~�B\n", debt); //5�N�ڂ̎؋��\��

  return 0;

}
