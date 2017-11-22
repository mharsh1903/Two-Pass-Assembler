#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define size 1000

/* Assembler Created By:
1. Abhijeet Pareek (15UCC001)
2. Harsh Modi (15UCC014)
3. Sparsh Agarwal (15UCC038)
4. Yagyansh S. Kumar (15UCC042) */

struct regisa{
	char regname[10];
	char regopcode[20];
	
	struct regisa *next;
};

struct label{
    char labelname[10];
    int line;
};

struct label arr[50];   
int currentsize=0;
struct regisa *hashtable1[size];

int count(FILE *fp) // Function to Count the number of lines.
{
	char c;
	int count=0;
	for (c = getc(fp); c != EOF; c = getc(fp)){
		if (c == '\n') // Increment count if this character is newline
			count = count + 1;
    }
	rewind (fp);
	return count+1;
}


long hashcode1(char regname[]){
	int i;
	long sum=0;
	for(i=0;regname[i]!='\0';i++){
		sum += (regname[i]-'A');
	}
	return (sum%10);
}


void insert1(char regname[],char regopcode[]){
	//printf("1\n");
	struct regisa * emp = (struct regisa *)malloc(sizeof(struct regisa));
	
	strcpy(emp->regname,regname);
	strcpy(emp->regopcode,regopcode);
	
	long hashindex = hashcode1(regname);
	//printf("1\n");
	if (hashtable1[hashindex]==NULL ) 
	{
	emp->next=NULL;
        hashtable1[hashindex] = emp;        
        return;
    	}

   
    emp->next = (hashtable1[hashindex]);

   
    hashtable1[hashindex] = emp;

    

    return;

}
void search1(char regname[]){
	long hashindex = hashcode1(regname);
	struct regisa * e;
	e= hashtable1[hashindex];
    FILE *fptr;
    fptr = fopen("binarycode.txt" , "a+");

	if(e == NULL){
		printf("not found");
		return;
	}	
	else{
		int flag=0;
		while(e!=NULL){
			if(strcmp(e->regname,regname)==0){
				printf(" %s ",e->regopcode);
                fprintf(fptr , "%s\t",e->regopcode);
                flag=1;	
			break;
			
			}
            
			e = e->next;
		
		}
		if(flag==0){
			printf("not found");
		return;
		}
			
	
	}	
fclose(fptr);
}

// Convert Decimal To Binary
long long int convert(int dec)

{

    if (dec == 0)

    {

        return 0;

    }

    else

    {

        return (dec % 2 + 10 * convert(dec / 2));

    }

}

// Check Every Instruction Format
void check(char s[]){
	int i;
	char str[5];
    FILE *fptr;
    fptr = fopen("binarycode.txt" , "a+");

	for(i=0;s[i]!='\0';i++){
		// Immediate Addressing
		if(s[i]=='#'){
			int num=0;
			i++;
			while(s[i]!='\0' && (s[i]>='0' && s[i]<='9')){
				num = (num*10) + (s[i]-'0');
				i++;
			}
			printf(" %lld",convert(num));
            		fprintf(fptr,"%lld\t",convert(num));            			
		}
        
		if(s[i]=='R'){
			str[0]='R';	
			str[1]=s[++i];
            	if(s[i+1]>='0' && s[i+1]<='9' && s[i+1]!='\0'){
                	str[2]=s[++i];
                	str[3]='\0';
            }
			
            else{
			    str[2]='\0';
            }
			search1(str);
		}
        else if(s[i]=='F' && s[i+1]=='L'){
            strcpy(str,"FLAG");
        }
        else if(s[i]=='P' && s[i+1]=='C'){
            strcpy(str,"PC");
        }
        else if(s[i]='S' && s[i+1]='R'){
            strcpy(str,"SR");
        }
        else{
            strcpy(str,"BR");
        }
            
		
	}	
fclose(fptr);
}

struct isa{
	char name[10];
	char opcode[20];
	
	struct isa *next;
}*s,*r;

struct isa *hashtable[size];


long hashcode(char name[]){
	int i;
	long sum=0;
	for(i=0;name[i]!='\0';i++){
		sum += (name[i]-'A');
	}
	return (sum%10);
}


void insert(char name[],char opcode[]){
	//printf("1\n");
	struct isa * emp = (struct isa *)malloc(sizeof(struct isa));
	
	strcpy(emp->name,name);
	strcpy(emp->opcode,opcode);
	
	long hashindex = hashcode(name);
	//printf("1\n");
	if (hashtable[hashindex]==NULL ) {
	emp->next=NULL;
        hashtable[hashindex] = emp;

        
        return;

    }

   
    emp->next = (hashtable[hashindex]);

   
    hashtable[hashindex] = emp;

    

    return;

}

// Printing the Opcode 
void search(char name[]){
	long hashindex = hashcode(name);
	struct isa * e;
    FILE *fptr;
    fptr = fopen("binarycode.txt" , "a+");
	e= hashtable[hashindex];
	if(e == NULL){
		printf("not found");
		return;
	}	
	else{
		int flag=0;
		while(e!=NULL){
			if(strcmp(e->name,name)==0){
				printf("\n%s ",e->opcode);
                fprintf(fptr , "%s\t",e->opcode);

			flag=1;	
			break;
			
			}
			e = e->next;
		
		}
        
		if(flag==0){
			printf("not found");
		return;
		}
			
	
	}	
fclose(fptr);
}

// Reading the Opcodes
void read1()
{
//printf("c");
     char a[10],b[30];
	FILE *f;
	f=fopen("opcod.txt","r");
    //printf("b");
	int n=count(f); //NUMBER OF LINES OF OPCODES
	int i=0;
	int ac=0;
	//s=(struct isa*)malloc(n*sizeof(struct isa));
	while(!feof(f))
	{
		for(i=0;i<n;i++)
		{
			fscanf(f,"%s %s",a,b);
            insert(a,b);
		}
	}
	fclose(f);
}

void read2() // READING THE REGISTERS
{
	FILE *f;
    char a[10],b[30];
	f=fopen("NEWRegistor.txt","r");
	int n=count(f);
	int i=0;
	int ac=0;
	//r=(struct isa*)malloc(n*sizeof(struct isa));
	while(!feof(f))
	{
		for(i=0;i<n;i++)
		{
			fscanf(f,"%s %s",a,b);
            insert1(a,b);
		}
	}
	fclose(f);
}
/*
void read3()
{
char a[10];
FILE *f;
	f=fopen("test.txt","r");
    
	int n=count(f);
	int i=0;
	int ac=0;
	//r=(struct isa*)malloc(n*sizeof(struct isa));
	while(!feof(f))
	{
		for(i=0;i<n;i++)
		{
            fscanf(f,"%s",a);
			search(a);
		}
	}
	fclose(f);
}
*/
//Reading the Assembly Code
void read(){
	FILE *fptr;
	char filename[100], c;

    printf("Enter the filename to open \n");
    scanf("%s", filename);
	fptr=fopen(filename,"r");
	char a[20],b[50];
	int n=count(fptr); //NUMBER OF LINES OF OPCODES
	int i=0;
	int ac=0;
	//s=(struct isa*)malloc(n*sizeof(struct isa));
	while(!feof(fptr))
	{
		for(i=0;i<(n-1) && (!feof(fptr));i++)
		{
			fscanf(fptr,"%s",a);
            if(a[strlen(a)-1]==':')
            {
                strcpy(arr[currentsize].labelname,a);
                arr[currentsize++].line=i+1;
            }
             else{   
			search(a);
			fgets(b,50,fptr);
			check(b);
            }
		}
	}
	fclose(fptr);



}
void labeltableprint(){
    int i;
    printf("\n\nSYMBOL TABLE");
    FILE *fptr;
    fptr = fopen("labels.txt" , "w");
    
    for(i=0;i<currentsize-1;i++){
        printf("\n%s  %d",arr[i].labelname,arr[i].line);
        fprintf(fptr , "%s\t", arr[i].labelname);
        fprintf(fptr , "%d\n", arr[i].line);
    }
    fclose(fptr);
    printf("\n");
}

void menu();
void getOpcode(){
 FILE *fptr;

    char c;

    

    // Open file
    fptr = fopen("opcod.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        menu();
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
} 
void getRegister(){
 FILE *fptr;

    char c;

    

    // Open file
    fptr = fopen("NEWRegistor.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
} 
void showAss(){
FILE *fptr;

    char filename[100], c;

    printf("Enter the filename to open \n");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return;

}

void menu(){ 
		int option=0;
	printf("\n\n");
        printf("-----------Enter Input From Given Range ------------\n");
        printf("1.Print the Opcode table\n");
        printf("2.Print the Register table\n");
        printf("3.Convert assembly to binary\n");
        printf("4.Print the label Table\n");
        printf("5.Show Assembly instruction file\n");
	printf("6.Exit\n");		 
	while(option<=6)
    {
		printf("Enter Your Option: ");
        scanf("%d",&option);
		printf("\n\n");
		switch (option)
		{
			case 1:
				getOpcode();
				menu();
				break;
				
			case 2:
				getRegister();
				menu();
					break;
				
			case 3:
			read1();
			read2();
			read();	
			menu();
	         break;
            
            case 4:
            labeltableprint();
		menu();
            break;
            
            case 5:
		showAss();
		menu();
            	break;
	case 6:
    
          	
	
    		exit(0);
				
		}
    	

	printf("Incorrect option \n");
	menu();}
}



int main(){
int i;
for(i=0;i<1000;i++){
	hashtable1[i]=NULL;
}
for(i=0;i<1000;i++){
hashtable[i]=NULL;

}

menu();




//printf("%s\n%s\n",hashtable[7]->name,hashtable[7]->opcode);

return 0;
}


