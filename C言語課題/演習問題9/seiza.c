#include <stdio.h>

int month, day;

int main(){

  printf("月を入力して下さい：");
  scanf("%d", &month);
  printf("日を入力して下さい：");
  scanf("%d", &day);

  int n = seizaNumber(month,day);
  
  if(n == 1) printf("おひつじ座です。\n"); 
  if(n == 2) printf("ふたご座です。\n"); 
  if(n == 3) printf("おうし座です。\n"); 
  if(n == 4) printf("かに座です。\n"); 
  if(n == 5) printf("しし座です。\n"); 
  if(n == 6) printf("おとめ座です。\n"); 
  if(n == 7) printf("てんびん座です。\n"); 
  if(n == 8) printf("さそり座です。\n"); 
  if(n == 9) printf("いて座です。\n"); 
  if(n == 10) printf("やぎ座です。\n"); 
  if(n == 11) printf("みずがめ座です。\n"); 
  if(n == 12) printf("うお座です。\n"); 

  return 0;
}

