#include <stdio.h>

int seizaNumber(int month,int day);

int month,day,n;

int seizaNumber(int month,int day){
	if(month==1){
		if(day>0 && day<21) n=10;
		else if(day>20 && day<32) n=11;
		else n=0;
	}
	else if(month==2){
		if(day>0 && day<19) n=11;
		else if(day>18 && day<29) n=12;
		else n=0;
	}
	else if(month==3){
		if(day>0 && day<21) n=12;
		else if(day>20 && day<32) n=1;
		else n=0;
	}
	else if(month==4){
		if(day>0 && day<20) n=1;
		else if(day>19 && day<31) n=3;
		else n=0;
	}
	else if(month==5){
		if(day>0 && day<21) n=3;
		else if(day>20 && day<32) n=2;
		else n=0;
	}
	else if(month==6){
		if(day>0 && day<22) n=2;
		else if(day>21 && day<31) n=4;
		else n=0;
	}
	else if(month==7){
		if(day>0 && day<23) n=4;
		else if(day>22 && day<32) n=5;
		else n=0;
	}
	else if(month==8){
		if(day>0 && day<23) n=5;
		else if(day>22 && day<32) n=6;
		else n=0;
	}
	else if(month==9){
		if(day>0 && day<23) n=6;
		else if(day>22 && day<31) n=7;
		else n=0;
	}
	else if(month==10){
		if(day>0 && day<24) n=7;
		else if(day>23 && day<32) n=8;
		else n=0;
	}
	else if(month==11){
		if(day>0 && day<23) n=8;
		else if(day>22 && day<31) n=9;
		else n=0;
	}
	else if(month==12){
		if(day>0 && day<22) n=9;
		else if(day>21 && day<32) n=10;
		else n=0;
	}
	
	return n;
}