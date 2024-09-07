#include "without_class.h"
#include "treat_mask.h"
#include "decoupage.h"
#include "treat_ip.h"
#include <stdio.h>
#define LENGTH 50
int main() {
    char first_byte[10];
    char second_byte[10];
    char third_byte[10];
    char last_byte[10];
    char ip[LENGTH];
    char ip_binary[36];
    char netmask[36];
    int first_bit=256;
    int second_bit=256;
    int third_bit=256;
    int last_bit=256;
    int first_bitmask;
    int second_bitmask;
    int third_bitmask;
    int last_bitmask;
    int cut=-1;
    long computer=0;
    char last_word='\0';
    char class_indice;
    ///verifie l'adresse ip
    input_ip(ip);
    treat_ip(ip,&first_bit,&second_bit,&third_bit,&last_bit,&last_word);
    verify_ip(first_bit,second_bit,third_bit,last_bit,last_word,&class_indice);
    convert_binary(ip_binary,first_bit,second_bit,third_bit,last_bit);
    ///entrer le nombre de decoupage
    cut=input_cut();
    verify_cut(cut);
    ///masque de sous réseau
    masking(cut,netmask,class_indice);
    sectioning(netmask,first_byte,second_byte,third_byte,last_byte);
    reconvert_decimal(first_byte,second_byte,third_byte,last_byte,&first_bitmask,&second_bitmask,&third_bitmask,&last_bitmask);
    print(first_bitmask,second_bitmask,third_bitmask,last_bitmask);
    return 0;
}
