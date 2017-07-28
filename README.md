Name: Minh Nguyen
SID: 104836836

/**************/
Final Project CSCI-2270

Summary:
Idea: The program use in a library with directions for folks to get to different stacks and self-checkout.
Method (Data Struct): The map will be a weighted undirected graph with 6 vertices (represent 6 different stacks in the library). And each vertices is a root of a binary search tree
---Menu----
1. Search for book // check book status using title
2. Check-in book 
3. Check-out book 
4. Look at the map // print out vertices connection
5. Shortest path to stack // Dijkstra Algorithm
6. Print out book in stack
7. Re-enter location // re-enter starting location
8. Quit

User can use the program to access to library information in case they don't find anyone to help. User have option to self-checkout and self-checkin.
User can use the program to find the shortest path to a stack or an overlook on the whole library stacks.

How to run:
1. For the program to run, please download 3 files: graph.hpp graph.cpp project.cpp list_of_book.txt
2. To run the program:
if you using linux, compile in terminal and run it.
For example: $g++ -std=c++11 project.cpp   //to compile
./a.out // to run
if using third-party, open project.cpp compile and run.

Dependencies:
N/A

System Requirements:
Windows and Linux both work.

Issues:
When starting the program, if you type in the wrong code. It will return weird results in options in the main menu.
You will get infinite loop if you enter anythings other than number when menu pop up.
