#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h> 
int main() {
	int i;
    char inputNum[5]; // Increase array size to store '\0'
    char randNum[5]; // Increase array size to store '\0'
    srand(time(0));
        
    // Generate 4 random digits and store them in randNum
    for (i = 0; i < 4; i++) {
        randNum[i] = '0' + rand() % 10; // Convert random int to a char digit (0 to 9)
    }
    randNum[4] = '\0'; // Null-terminate the string
    while (1) {
        printf("Enter a 4-digit number: ");
        scanf("%s", inputNum);
        // Check if the input is valid (4 digits)
        if (strcmp(inputNum, "S") == 0) {
            printf("The answer is: %s\n", randNum);
            break;
        }
        if (strlen(inputNum) != 4) {
            printf("Invalid input! Please enter a 4-digit number.\n");
            continue;
        }
                // Check if the input is 'S' to reveal the answer


        // Check for correct numbers and positions (1A)
        int countA = 0;
        for (i = 0; i < 4; i++) {
            if (inputNum[i] == randNum[i]) {
                countA++;
            }
        }

        // Check for correct numbers but wrong positions (2B)
        int countB = 0;
        for (i = 0; i < 4; i++) {
            int j;
            for (j = 0; j < 4; j++) {
                if (inputNum[i] == randNum[j] && i != j) {
                    countB++;
                }
            }
        }

        // Print the result
        printf("%dA%dB\n", countA, countB);

        // Check if the user guessed the number correctly
        if (countA == 4) {
            printf("Congratulations! You guessed the number correctly.\n");
            break;
        }
    }
    return 0;
}
////A.
//typedef struct{
//	unsigned short int type;
//	unsigned int size;
//	unsigned short int reserved[2];
//	unsigned int offset; //bug
//}fileHeader;
////B
//void fileHeaderWrite(FILE *fp,fileHeader *fh){
//	fwrite(&fh->type,sizeof(unsigned short int),1,fp);
//	fwrite(&fh->size,sizeof(unsigned int),1,fp);
//	fwrite(&fh->reserved,2*sizeof(unsigned short int),1,fp);
//	fwrite(&fh->offset,sizeof(unsigned int),1,fp);//bug
//}
////C
//typedef struct{
//	unsigned int infosize;
//	int width,height;
//	unsigned short int planes;
//	unsigned short int bits;
//	unsigned int compression;
//	unsigned int imagesize;
//	int xresolution,yresolution;
//	unsigned int ncolors;
//	unsigned int importancecolord;
//}infoHeader;
////D
//void infoHeaderWrite(FILE *fp,infoHeader *ih){
//	fwrite(&ih->infosize,sizeof(unsigned int),1,fp);
//	fwrite(&ih->width,sizeof(int),1,fp);
//	fwrite(&ih->height,sizeof(int),1,fp);
//	fwrite(&ih->planes,sizeof(unsigned short int),1,fp);
//	fwrite(&ih->bits,sizeof(unsigned short int),1,fp);
//	fwrite(&ih->compression,sizeof(unsigned int),1,fp);
//	fwrite(&ih->imagesize,sizeof(unsigned int),1,fp);
//	fwrite(&ih->xresolution,sizeof(int),1,fp);
//	fwrite(&ih->yresolution,sizeof(int),1,fp);
//	fwrite(&ih->ncolors,sizeof(unsigned int),1,fp);
//	fwrite(&ih->importancecolord,sizeof(unsigned int),1,fp);
//}
////E
////BGRA«¬ºA©w¸qred¡Bblue¡Bgreen¡Bwhite blue={0,255,0,0}
//typedef struct{
//	unsigned char b;
//	unsigned char g;
//	unsigned char r;
//	unsigned char a;
//}BGRA;
////F
//unsigned char interValue(unsigned char a,unsigned char b,double i,double total){
//	return i/total *a +(total-i)/total*b;
//}
////G
//BGRA interBGRA(BGRA color1,BGRA color2,int i,int total){
//	BGRA value={interValue(color1.b,color2.b,i,total),
//	interValue(color1.g,color2.g,i,total),
//	interValue(color1.r,color2.r,i,total),
//	interValue(color1.a,color2.a,i,total)
//	};
//	return value;
//}
////H
//BGRA average(BGRA color){
//	double average=((double)color.b+color.g+color.r)/3;
//	BGRA value={average,average,average,0};
//	return value;
//}
////I
//int main(){
//	//step1
//	int width=1024;
//	int height=1024;
//	//step2
//	fileHeader file1={0x4d42,54 +width*height*4,{0,0},54};
//	infoHeader info1={40,width,height,1,32,0,64,4,4,4,4};
//	//step3
//	FILE *fp =fopen("output.bmp","wb");
//	
//	fileHeaderWrite(fp,&file1);
//	infoHeaderWrite(fp,&info1);
//	int i,j;
//	const BGRA red={0,0,255,0},blue={255,0,0,0},green={0,255,0,0},white={255,255,255,0};
//	for(i=0;i<width;i++){
//		for(j=0;j<height;j++){
//			BGRA color=interBGRA(interBGRA(red,blue,i,width),interBGRA(green,white,i,width),j,height);	
//			fwrite(&color,sizeof(BGRA),1,fp);//bug
//		}
//	}
//	fclose(fp);
//}
//
//
//

