#include <REGX52.h>
//串口向电脑发送数据


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
        xms--;}
}


void UART_Init(){
    SCON = 0x40;
    PCON |= 0x80;
    //配置定时器
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = 0xF3;
    TH1 = 0xF3;
    ET1 = 0;
    TR1 = 1;
}


void UART_SendByte(unsigned char Byte)
{
    SBUF = Byte;
    while(TI == 0);
    TI = 0;
}

void main()
{
    UART_Init();
    while(1)
    {
        UART_SendByte(0x66);
        Delay(1); //波特率太快可能导致错误，因此延时一下
    }
}