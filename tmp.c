
    void Check(char ins[])
{
  if(ins[0]=='0' && ins[1]=='1'){
        printf("One address instruction\n");
        int a=CheckReg(11,9)
        switch(a)
        case 0:
            WTR();
            break;
        case 1:
            LDR();
            break;
        case 2:
            ODR();
            break;
        case 3:
            MYJMP();
            break;
        case 4:
            JGT();
            break;
        case 5;
            JLT();
            break;
        case 6:
            JEQ();
            break;
      
}

        
 else if(ins[0]=='1' && ins[1]=='0'){
        printf("two address instruction\n");
        int a=CheckReg(5,3);
        switch(a)
        case 0:
            CCl();
            break;
        case 1:
            EXP();
            break;
        case 2:
            ENM();
            break;
        case 3:
            MOVa();
            break;
        case 4:
            MOVb();
            break;
        case 5;
            ADDa();
            break;
        case 6:
            ADDb();
            break;
        case 7;
            CMPa();
            break;
        case 8:
            CMPb();
            break;
}
    else if(ins[0]=='0' && ins[1]=='0'){
    printf("Zero address instruction\n");
        int a=CheckReg(15,13);
        switch(a)
        case 0:
            ON();
            break;
        case 1:
            OFF();
            break;
        case 2:
            ALERT();
            break;
        case 3:
            HLT();
            break;
        case 4:
            CUR();
            break;
     }
    else
    {
         printf("Three address instruction\n");
        int a=CheckReg(3,2);
        switch(a)
        case 0:
            CLN();
            break;
        case 1:
            TDET();
            break;
        case 2:
            TFT();
            break;
        }
}
        
