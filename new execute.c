#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define size 1000

/* Assembler Created By:
1. Abhijeet Pareek (15UCC001)
2. Harsh Modi (15UCC014)
3. Sparsh Agarwal (15UCC038)
4. Yagyansh S. Kumar (15UCC042) */

void check(char ins[]){
    if(ins[0]=='0' && ins[1]=='0'){
        printf("Zero address instruction\n");
        if(ins[13]=='0' && ins[14]=='0' && ins[15]=='0'){
            ON();
        }
        else if(ins[13]=='0' && ins[14]=='0' && ins[15]=='1'){
            OFF();
        }
        else if(ins[13]=='0' && ins[14]=='1' && ins[15]=='0'){
            ALERT();
        }
        else if(ins[13]=='0' && ins[14]=='1' && ins[15]=='1'){
            HLT();
        }
        else{
            CUR();
        }
    }

    else if(ins[0]=='0' && ins[1]=='1'){
        printf("One address instruction\n");
        if(ins[8]=='0' && ins[9]=='0' && ins[10]=='0'){
            WTR();
        }
        else if(ins[8]=='0' && ins[9]=='0' && ins[10]=='1'){
            LDR();
        }
        else if(ins[8]=='0' && ins[9]=='1' && ins[10]=='0'){
            ODR();
        }
        else if(ins[8]=='0' && ins[9]=='1' && ins[10]=='1'){
            MYJMP();
        }
        else if(ins[8]=='1' && ins[9]=='0' && ins[10]=='0'){
            JGT();
        }
        else if(ins[8]=='1' && ins[9]=='0' && ins[10]=='1'){
            JLT();
        }
        else if(ins[8]=='1' && ins[9]=='1' && ins[10]=='0'){
            JEQ();
        }
        
    }

    else if(ins[0]=='1' && ins[1]=='0'){
        printf("two address instruction\n");
        if(ins[3]=='0' && ins[4]=='0' && ins[5]=='0' && ins[6]=='0'){
            CCL();
        }
        else if(ins[3]=='0' && ins[4]=='0' && ins[5]=='0' && ins[6]=='1'){
            EXP();
        }
        else if(ins[3]=='0' && ins[4]=='0' && ins[5]=='1' && ins[6]=='0'){
            ENM	();
        }
        else if(ins[3]=='0' && ins[4]=='0' && ins[5]=='1' && ins[6]=='1'){
            MOVa();
        }
        else if(ins[3]=='0' && ins[4]=='1' && ins[5]=='0' && ins[6]=='0'){
            MOVb();
        }
        else if(ins[3]=='0' && ins[4]=='1' && ins[5]=='0' && ins[6]=='1'){
            ADDa();
        }
        else if(ins[3]=='0' && ins[4]=='1' && ins[5]=='1' && ins[6]=='0'){
            ADDb();
        }
        else if(ins[3]=='0' && ins[4]=='1' && ins[5]=='1' && ins[6]=='1'){
            CMPa();
        }
        else{
            CMPb();
        }
       
        
    }

    if(ins[0]=='1' && ins[1]=='1'){
        printf("Three address instruction\n");
        if(ins[2]=='0' && ins[3]=='0'){
            CLN();
        }
        else if(ins[2]=='0' && ins[3]=='1'){
            TDET();
        }
        
        else{
            TFT();
        }
    }

    

}
int CheckReg(int x,int y)
{
    int z=0;
    for(int i=x;i>=y;i--)
    {
        z=z+((ins[i]-'0')*base);
        base=base*2;
    }
    return(z);
}

void Mova()
{
    int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    R[a].val=b;
    Printf("Value in %s = %d",R[a].Reg,R[a].val);
}

void Movb()
{
    int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    R[a].val=R[b].val;
    Printf("Value in %s = %d",R[a].Reg,R[a].val);
}

void Adda()
{
    int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    R[a].val=R[a].val+b;
    Printf("Value in %s = %d",R[a].Reg,R[a].val);
}

void Addb()
{
    int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    R[a].val=R[a].val+R[b].val;
    Printf("Value in %s = %d",R[a].Reg,R[a].val);
}

void Cmpa()
{
     int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    if(R[a].val-b==0)
    {
        printf("Arithmetic Operation\n");
        printf("Status Register = 1\n");
        printf("Flag Status : Z = 1\n");
    }
     if(R[a].val-b<0)
    {
         printf("Arithmetic Operation\n");
        printf("Status Register = 1\n");
        printf("Flag Status : N = 1\n");
    }      
}

void Cmpb()
{
     int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    if(R[a].val-R[b].val==0)
    {
        printf("Arithmetic Operation\n");
        printf("Status Register = 1\n");
        printf("Flag Status : Z = 1\n");
    }
     if(R[a].val-R[b].val<0)
    {
         printf("Arithmetic Operation\n");
        printf("Status Register = 1\n");
        printf("Flag Status : N = 1\n");
    }      
}

void CCL()
{
     int a=CheckReg(11,8);
    int b=CheckReg(15,12);
    R[a].val==(R[a].val)*b;
}



void EXP(int oprd1,int oprd2,int oprd3){	//oprd1 is the product manufacture month & oprd3 is best before of product
	int expmonth,expyear;
    
	if((oprd1+oprd3)<12)
{
    expmonth=oprd1+oprd3;
    expyear=oprd2;

}
else
{
    expmonth=oprd1+oprd3;
    while(expmonth>=12)
{
    x=expmonth/12;
    expyear=oprd+x;
    expmonth=oprd1+(expmonth%12);
}
}
 if(expyear<r[10])
{
printf("Product expired\n");
}
else if(expyear==r[10])
{
    if(expmonth>r[9])
    {
        printf("Product will expire in %d months",expmonth-r[9]);
    }
    else
    {
        printf("product expired\n");
    }
}
else
{
    printf("Product will expire in %d months", ((expyear-r[10])*12)+expmonth-r[9]);
}

}

    

struct Register
{
    char Reg[5];
    int val;

} ;


int main()
{
   struct Register R[20]={ {"R0",-1},{"R1",-1},{"R2",-1},{"R3",-1},{"R4",-1},{"R5",-1},{"R6",-1},{"R7",-1},{"R8",-1},{"R9",-1},{"R10",-1},{"R11",-1},{"R12",-1},{"R13",-1},{"R14",-1},{"R15",-1},{"R16",-1}};
   
}       
    


void read1()
{
//printf("c");
     char a[20];
	FILE *f;
	f=fopen("machinecode.txt","r");
    //printf("b");
	int n=count(f); //NUMBER OF LINES OF OPCODES
	int i=0;
	int ac=0;
	//s=(struct isa*)malloc(n*sizeof(struct isa));
	while(!feof(f))
	{
		for(i=0;i<n;i++)
		{
			fscanf(f,"%s",a);
            
		}
	}
	fclose(f);
}
