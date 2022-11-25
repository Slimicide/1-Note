#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char menu() {

	char option;
	char* menu_options = "\n"
				   "0) Read note.\n"
	               "1) Change note title.\n"
		       	   "2) Change note contents.\n"
		           "3) Malloc / Free 0x88.\n"
		           "4) Malloc / Free 0xf8 #1.\n"
		           "5) Malloc / Free 0xf8 #2.\n"
		           "6) Change note author.\n"
		           "7) Delete note contents.\n"
		           "8) Exit 1-Note. (Seriously, not *that* OneNote.)\n"
		           "Input> ";

	while(1) {

		printf("%s", menu_options);
		option = getchar();

		if(option == '\0') {
			getchar(); //Clear trailing new-line character.
		}

		//47 == '-1', 57 == '9'
		if(option > 47 && option < 57) {
			getchar(); //Clear trailing new-line character.
			break;
		}
	}
	return option;
}

int main() {

	void* title = NULL;
	void* contents = NULL;
	void* theThirdOption = NULL;
	void* theFourthOption = NULL;
	void* theFifthOption = NULL;
	void* author = NULL;

	char buf[0x208];

	printf("\nWelcome to 1-Note. (Not that OneNote)\n"
		   "You only have 1 note to write on. (It's convinient for me.)\n");

	while(1) {

		char option = '\0';
		option = menu();
		switch(option) {

			case '0':
				if(title != NULL){
					printf("\nTitle: %s\n", (char*)title);
				}else{
					printf("\nTitle: Untitled\n");
				}
				if(contents != NULL){
					printf("%s", (char*)contents);
				}else{
					printf("Empty Note");
				}
				if(author != NULL){
					printf("\nAuthor: %s\n", (char*)author);
				}else{
					printf("\nAuthor: Anonymous\n");
				}
				break;

			case '1':
				if(title == NULL){
					title = malloc(0x18);
				}
				printf("\nNew title: ");
				fgets(title, 0x18+1, stdin);
				break;

			case '2':
				if(contents == NULL){
					contents = malloc(0x208);
				}
				printf("\nNew note: ");
				fgets(buf, 0x208+1, stdin);

				if(buf[0] == '\n'){ //If no input is given, don't write '\n\0'.
					buf[0] = '\0';
				}else{
					strcpy(contents, buf); //If input is given, write it to contents.
				}
				break;

			case '3':
				if(theThirdOption == NULL){
					theThirdOption = malloc(0x88);
				}else{
					free(theThirdOption);
					theThirdOption = NULL;
				     }
				break;

			case '4':
				if(theFourthOption == NULL){
					theFourthOption = malloc(0xf8);
				}else{
					free(theFourthOption);
					theFourthOption = NULL;
				}
				break;

			case '5':
				if(theFifthOption == NULL){
					theFifthOption = malloc(0xf8);
				}else{
					free(theFifthOption);
					theFifthOption = NULL;
				     }
				break;

			case '6':
				if(author == NULL){
					author = malloc(0x18);
				}
				printf("\nNew author: ");
				fgets(author, 0x18+1, stdin);
				break;

			case '7':
				if(contents != NULL){
					free(contents);
					contents = NULL;
					break;
				}else{
					printf("\nYour note is already empty.\n");
					break;
				}

			case '8':
				return 0;
		        }
	}
}
