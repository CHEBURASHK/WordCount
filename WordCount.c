#include <stdio.h>
#include <string.h>
#include<malloc.h>
int countw(char *filename);
int countc(char *filename);

int main(int argc,char* argv[]){
    char filname[30];
    char operation;
    int toalchar;//字符数
    int totalword;//单词数
    if(!strcmp(argv[1],"-w")) 
    countw(argv[2]); 
    else if(!strcmp(argv[1],"-c")) 
    countc(argv[2]); 
}

int countw(char *filename){
    FILE *fp=NULL;
    char buffer[1003]; 
    int bufferLen; 
    int i; 
    char c; 
    int isLastBlank = 0; 
    int totalword=0;
    int wordNum = 0; 
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return 0;
    }
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t' || c==','){ 
                !isLastBlank && wordNum++; //当上一个不是空格，而这一个是空格时单词数+1 
                isLastBlank = 1;//表明一个空格
           }
		   else if(c!='\n'&&c!='\r'){ 
               isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++; 
        isLastBlank = 1; 
        totalword += wordNum; 
        wordNum = 0;
    }
    printf("单词数:%d ",totalword);
    fclose(fp);
    return 0;
}

int countc(char *filename){
    FILE *fp=NULL;
    char buffer[1003]; 
    int bufferLen; 
    int i; 
    char c; 
    int totalchar=0;
    int charNum = 0; 
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return 0;
    }
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if(c!='\r'){ 
                charNum++;
            }
        }
        totalchar += charNum; 
        charNum = 0;
    }
    printf("字符数:%d",totalchar);
    fclose(fp);
    return 0;
}

 
