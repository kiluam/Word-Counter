#include <stdio.h>

#define ONSTATE 1		/*reading a valid character*/ 
#define OFFSTATE 0  	/*yet to start reading or just finished reading a valid word*/

void main(){
	int wc = 0;				/*word counter*/
	int state = OFFSTATE;	/*yet to start reading*/
	char c;					/*I'm the present character*/ 
	FILE *fopen(), *fp;
	fp = fopen("textfile.txt", "r"); /*Put your filename here. Replace textfile.txt with your file.*/
	while ((c = getc(fp)) != EOF){
		if ((c >= 65 && c <= 122 )||(c >= 48 && c <= 57 )){ /*printf("%d \n %d", '0','9') o/p 48 57*/
			state = ONSTATE;
			// printf("%d", c);	/*uncomment if you want to see the words read*/
		}
		else if (state == ONSTATE && (c == ' ' || c == '\n' || c == '\t' )){ /*space, newline and tab*/
			wc++; 				/*update word counter*/
			state = OFFSTATE;
		}
	}
	printf("%d", wc);
}