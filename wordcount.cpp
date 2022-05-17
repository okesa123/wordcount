#include <stdio.h>
#include <string.h>
int *WordCount(char *filename, int *Num);
int main(){
    char filename[99];
    int Num[3];
    printf("输入需要查看的文件: ");
    scanf("%s", filename);
    if(WordCount(filename, Num))
        printf("合计: %d 行,  %d 字符, %d 单词\n", Num[0], Num[1], Num[2]);
    
    

    return 0;
}

int *WordCount(char *filename, int *Num){
    FILE *fp;char huanchongqu[9999]; int LEN; int i;char nowReading;int Blank = 0;int charNum = 0; int word = 0; 
    if( (fp=fopen(filename, "r")) == NULL )
	{
        perror(filename);
        return NULL;
    }
    while(fgets(huanchongqu, 9999, fp) != NULL){
        LEN = strlen(huanchongqu);

        for(i=0; i<LEN; i++){
            nowReading = huanchongqu[i];
            if( nowReading==' ' || nowReading=='\t'){ 
                !Blank && word++; 
                Blank = 1;
            }else if(nowReading!='\n'&&nowReading!='\r'){ 
                charNum++; 
                Blank = 0;
            }
        }
        !Blank && word++;
        Blank = 1; 

        Num[0]++; 
        Num[1] += charNum;  
        Num[2] += word;  
        charNum = 0;
        word = 0;
    }
    return Num;
}
