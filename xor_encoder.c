#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void xorCripto(char *msg, char *key){

	int i = 0;

	while(msg[i] != '\0'){
		msg[i] = msg[i] ^ key[i % strlen(key)];
		i++;
	}

	for(i = 0; msg[i] != 0; i++){
		if(isprint(msg[i])){
			printf("\033[34;1m%c", msg[i]);
		}else{
			char hardChars[] = {'!', '@', '#', '$', '%', '&'};
			int numChars = sizeof(hardChars) / sizeof(char);
			int randomChar = rand() % numChars;
			printf("\033[31;1m%c", hardChars[randomChar]);
		}
	}
	printf("\n");
}

int main(int argc, char **argv){

	srand(time(NULL));

	if(argc != 3){
		printf("\n\033[35;1m====================\n");
		printf("     X0R 3NC0D3     \n");
		printf("       By Uzu       \n");
		printf("====================\n\n");
		printf("\033[31;1m[!] Usage: %s \"password\" \"key\"\n\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *passwordXor = argv[1];
	char *keyEncode = argv[2];

	xorCripto(passwordXor, keyEncode);

	return 0;
}
