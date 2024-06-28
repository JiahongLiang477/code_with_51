#include<REGX52.h>
//矩阵键盘密码锁
unsigned char KeyNum;
unsigned int Password;

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

unsigned char MatrixKey()
{
    unsigned char KeyNumber=0;
    P1 = 0xFF;
    P1_3 = 0;
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==1};
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==1};
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==1};
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==1};

    P1 = 0xFF;
    P1_2 = 0;
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==2};
    if(P1_6 == 0) {Delay(20); while(P1_6==0); Delay(20); KeyNumber==6};
    if(P1_5 == 0) {Delay(20); while(P1_5==0); Delay(20); KeyNumber==10};
    if(P1_4 == 0) {Delay(20); while(P1_4==0); Delay(20); KeyNumber==14};

    P1 = 0xFF;
    P1_1 = 0;
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==3};
    if(P1_6 == 0) {Delay(20); while(P1_6==0); Delay(20); KeyNumber==7};
    if(P1_5 == 0) {Delay(20); while(P1_5==0); Delay(20); KeyNumber==11};
    if(P1_4 == 0) {Delay(20); while(P1_4==0); Delay(20); KeyNumber==15};

    P1 = 0xFF;
    P1_0 = 0;
    if(P1_7 == 0) {Delay(20); while(P1_7==0); Delay(20); KeyNumber==4};
    if(P1_6 == 0) {Delay(20); while(P1_6==0); Delay(20); KeyNumber==8};
    if(P1_5 == 0) {Delay(20); while(P1_5==0); Delay(20); KeyNumber==12};
    if(P1_4 == 0) {Delay(20); while(P1_4==0); Delay(20); KeyNumber==16};
    return KeyNumber;
}


void main()
{
    int count = 0;
    LCD_Init();
    LCD_ShowString(1, 1, "PassWord");
    while(1)
    {
        KeyNum = MatrixKey();
        if(KeyNum)  //不加判断时刷新很快变为00
        {
            if(count < 4){
                if(KeyNum<=10){
                Password *=10;   //乘10留空位，比如111 ——》1110， 然后下面加上比如3，就是1113
                Password += KeyNum%10;   //获取一位密码
            }
            LCD_ShowNum(2,1 KeyNum, 4)
            count++;
            }
        }
        if(KeyNum == 11){  //设置11为确认键
            if(Password == 2345){
                LCD_ShowString(1, 14, "OK");
                Password = 0;   //密码清零
                count = 0;      //计算清零
                LCD_ShowNum(2,1 KeyNum, 4)
            }
            else{
                LCD_ShowSrting(1, 14, "ERR");
                Password = 0;   //密码清零
                count = 0;      //计算清零
                LCD_ShowNum(2,1 KeyNum, 4)
            }
        }

        if(KeyNum == 12){
            Password = 0;   //密码清零
            count = 0;      //计算清零
            LCD_ShowNum(2,1 KeyNum, 4)
        }
    }
}