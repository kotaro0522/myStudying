#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
	int i;
	int flag1=0;
	int flag2=0;
	int flag3=0;
	char *s1="Hello";
	char *s2="Whats";
	char *s3="your";
	char *s4="name?";
	char *s5="favorite";
	char *s6="food?";
	
	if(strcmp(s1,argv[1])==0) flag1=1;
	
	if(strcmp(s2,argv[1])==0){
		if(strcmp(s3,argv[2])==0){
			if(strcmp(s4,argv[3])==0) flag2=1;
			else if(strcmp(s5,argv[3])==0){
				if(strcmp(s6,argv[4])==0) flag3=1;
			}
		}
	}
	
	if(flag1) printf("Hello!\n");
	if(flag2) printf("I'm John.\n");
	if(flag3) printf("I love cucumber.\n");
	
	return 0;
}