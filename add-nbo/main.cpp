#include <stdint.h>     // for uint32_t
#include <stdio.h>      // for printf
#include <cstdio>       // for fopen, fclose


uint32_t my_ntohl(uint32_t a){
  return ((a&0xFF000000)>>24)|((a&0x00FF0000)>>8)|((a&0x0000FF00)<<8)|((a&0x000000FF)<<8);
}


int main(int argc, char* argv[])
{
    if(argc !=3){
        printf("Error: You should put 2 files");
        return 0;
    }

    FILE *file1, *file2;

    if ((file1=fopen(argv[1], "rb"))==NULL||(file2=fopen(argv[2], "rb"))==NULL){
        printf("Error: Either files are empty");
        return 0;
    }

    uint32_t num1,  num2;

    fread(&num1, sizeof(uint32_t), 1, file1);
    fread(&num2, sizeof(uint32_t), 1, file2);

    num1 = my_ntohl(num1);
    num2 = my_ntohl(num2);

    fclose(file1);
    fclose(file2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",(int)num1,num1,(int)num2,num2,(int)(num1+num2),num1+num2);
    return 0;
}
