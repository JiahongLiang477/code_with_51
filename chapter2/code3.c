#include<REGX52.h>
#include<INTRINS.h>
//LED流水灯

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


void main(){
    while(1){
        P2 = 0xFE;  //1111 1110
        Delay500ms();
        P2 = 0xFD; // 1111 1101
        Delay500ms();
        P2 = 0xFB; // 1111 1011
        Delay500ms();
        P2 = 0xF7; // 1111 0111
        Delay500ms();
        P2 = 0xEF; // 1110 1111
        Delay500ms();
        P2 = 0xDF; // 1101 1111
        Delay500ms();
        P2 = 0xBF; // 1011 1111
        Delay500ms();
        P2 = 0x7F; // 0111 1111
        Delay500ms();
    }
}