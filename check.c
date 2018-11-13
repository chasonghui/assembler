#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/
	char tmp[256];
	strcpy(tmp,args);
	char *start = strtok(tmp,",");
	char *dest=strtok(NULL,",");
	if(dest[0]=='$')return 0;
	if((start[0]=='0'||start[0]=='('||start[0]=='-')&&(dest[0]=='-'||dest[0]=='('))return 0;
	return 1;
}
