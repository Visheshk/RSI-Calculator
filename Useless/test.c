#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fl;
	fl = fopen("Stocks/01-06-2011.txt", "r");
	int co = 0;
	while (co != 12) {
		co = fgetc(fl);
		printf("%c", co, co);
	}
}