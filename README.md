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
resulted in 2^n subsets or 2^n wall objects. The second to last 
thing we did was organize the walls in terms of most expensive to 
least expensive. We utilized a quick sort function in order to
achieve this and successfully ordered the walls from most expensive
to least expensive. Lastly, we displayed the most expensive wall,
which is a feature in our wall class, displaying the total 
cost of the wall and the paintings that can be found on it in 
a text file called '{inputfilename}-bruteforce.txt’.

### Most Expensive Algorithm:

