#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXSIZE 1500

int ugly[MAXSIZE], ptr2, ptr3, ptr5;

int minimum(int x,int y,int z)
{
       if (x<y) return (x<z?x:z);
            return (y<z?y:z);
}

int nextUgly(int num)
{
    int num2,num3,num5;
    if(num==0)
    {
           ugly[num]=1;
           ptr2=ptr3=ptr5=0;
           return  ugly[num];
    }
    num2=ugly[ptr2]*2;
    num3=ugly[ptr3]*3;
    num5=ugly[ptr5]*5;
    ugly[num]=minimum(num2,num3,num5);
    if(ugly[num]==num2) ptr2++;
    if(ugly[num]==num3) ptr3++;
    if(ugly[num]==num5) ptr5++;
    return ugly[num];
}

int main()
{
    int i, uglyNum;
    for(i=0; i<MAXSIZE; i++)
    uglyNum = nextUgly(i);
    cout<<"The "<<MAXSIZE<<"'th ugly number is "<<uglyNum <<"\n";
}

