#include "stdio.h"
#include<conio.h>


int convert(int );

bool bin[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


int main(){

    int dec;
  printf("Enter the decimal no to be converted:");
  scanf("%d",&dec);


   dec = convert(dec);
   while(dec >0)
   dec=convert(dec);

 printf("\n\n\nBinomial Equivalent is :  ");


  for(int j=15;j>=0;j--)
  printf("%d",bin[j]);




    getch();
}



int convert(int x){

    int  bval[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4196,8392,16784,33568};


    int i =0;
    while( bval[i]<=x )                                                                 //linear search
    i++;

   bin[i-1]=1;

   return x-bval[i-1];


}



