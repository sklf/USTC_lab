#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define Pack_Size 15
#define Num 5

struct item{
    int size;
    int value;
};

struct item items[Num];
int result[Num];
int Sum_Value;

int  Size[Num] ={5,3,8,2,3};
int Value[Num] = {22,55,95,45,200};
void create()
{   
    memset(result,0,sizeof(result));
    for(int i;i < Num;i++)
    {
        items[i].size = Size[i];
        items[i].value = Value[i];
    }
}
void print()
{
    for(int i =0;i<Num;i++)
    {
        printf("%d",result[i]);
    }
}
int Value_Partation(int i,int j)
{   
    int temp1;
    int temp2;
    if(i == 0)
    {
        return 0;
    }
    if(j == 0)
    {
        return 0;
    }
    if(j<items[i].size)
    {
        return Value_Partation(i-1,j);
    }
    else
    {
        temp1 = Value_Partation(i-1,j);
        temp2 = Value_Partation(i-1,j-items[i].size)+items[i].value;
        if(temp1<temp2)
        {
            result[i] = 1;
            return temp2;
        }
        else
        {
            return temp1;
        }
    }

}


int main()
{   int sum;
    create();
    sum = Value_Partation(5,15);
    printf("%d",sum);
    print();
    return 0;
}

