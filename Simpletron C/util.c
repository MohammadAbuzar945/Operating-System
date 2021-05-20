/*Mohammad Abuzar   
	SP19-BCS-089   */


#include <stdio.h>
#include "myheader.h"



int accum;
int counter;
int reg;
int mem[SIZE];
int oprand;
int operation;




FILE *Lf(const char fname[])
{

FILE *file;
file=fopen(fname, "r");

if(!file)
	printf("Open a Correct File\n");

return file;

}


void Linst(FILE *file)
{

int count=0;
while(fscanf(file,"%d", &mem[count++]))
	if(count==SIZE)
		break;
		
}

void printInfo()
{

printf("\n\t\t\t\t\t\t\t!!!!!!!!!!!!!!!Values of Register!!!!!!!!!!!!!!!!!!!\n");

printf("Operand %d \n",oprand);
printf("Operation %d \n",operation);

printf("Instruction Counter %d \n",counter);
printf("Instruction_Reg %d \n",reg);
printf("Accumulator_Reg %d \n",accum);

}		
		 

void memory()
{
int i;
int flag;
//flag=((SIZE+10)%SIZE);
for(i=0;i<((SIZE+10) % SIZE);i++)
	printf("    %02d",i);

for(i=0;i<SIZE;i++)
	{if(i%10==0)
		printf(" 	 \n%02d",i);	
      printf(" %+05d",mem[i]);
}
}


void switchpart()
{

//check to see instruction counter if greater then SIZE of memory then return from here

if(counter>=SIZE)
	return;
reg=mem[counter];

//again check if instruction register is equal to zero then return 

if (reg==0)
	return;
	
oprand=reg%100;

operation=reg/100;
		
	
switch(operation)
{

case R:
	printf("?");
	int a ;
	scanf("%d",&a);
	if(a>9999||a<-9999)
		return switchpart();
	mem[oprand]=a;
	break;

case W:

   printf("The value is %d\n",mem[oprand]);
   break;

case L:
   
	accum=mem[oprand];
	break;

case S:
	mem[oprand]=accum;
	break;
case A:

	accum=accum+mem[oprand];	
	break;


case Halt:
       printf("\nStopped Executon\n");
       return;
       
case Branch:
    	counter=oprand-1;

	break;
case BranchNeg:
	//check condition
	if(accum<0)
		counter=oprand-1;
	
	break;
case BranchZero:
	if(accum==0)
	counter=oprand-1;
	
	break;       
default:
       printf("\nInvalid Option\n ");       
	return;
}

counter++;
memory();
printInfo();
switchpart();

}

void run(const char fname[])
{

printf("\n\t\t\t\t\tWelcome\n");

FILE *f3=Lf(fname);

if(f3==NULL)
	return;
	
Linst(f3);

switchpart();


}

