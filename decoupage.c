#include "treat_mask.h"
#include "decoupage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void new_decimal_system(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int computer,int cut,char class_indice) {
    int temp;
    int first_bit;
    int second_bit;
    int third_bit;
    int last_bit;
    if (class_indice=='C')
        for(int i=1;i<=2*cut;i++) {
            printf("sous reseau %d :\n",i);
            calcul_byte(&first_bit,first_byte);
            calcul_byte(&second_bit,second_byte);
            calcul_byte(&third_bit,third_byte);
            calcul_byte(&last_bit,last_byte);
            if (last_bit>=128)
                temp=last_bit;
                printf("%d\n",last_bit);
                last_bit=255-last_bit*i;
                if(i != 1) last_bit-=1;
                printf("\t@ reseau :%d.%d.%d.%d\n",first_bit,second_bit,third_bit,last_bit);
                last_bit+=temp;
                printf("\t@ broadcast :%d.%d.%d.%d\n",first_bit,second_bit,third_bit,last_bit);
        }
}
void treating(int computer,int cut,char*netmask,char*ip_binary,char class_indice) {
    char network[38];
    char first_byte[9];
    char second_byte[9];
    char third_byte[9];
    char last_byte[9];
    strcpy(network,"");
    adressing_network(network,netmask,ip_binary);
    cat_binary(network,first_byte,second_byte,third_byte,last_byte);
    new_decimal_system(first_byte,second_byte,third_byte,last_byte,computer,cut,class_indice);
}
long computer_number (int cut,char class_indice) {
    if (class_indice=='A') return(pow(2,24-cut)-2);
    if (class_indice=='B') return(pow(2,16-cut)-2);
    if (class_indice=='C') return(pow(2,8-cut)-2);
}
void masking(int cut,char*netmask,char class_indice) {
    strcpy(netmask,"");
    if(class_indice=='A') {
        for(int i=0;i<35;i++) {
            if(i==8 || i==17 || i==26 ) strcat(netmask," ");
            else {
                if(i<9+cut && i!=8) strcat(netmask,"1");
                else        strcat(netmask,"0");

            }
        }
    }
    if(class_indice=='B') {
        for(int i=0;i<35;i++) {
            if(i==8 || i==17 || i==26 ) strcat(netmask," ");
            else {
                if(i<18+cut && i!=17) strcat(netmask,"1");
                else        strcat(netmask,"0");

            }
        }
    }
    if(class_indice=='C') {
        for(int i=0;i<35;i++) {
            if(i==8 || i==17 || i==26 ) strcat(netmask," ");
            else {
                if(i<27+cut && i!=26) strcat(netmask,"1");
                else        strcat(netmask,"0");

            }
        }
    }
}
void verify_cut(int cut) {
    if(cut<0){
        printf("nombre de decoupage invalid!!!\n");
        exit(0);
    }
}
int input_cut() {
    int cut=-1;
    printf("entrer le nombre de decoupage :");
    scanf("%d",&cut);
    return cut;
}
