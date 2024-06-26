#include<REGX52.h>
#include<INTRINS.h>
//控制LED不断循环亮灭

//延时函数
void Delay500ms()   //@12.000MHz
{
    unsigned char i, j , k;

    _nop_();   //在晶振频率为12.000MHz时，延时为1ms
    i = 4;
    j = 205;
    k = 187;
    do{
        do
        {
         whlie (--k);   
        } while(--j);
    }while(--i);
}

//主函数
void(){
    
    while(1){
    P2 = 0xFE;
    Delay500ms(); //延时函数
    P2 = 0xFF;
    }
}