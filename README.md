# Art Gallery Project

## 22s-pa01-kas-and-clayton GitHub 
- https://github.com/smu-cs-3353/22s-pa01-kas-and-clayton

##Problem
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;For businesses, it is most important to ensure maximization of profitability. 
Let's assume that you have an art gallery, how would you achieve the maximum
profitability while being efficient? <br />
>The goal of this project is to develop an efficient
algorithm that tells the owner of the art gallery what is the most optimal way 
of putting art paintings on the wall of the gallery in order to achieve 
the maximum potential profit.

##Build and Run From Terminal
###Build:

>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-clone the project from GitHub<br />
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-using cd to get to the designated project<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-once you are in the project folder then use 
command line mkdir to create a build &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;folder by typing mkdir nameOfTheFolder<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-use command line cd to go to the folder that you just created<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-now you are ready to build your project<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-use command line cmake .. to add cmake to the folder<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-now to build the cmake use the command line cmake --build .<br />
### Run:
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-Use command line cd to go to the cmake-build-debug folder<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-In this folder you should be able to see a folder with the same name is your &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;project<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-Use command line ./name of your project input/the absolute path of your input file<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
-Good Job! you have build and run your project from terminal 

##Algorithms
### Brute Force:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; One of the most important algorithms 
in this project is brute force algorithm as is the most accurate algorithm
for maximizing the profitability while being the worst algorithm to use 
because of its incredible inefficiency since we are testing all possible
ways to put the most suitable paintings on the wall.<br />
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; We started our journey to this project
by implementing the brute force algorithm as was suspected that this 
algorithm will take the most amount of time to implement and optimize. 
To implement this algorithm, we created a Painting class 
that contains all the information about each painting, 
including the ID, price, height, and width then we established 
a Wall class that contains a vector of paintings to be 
on that wall as well as a variable that tracks the 
amount of space remaining on the wall. From there, we defined an 
algorithm that created every possible subset of the number of paintings which 
resulted in 2^n subsets or 2^n wall objects. <br />
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The second to last 
thing we did was organize the walls in terms of most expensive to 
least expensive. We utilized a quick sort function in order to
achieve this and successfully ordered the walls from most expensive
to least expensive. Lastly, we displayed the most expensive wall,
which is a feature in our wall class, displaying the total 
cost of the wall and the paintings that can be found on it in 
a text file called '{inputfilename}-bruteforce.txt’.

### Most Expensive Algorithm:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Most expensive algorithm is a fast way to achieve
an expensive wall of paintings but without the optimization to make sure
that we are using the wall as efficiently as possible to achieve the most
expensive wall possible.<br />
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; After implementing the brute force 
algorithm, we decided to give ourselves a break by working on the 
most expensive algorithm as we thought it would be the easiest algorithm
to implement. This algorithm aims 
to put paintings on the wall in order of most expensive to 
least expensive, so the first thing that the function does is to
order the paintings in terms of most to least expensive utilizing 
the same quick sort function as from the brute force algorithm.
From there, we added paintings to the wall in that order.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; We utilize the variable "widthRemaining" in order to skip over 
paintings that would not be able to fit on the wall and then looping through 
the entire list of paintings and adding them as many as possible until 
no more paintings can be fitted on the wall. This algorithm provides 
the most expensive paintings that can be fitted on the wall, 
but does not take into account the size of the painting,
leaving room for an inefficient algorithm as one painting 
could take up the entire wall if it is the most expensive painting, 
not providing profit maximization to the art gallery.

### Custom Algorithm:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; This was the most fun algorithm that worked
on to implement as we had to find creative ways to find the most efficient 
algorithm as possible as we could to achieve the most expensive wall as fast
as possible while maximizing the potential profitability for the art gallery.<br />
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; This algorithm takes both painting 
price and painting width in order to create a price per unit 
width (ppuw) variable in the painting class. We got inspiration 
to implement out algorithm this way from the housing market 
and way that houses are sold which is price per foot. similar to a price
per square foot number that you’d find when in the market for a 
new house. This implementation will allow the art gallery to choose
the paintings in way to achieve most expensive wall by ordering
the most valuable per inch of wall which will allow the gallery 
to maximize their profit with the space that they have.<br />
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; We sorted the 
paintings vector using the same quick sort implementation as 
before, except this time it was ordered by the price per unit
width variable allowing the algorithm to place painting on 
the wall based on the value of the paintings unit width, rather 
than the painting as a whole, putting the relatively most valuable 
paintings at the front and the least valuable paintings per unit
width in the back. Similar to the most expensive painting first 
algorithm, this adds paintings based on the price per unit width and 
similarly tracks the amount of remaining space on the wall,
skipping over paintings if there is not enough space to
include them on the wall. This algorithm provides solutions
similar to that of the perfect brute force algorithm while being 
so much faster because of the optimization that has been implemented in
this algorithm.

## Time Complexity
### Brute Force:
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Although producing the most optimal 
> output as the number of painting increases the time complexity of
> 2^n increases and as the result of increase in the number of subsets
> this algorithm gets exponentially slower. As the result of 
> slowness of this algorithm we only were able to generate output 
> on a data set of size 29 which took 423 seconds for the program 
> to get executed. Below is a graph:<br />
> 
> ![Alt text](/Users/kasrataghavi/Desktop/Screen Shot 2022-02-14 at 12.45.28 AM.png)
> 

### Most Expensive:
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; This algorithm provides a quick but not
> optimize solution as it is the fastest algorithm out of the 3 
>  that were implemented for this project and due to the 
> sorting algorithm the time complexity is O(n^2). Using python
> we generated random data sets of 100, 1k, 10k and 100k and tested
> this algorithm as well as our custom algorithm with those data sets.

### Custom:
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Our custom algorithm achieves  
> an optimized solution that is as perfect as our brute force
> algorithm does while being wildly faster and just slightly slower
> than most expensive algorithm which is the fastest algorithm with
> the time complexity of O(n^2). Below is a graph which shows 
> the efficiency of this algorithm in terms of generating the most
> valuable wall while not being much slower than the most
> expensive algorithm:
> 
> ![Alt text](/Users/kasrataghavi/Desktop/Screen Shot 2022-02-14 at 12.45.34 AM.png)
> 
> ![Alt text](/Users/kasrataghavi/Desktop/Screen Shot 2022-02-14 at 1.07.52 AM.png)
>