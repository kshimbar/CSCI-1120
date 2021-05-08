#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){
	char input[20];
	printf("Enter a line of text: \n");
	scanf("%s", input);
	printf("Input '%s'\n", input);
	int length;
	length = 0;
	while(input[length] != '\0'){
		++length;
	}
	for(int i = 0; i < length; ++i){
		if(isalpha(input[i])){
			input[i] = tolower(input[i]);	
		}
	}
	int indexright, indexleft;
	indexright = 0;
	indexleft = length - 1;
	bool check = true;
	while(indexright < indexleft && check){
		if(isalpha(input[indexright]) && isalpha(input[indexleft])){
			check = input[indexright] == input[indexleft];
			indexright = indexright + 1;
			indexleft = indexleft - 1;
		}
		if(isalpha(input[indexright]) && !isalpha(input[indexleft])){
			indexleft = indexleft - 1;
		}
		if(!isalpha(input[indexright]) && isalpha(input[indexleft])){
			indexright = indexright + 1;
		}
	}
	if(check){
		printf("a palindrome");
	} else{
		printf("not a palindrome");
	}
	printf("\n");
	
	return 0;
} 
