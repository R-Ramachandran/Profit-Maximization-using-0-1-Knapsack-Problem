# Profit Maximization using 0/1 Knapsack Problem
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This project helps to maximise the profit using 0/1 Knapsack problem. This also uses dynamic programming approach to solve the 
problem efficiently (i.e., having less time complexity).

## Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A knapsack is a sack or bag that can be filled up to the given maximum weight. Here, each of the object have some value (i.e. worth) and some weight. Also, these objects are indivisible. So, we can’t divide the object into its fractional parts accordingly to fill the sack. This is the reason why we give the name 0/1 knapsack, which means ‘0’ indicates that the particular object is not taken and ‘1’ indicates that the particular object is taken in the sack (like we use in digital logics). Our aim is to fill the sack such that we get the maximum profit(value) and the weight of all the objects that are taken should be less than are equal to the maximum capacity of the bag (i.e. maximum weight capacity). In mathematical terms,
Maximum(&sum; p[i]x[i] , &sum; w[i]x[i]) <= W <br> <br>
Where,<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;p[i] = The profit of that particular object.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;w[i] = The weight of that particular object.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;x[i] = 1 or 0(i.e., object is taken or left behind respectively)<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;W = Maximum weight capacity of the sack.<br> <br>
For example, let us consider a situation where we need to pack a bag such that the contents provide maximum value without exceeding our bag’s capacity. We assume that we have a Knapsack that can hold at most 5 Kgs and have the following items.

<table>
  <thead>
    <tr>
      <th>Things</th>
      <th>Value</th>
      <th>Weight</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Clock</td>
      <td>450</td>
      <td>0.5 Kg</td>
    </tr>
    <tr>
      <td>Painting</td>
      <td>500</td>
      <td>0.5 Kg</td>
    </tr>
    <tr>
      <td>Radio</td>
      <td>1250</td>
      <td>1 Kg</td>
    </tr>
    <tr>
      <td>Laptop</td>
      <td>45000</td>
      <td>2 Kgs</td>
    </tr>
    <tr>
      <td>Grinder</td>
      <td>5000</td>
      <td>2 Kgs</td>
    </tr>
    <tr>
      <td>DVD Player</td>
      <td>5000</td>
      <td>1 Kg</td>
    </tr>
  </tbody>
</table>

<ul>
  <li>
    To solve this problem, we use different kinds of algorithms like backtracking, greedy, dynamic programming, brute-force etc.
  </li>
  <li>
    The main goal is to present the comparative study of the approaches to find the performance of the different algorithms used
    to solve the 0/1 Knapsack problem, based on the time complexity of each algorithm.
  </li>
</ul>

In our program, we take-
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Maximum weight&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;&nbsp;&nbsp;&nbsp; Initial Investment<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Individual weights&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;&nbsp;&nbsp;&nbsp; Individual prices of the stock items<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Individual values&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;&nbsp;&nbsp;&nbsp; Individual profits on selling the stock items<br>
<br>
So, our aim is to get maximum profit by using our investment wisely.<br>
<ul>
  <li>
    The program uses the concept of data structures as well as algorithms.
  </li>
  <li>
    To solve the knapsack, we use the concept of queues and linked list data structures and do dynamic programming in order to get maximum profit for the company.
  </li>
  <li>
    The comparison of the algorithms is the concept derived from algorithms where we compare the time taken to compile (time complexity) when the data is passed using brute force, dynamic programming, greedy and back tracking approaches.
  </li>
</ul>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;While we do this, we find out that dynamic programming is the fastest and the most efficient way of solving the knapsack problem due to the least time taken to compile.
We have various member functions in order to add stock items, display stock items, delete stock items, alter the price or the profit of a stock item and so on, adding functionality to our program.

## Note :
<ul>
  <li>
    This project is done just to see how the 0/1 Knapsack Problem is useful and also to show how to implement 0/1 Knapsack Problem in our Real life.
  </li>
  <li>
    Not for the purpose of user friendly application like android app, web app, etc.. It's just a C++ program.
  </li>
</ul>
