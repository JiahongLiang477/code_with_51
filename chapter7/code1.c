#include <REGX52.h>
//定时器

void Timer0_Init()
{
    // TMOD = 0x01; 
    TMOD = TMOD & 0xF0;  //低四位清零，高四位不变
    TMOD = TMOD | 0x01;  //最低位置1，高四位不变
    TF = 0;
    TR0 = 1;
    TH0 = 64535/256;
    TL0 = 64535%256;
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}


void main(){
    P2 = 0xFE;
    Timer0_Init();
    while(1)
    {
        KeyNum = Key();
        if(KeyNum){
            if (KeyNum == 1)
            {
                LEDMode++;
                if(LEDMode>=2) LEDMode=0;
            }
        }
    }
}

void Timer0_Routine() interrupt 1;
{
    TH0 = 64535/256;
    TL0 = 64535%256;
    T0Count++;
    if(T0Count>=1000){
        T0Count = 0;
        P2_0 = ~ P2_0;
    }
}