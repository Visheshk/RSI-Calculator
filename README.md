#RSI-Calculator#

##Aim##
Essentially, to make the process of obtaining the list of stocks worth looking into, automated, and easy.
As is right now, put very explicitly, by tracking the RSI (Relative Strength Index) of the stocks.

##What is done at the moment?
rsi-to-txt.c does the following stuff:
* Takes an initial date in the string called name[].
* Has an integer n, which is the number of days whose closing values will be taken into account, to calculate the RSI at the end of the nth day.
From the initial date to n days ahead, it analyzes all the stock values found, as if they were consecutive days. (This functionality can be changed somewhat, but at the moment, this makes sense.) Calculates the RSI for the first 50 stocks (50 is the largest values stline takes in main), and outputs them to a txt file in Output/, with the filename as the last day it took into account, to calculate the RSI. 
The filename as the last day will ideally be of use for the planned rsiupdate program, which using this text file, can simply find the next txt file, read the stocks' data, and make a txt file with updated rsi values.
In the output txt file, at the moment, the array of opening value, closing value, simple moving average of closing values, of opening values, and rsi, is printed. You can also choose to print multiple rows for each stock, as in see rsi changes over numerous days, greater than n, by changing a few values, mainly the range of the second for loop in main(), by running i from a smaller value to day.

###Right Now?
To calculate the RSI of the stocks in the txt files.

The syntax of stock details in the txt files are as such:
<STOCKNAME>, Opening, High, Low, Close, <somerandomnumber>

The output is supposed to be a txt file with the following format:
<STOCKNAME>, RSI, … <other statistical measurements as and when we think of them>,
with the filename being the date.


###Further probable things###
Functionality is to be added in terms of other statistical measurements, whichever seems to be any important value to our active investor. :P 

Ideally, when the user sees the RSI table and says he is interested to see the prices of one these stocks, the program should display a chart of the values of that stock as well. We can even experiment with learning some fancy ass graphics with relation to this. 

##What (How) is the stuff being done?##

// On further specifications, the array within the program will hold the stocks of particular interest, depending upon the newest day's file prepared, and recent low or high rsi values, et al.
/* That means after rsi.c is made to work and prepare the initial text file that is up to date with the latest date, we are required to make an rsiupdate.c, that sees the latest date, the last text file, and prepares the output file for the latest date. We will discuss the detailed working plan of how this will work later.
*/
The current first iteration of this program tries to prepare a table of the RSI of the first stock, in the first ten dates (out of which only 7 happen to be valid).

Things which need to be improved for this.~~

!!
So, instead of preparing a table that is uptodate, we work on rsiupdate.c directly.!!

###Things To Do###
1. Decide number of elements to be used for simple moving average
2. Prepare txt file with every required thing to build upon for further calculation of RSI - in kind of the following format
<stockname>, Simple Moving Average of ( up value (U) ),Simple Moving Average of ( down value (D) )
with the filename as the date upto which it sees.
3. Add ability to do this for all rows, moving beyond doing it for just the first stock.
4. Analyze every condition for adding 1 to the date. (!), and make a corresponding add_to_date function.
5. Prepare updatersi.c which (obviously enough), updates the rsi, for the next available date.
6. Do something about getting this to work on Windows (bah :P).

##License##
None yet. But if you start using this, and make profit out of it, I'd be much obliged if you shared some with me. Actually, I'd be happy to know it even helped you at all, if it did. So at least tell me a bit. :)
