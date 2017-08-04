#include <stdio.h>
#include <stdbool.h>

void MyShiftOut( unsigned long val, bool not)
{
  for( int i = 0; i < 8; i++ )
  {
    if(not)
        printf("%d\n", !(val & (1L << i)));
    else
        printf("%d\n", !!(val & (1L << i)));
  }
}

int main(){
    unsigned long val = 0;
    bool not = true;
    
    printf("Please number :");
    scanf("%lu", &val);

    MyShiftOut(1L << val, not);
    return 0;
}