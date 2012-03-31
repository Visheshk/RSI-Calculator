#include <stdio.h>
#include <math.h>



float converttofloat(int str[], int len)
{
	int i = 0, dec = len;
	for(i = 0; i < len; i++){
//		printf("%d ", str[i]);
		if(str[i] == 46)
			dec = i;
	}
	float val = 0;
	int k = 0;
	for(i = dec - 1; i >= 0; i--){
//		printf("%d ", str[i]);
		val += (str[i] - 48) * pow(10, k);
		k++;
	}
//	printf("%f", val);
	if(dec != len){
	k = -1;
	for(i = dec + 1; str[i] != 0; i++){
//		printf("%d ", str[i]);
		val += (str[i] - 48) * pow(10, k);
//		printf("%f ", val);
		k--;
	}
	}
	return val;
}

int updateud(float today[][5], int day){
	today[day][2] = 0; 	today[day][3] = 0;
	if(today[day][1] >= today[day - 1][1])
		today[day][2] = today[day][1] - today[day - 1][1];
	else
		today[day][3] = today[day - 1][1] - today[day][1];
	return 0;
}

int nextcomma(FILE *fl, int co){
	while(co!=44) 			//find comma
		co = fgetc(fl);		//find comma
	co = fgetc(fl);
	return co;
}

int oneday(char name[], float today[][5], int day, int stline) {
	FILE* fl;
	//fl = fopen("01-06-2011.txt","r");
//	char name[]="01-06-2011.txt";
	fl = fopen(name, "r");
	if(fl != NULL){
	int op[15], cl[10], co = fgetc(fl);
	int i = 0;
	while(i < stline && co != 13) {
		co = fgetc(fl);
	}
	co = fgetc(fl);
	co = nextcomma(fl, co);	
	co = nextcomma(fl, co);
	i = 0;
	while(co != 44){
		op[i] = co;
		i++;
		co = fgetc(fl);
	}					//obtain opening value
	
	int lo = i, lc = 0; // lo - length of opening; lc - length of closing
	op[i] = 0;				//set comma obtained extra value to 0
	co = fgetc(fl);
	
	co = nextcomma(fl, co);
	co = nextcomma(fl, co);
	
	i = 0;
	while(co != 44){
		cl[i] = co;
		i++;
		co = fgetc(fl);
	}						//obtain closing value
	lc = i;
	cl[i] = 0;
	int deco = 0, decc = 0; //deco - decimal point of opening value
	
	today[day][0] = converttofloat(op, lo);
	today[day][1] = converttofloat(cl, lc);
	if(day > 0){
		updateud(today, day);
	}
	return 0;}
	else
		return 12;
	printf("%f", today[day][0]);
	
}

float calcrsi(float today[][5], int n){
	int i = 0;
	float smova[100][2]; //simple moving average [n][U], [][D]
	//rs[n] = [n][0]/ [n][1]
	//rs[n] = f (rs[n]) = 100 - (100 / (1 + rs[n])) 
	float avgu = 0, avgd = 0;
	for(; i < 100; i++){
		smova[i][0] = 0;
		smova[i][1] = 0;
	}
	i = 1;
//	smova[0][0] = today[0][2]; smova[0][1] = today[0][3]; // initial values, anyway zero
	for (; i < n; i++){
		smova[i][0] = today[i][2] + smova[i - 1][0];
		smova[i][1] += today[i][3] + smova[i - 1][1];
	}
	i--;
	smova[i][0] /= n; smova[i][1] /= n;
//	printf("\n%f\n", smova[i][0]);
	float rs;
	if(smova[i][1] == 0)
		rs == 100;
	else{
		rs = smova[i][0] / smova[i][1];
		rs += 1.0;
		rs = 100.0 / rs;
		rs = 100.0 - rs;
	}
//	printf("\n\n%f\n\n", rs);
	today[i][4] = rs;
	rs = 0;
	i++;
//	printf("\n%f\n", rs);
	while(today[i][0] != 0.000){
		smova[i][0] = smova[i - 1][0] + ((today[i][2] / n) - (today[i - n][2]/n));
		smova[i][1] = smova[i - 1][1] + ((today[i][3] / n) - (today[i - n][3]/n));
		if(smova[i][1] == 0)
			rs == 100;
		else{
			rs = smova[i][0] / smova[i][1];
			rs += 1.0;
			rs = 100 / rs;
			rs = 100 - rs;
		}
		today[i][4] = rs;
		rs = 0;
		i++;
	}
	int l = 0;
//	printf("\n"); // to print smova's both columns, to check obtained simple moving averages
	for(; l < 10;  l++){
//		printf("%f\t%f\n", smova[l][0], smova[l][1]);
	}
//	printf("\n");
}

int main(){
	int stline = 0;
	while(stline <= 1){
	float today[100][5]; //today[row number][opening], [][closing], [][U], [][D], [][rsi]
	int day = 0, i = 0;
	char name[] = "Stocks/01-06-2011.txt";
	for(; i < 10; i++){
		if(oneday(name, today, day, stline) == 0)
			day++;
		name[8]++;
	}
	today[0][2] == 0; today[0][3] == 0;
	oneday(name, today, day, stline);
	int n = 3;
	calcrsi(today, n);	
	for(i = 0; i < 10; i++){
		printf("%f\t%f\t%f\t%f\t%f\n", today[i][0], today[i][1], today[i][2], today[i][3], today[i][4]);
	}
	printf("\n");
	stline++;
	}
}

