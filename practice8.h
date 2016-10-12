#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu()
{
    printf("a) Convert binary to Decimal\n");
    printf("b) Convert hexidecimal to Decimal\n");
    printf("c) Convert String to Double\n");
    printf("d) Exit\n");
}

int BinaryToInt(char cAbinary[32])
{
    int iCont=0,iDecimal=0;
    char *cpPointer;
    cpPointer = &cAbinary[0];
    while(cAbinary[iCont]!='\0')
    {
        iCont++;
    }
    iCont--;
    while(*cpPointer != '\0')
    {
        if(*cpPointer == '1')
        {
            iDecimal += pow(2,iCont);
        }
        iCont --;
        cpPointer++;
    }
    return iDecimal;
}
int HexToInt(char cAhex[8])
{
    int iCont=0,iDecimal=0,iTemp=0;
    char *cpPointer;
    cpPointer = &cAhex[0];
    while(cAhex[iCont]!='\0')
    {
        iCont++;
    }
    iCont--;
    while(*cpPointer != '\0')
    {
        switch (*cpPointer) {
            case 'A':
                iDecimal += 10 * pow(16,iCont);
                break;
            case 'B':
                iDecimal += 11 * pow(16,iCont);
                break;
            case 'C':
                iDecimal += 12 * pow(16,iCont);
                break;
            case 'D':
                iDecimal += 13 * pow(16,iCont);
                break;
            case 'E':
                iDecimal += 14 * pow(16,iCont);
                break;
            case 'F':
                iDecimal += 15 * pow(16,iCont);
                break;
            default:
                iTemp = (int)*cpPointer - 48;
                iDecimal += iTemp  * pow(16,iCont);
                break;
        }
        iCont--;
        cpPointer++;
    }
    return iDecimal;
}
double FloatToDouble(char cAFloat[20])
{
    double dDecimal=0;
    int iSign=0,iPoint=0,iCont=0;
    char *cpPointer;
    char cADouble[20];
    cpPointer = &cAFloat[0];
    while(*cpPointer !='\0')
    {
        if(*cpPointer == '+' || *cpPointer == '-')
        {
            iSign++;
            if(iSign == 2)
            {
                return -1000;
            }
        }
        if(*cpPointer=='.')
        {
            iPoint++;
            if(iPoint == 2)
            {
                return -1000;
            }
        }
        cpPointer++;
    }
    cpPointer = &cAFloat[0];
    while(*cpPointer!='\0')
    {
        if(*cpPointer=='.')
        {
            cADouble[iCont] = *cpPointer;
            iCont++;
            cpPointer++;
            cADouble[iCont] = *cpPointer;
            iCont++;
            cpPointer++;
            cADouble[iCont] = *cpPointer;
            break;
        }
        cADouble[iCont] = *cpPointer;
        iCont++;
        cpPointer++;
    }
    dDecimal = strtod(cADouble, NULL);
    return dDecimal;
}
