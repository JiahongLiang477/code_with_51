#include<REGX52.h>
#include<INTRINS.h>
//LED流水灯plus----可控延时

//延时函数
void Delay(unsigned int xms)   //@12.000MHz
{
    unsigned char i, j;
    while(xms)
    {
        i = 2;
        j = 239;
        do
        {
            whlie (--j);
        } while (--i);
        xms--;
    }


    
}


void main(){
    while(1){
        P2 = 0xFE;  //1111 1110
        Delay(200);
        P2 = 0xFD; // 1111 1101
        Delay(200);
        P2 = 0xFB; // 1111 1011
        Delay(200);
        P2 = 0xF7; // 1111 0111
        Delay(200);
        P2 = 0xEF; // 1110 1111
        Delay(200);
        P2 = 0xDF; // 1101 1111
        Delay(200);
        P2 = 0xBF; // 1011 1111
        Delay(200);
        P2 = 0x7F; // 0111 1111
        Delay(200);
    }
}