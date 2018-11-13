#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int instr_trans(char *op,char*args,char*mcode);
int is_valid(char *op,char *args);
typedef enum member{reg,abst,rel,dis,imm}member;
typedef struct data{
char *op;
member type;
}data;
// complete this header file
