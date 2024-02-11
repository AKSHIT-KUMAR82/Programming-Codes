#include <stdio.h>

int main(){
    printf("NAME : AKSHIT KUMAR\nSECTION : A1\nRNO : 05\n");
    char str[100];
    printf("Enter string: ");
    scanf("%s",str);

    int count1 = 0, count2 = 0, count3 = 0;
    int i;

    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == '1') count1++;
        if(str[i] == '2') count2++;
        if(str[i] == '3') count3++;
    }

    if(count1 > 0 && count1 == count2 && count2 == count3 && str[i] == '\0') printf("VALID STRING…");
    else printf("INVALID STRING");
}
