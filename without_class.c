#include "without_class.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void reconvert_decimal(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int*first_bit,int*second_bit,int*third_bit,int*last_bit) {
	int temp_bit=0;
	for(int i=0;i<8;i++){
		if(first_byte[i]=='1') {
			temp_bit+=1*pow(2,7-i);
		}
		if(first_byte[i]=='0') {
			temp_bit=temp_bit;
		}
	}
	*first_bit=temp_bit;
	temp_bit=0;
	for(int i=0;i<8;i++){
		if(second_byte[i]=='1') {
			temp_bit+=1*pow(2,7-i);
		}
		if(second_byte[i]=='0') {
			temp_bit=temp_bit;
		}
	}
	*second_bit=temp_bit;
	temp_bit=0;
	for(int i=0;i<8;i++){
		if(third_byte[i]=='1') {
			temp_bit+=1*pow(2,7-i);
		}
		if(third_byte[i]=='0') {
			temp_bit=temp_bit;
		}
	}
	*third_bit=temp_bit;
	temp_bit=0;
	for(int i=0;i<8;i++){
		if(last_byte[i]=='1') {
			temp_bit+=1*pow(2,7-i);
		}
		if(last_byte[i]=='0') {
			temp_bit=temp_bit;
		}
	}
	*last_bit=temp_bit;
}
void print(int first_bit,int second_bit,int third_bit,int last_bit) {
	printf("netmask: %d.%d.%d.%d\n",first_bit,second_bit,third_bit,last_bit);
}
void sectioning(char*MSR,char*first_byte,char*second_byte,char*third_byte,char*last_byte) {
	strcpy(first_byte,"");
	strcpy(second_byte,"");
	strcpy(third_byte,"");
	strcpy(last_byte,"");
	sscanf(MSR,"%s %s %s %s",first_byte,second_byte,third_byte,last_byte);	
}
void treat_msr(int bit_network,char*MSR) {
	strcpy(MSR,"");
	if(bit_network<=8) {
		for(int i=0;i<35;i++) {
			if(i==8 || i==17 || i==26) strcat(MSR," ");
			else {
				if(i<bit_network) strcat(MSR,"1");
				else strcat(MSR,"0");
			}
		}
	}
	if(bit_network>8 && bit_network<=16) {
		for(int i=0;i<35;i++) {
			if(i==8 || i==17 || i==26) strcat(MSR," ");
			else {
				if(i<bit_network+1) strcat(MSR,"1");
				else strcat(MSR,"0");
			}
		}
	}
	if(bit_network>16 && bit_network<=24) {
		for(int i=0;i<35;i++) {
			if(i==8 || i==17 || i==26) strcat(MSR," ");
			else {
				if(i<=bit_network+2) strcat(MSR,"1");
				else strcat(MSR,"0");
			}
		}
	}
	if(bit_network>24) {
		for(int i=0;i<35;i++) {
			if(i==8 || i==17 || i==26) strcat(MSR," ");
			else {
				if(i<=bit_network+3) strcat(MSR,"1");
				else strcat(MSR,"0");
			}
		}
	}
}
void verify_bit(int bit_network){
	if(bit_network<0 || bit_network>32) {	
		printf("invalid bit's number\n");
		exit(1); 
	}
}
int input_bit_network(char*ip) {
	int entier;
	printf("input the network bit's number:\n");
	printf("%s/",ip);
	scanf("%d",&entier);
	return entier;
}
