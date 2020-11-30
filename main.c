#define MAX_NAME 30
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct keytab{
	int nums;
	char name[MAX_NAME];
};

struct keytab keywords[13]={
	{0,"int"},
	{0,"float"},
	{0,"return"},
	{0,"if"},
	{0,"for"},
	{0,"while"},
	{0,"goto"},
	{0,"switch"},
	{0,"void"},
	{0,"default"},
	{0,"char"},	
	{0,"do"}		
};

int count_word(char* word){
	int i;
	for(i=0;i<13;i++){
			if(strncmp(keywords[i].name, strlen(keywords[i].name))==0){
				keywords[i].nums++;
				break;
			}		
	}
	return 0;	
}

void print_word(void){
	int i;
	for(i=0;i<13;i++){
		printf("%s : %i\n", keywords[i].name, keywords[i].nums);	
	}	
}

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
