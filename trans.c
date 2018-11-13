#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");

	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	data start,dest;

	start.op = strtok(args,",");
	dest.op=strtok(NULL,",");

	switch(start.op[0]=='$')
	{
	case '0':
		if(strchr(start.op,'(')==NULL) 
		{
		start.type=mem_abs;
		}
		else
		start.type = mem_disp;
		break;
	case '(':
		start.type=mem_rel;
		break;
	case '$':
		start.type = imm;
		break;
	case '%':
		start.type = reg;
		break;
	case '-':
		start.type =mem_disp;
		break;
	}
	//=======================================
	switch(dest.op[0])
	{
	case '0':
		if(strchr(dest.op,'(')==NULL)
		dest.type= mem_abs;
		else
		dest.type=mem_disp;
		break;
	case '(':
		dest.type = mem_rel;
		break;
	case '$':
		dest.type = imm;
		break;
	case '%':
		dest.type = reg;
		break;
	case '-':
		dest.type = mem_disp;
		break;
	default:
		printf("error\n");
	
	}
	//1. register to register
	if(start.type ==reg)
	{
	if(dest.type ==reg) strcpy(mcode,"89");
	//5. register to register[eax]
    else if(dest.type==mem_abs||dest.type==mem_rel||dest.type==mem_disp)strcpy(mcode,"a3");
	//6. immediate to register
	else if(start.type==imm){
	if(strcmp(dest.op,"%eax")==0)strcpy(mcode,"b8");
	else if(strcmp(dest.op,"%ecx")==0)strcpy(mcode,"b9");
	else if(strcmp(dest.op,"%edx")==0)strcpy(mcode,"ba");
	else if(strcmp(dest.op,"%ebx")==0)strcpy(mcode,"bb");
	else if(strcmp(dest.op,"%esp")==0)strcpy(mcode,"bc");
	else if(strcmp(dest.op,"%ebp")==0)strcpy(mcode,"bd");
	else if(strcmp(dest.op,"%esi")==0)strcpy(mcode,"be");
	else if(Strcmp(dest.op,"%edi")==0)strcpy(mcode,"bf");

	}
	//3. memory to register
	else if(dest.type==reg){
	if(start.type==mem_disp) strcpy(mcode,"8b");
	}
	else
	{
	//4.memory to register[eax]
	if(strcmp(dest.op,"%eax")==0)strcpy(mcode,"a1");
	//2.memory to register
	else strcpy(mcode,"8b");
	}
}
	return 1;	
}
