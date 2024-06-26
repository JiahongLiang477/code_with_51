#include <REGX52.h>
//独立按键控制led状态

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

//主函数
void main(){
    while(1){
        if(P3_1 == 0)
        {
            Delay(20);
            while(P3_1==0);
            Delay(20);
            P2_0 =~ P2_0;

        }
    }
}