#include <stdio.h>

int main(int argc, char *argv[]) {
	char name[] = "Stocks/01-06-2011.txt"; //DD-MM-YYYY
	//   name[] = "0123456789-123456
	//add 1 to the main part of date
	int i = 0;
	while(i < 365){
	if((int) name[8] < 57)
		name[8]++; //make 01 to 02 and so on
	else if((int) name[8] == 57){
		name[8] = 48;
		name[7]++; // make 09 to 10
	}
	
	if((int) name[8] == 50 && (int) name[7] == 51){ //make 32-0x to 01-MM + 1
		name[8] = 49;
		name[7] = 48;
		name[11]++;
	}
	
	if((int) name[11] == 58){ //converting DD-0: to DD-10
		name[11] = 48;
		name[10]++;
	}
	
	if((int) name[10] == 49 && (int) name[11] == 51){ //converting DD-13-YYYY to DD-01-YYY(Y+1)
		name[10] = 48;
		name[11] = 49;
		name[16]++;
	}
	
	if((int) name[16] == 58){ // converting dd-mm-yyy: to dd-mm-yy(y+1)0
		name[16] = 48;
		name[15]++;
	}
	printf("%s\n", name);
	i++;
	}
}