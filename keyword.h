#define MAX_NAME 30
#include <stdio.h>
#include <stdlib.h>


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
