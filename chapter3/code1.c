#include<REGX52.h>
//独立按键控制LED亮灭
void main(){
    while(1){
        if(P3_1 == 0)
        {
            P2_0 = 0;
        }
        else{
            P2_0 = 1;
        }
    }
}