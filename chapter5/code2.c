#include <REGX52.h>
//LCD1602调试工具
//描述LCD1602的各种函数，但不包含源码
void main(){
    LCD_Init();  //初始化
    
    while(1)
    {
    LCD_ShowChar(1, 1, 'A');         //在第一行第一列显示A
    LCD_ShowString(1, 3, "Hello");   //在第一行第三列显示Hello
    LCD_ShowSignedNum(1, 9, 123, 3); //在第一行第九列显示123，长度为3
    LCD_ShowHexNum(2, 1, 0xA8, 2);   //在第二行第一列显示十六进制的0xA8，长度为2
    LCD_showBinNum(2, 4, 0xAA, 8);   //在第二行第四列显示二进制的0xA8,长度为8
    }
}