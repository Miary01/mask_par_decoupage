#ifndef WITHOUT_CLASS_H
#define WITHOUT_CLASS_H
int input_bit_network(char*ip);
void print(int first_bit,int second_bit,int third_bit,int last_bit);
void verify_bit(int bit_network);
void treat_msr(int bit_network,char*MSR);
void sectioning(char*MSR,char*first_byte,char*second_byte,char*third_byte,char*last_byte);
void reconvert_decimal(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int*first_bit,int*second_bit,int*third_bit,int*last_bit);
#endif
