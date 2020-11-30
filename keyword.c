#define NKEYS 13
#include <stdio.h>
#include <stdlib.h>
#include <keywords.h>
struct keytab keywrds[NKEYS];

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
	cnt = 0;
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

