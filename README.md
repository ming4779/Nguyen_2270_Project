Name: Minh Nguyen
SID: 104836836

/**************/
Final Project CSCI-2270

Summary:
Idea: The program use in a library with directions for folks to get to different stacks and self-checkout.
Method (Data Struct): The map will be a weighted undirected graph with 5 vertices (represent 5 different stacks in the library). And each vertices is a root of a binary search tree
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
I For the program to run, please download 3 files: graph.hpp project.cpp list_of_book.txt
2. After download the program, if you using linux, compile in terminal and run it.
if using third-party, open project.cpp compile and run.

Dependencies:
N/A

System Requirements:
Windows and Linux both work.

Issues:
When starting the program, if you type in the wrong code. It will return weird results in options in the main menu.
