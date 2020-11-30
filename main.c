#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int is_whitespace(char c){
	if (c ==' '||
		c== '\n'||
		c==	'\r'||
		c==	'\t'||
		c=='(')
		return 1;
		
	return 0;
	
}

int fget_word(FILE* fp, char* word){
	char c;
	int cnt;
	
	while((c==fgetc(fp))!=EOF){
		if(is_whitespace(c) == 0)
		break;
	}
	if(c == EOF)
		return 0;
		
	//filling out the word
	cnt =0;
	word[cnt++]=c;
	word[cnt]='\0';
	
	while((word[cnt]=fgetc(fp))!=EOF){
		if(is_whitespace(word[cnt])==1){
			word[cnt]='\0';
			break;
			
		}
		cnt++;
	}
	return cnt;
}


int main(int argc, char *argv[]) {

	FILE* fp;
	char filename[100];
	char word[100];
	int cnt;
	
	//file open
	printf("input the file name : ");
	scanf("%s", filename);
	
	if((fp = fopen(filename, "r"))==NULL)
	{
		printf("input filename is invalid\n");
		return -1;
	}
	
	//bring word from fp
	while(fget_word(fp, word) != 0){	//bring a word
		count_word(word);
	}
	
	print_word();
	
	fclose(fp);
	
	
	return 0;
}
