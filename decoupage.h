#ifndef DECOUPAGE_H
#define DECOUPAGE_H
long computer_number(int cut,char class_indice);
int input_cut();
void verify_cut(int cut);
void masking(int cut,char*netmask,char class_indice);
void treating(int computer,int cut,char*netmask,char*ip_binary,char class_indice);
#endif
