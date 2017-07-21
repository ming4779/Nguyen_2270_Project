# Nguyen_2270_Project
CSCI-2270 Final Project

Phase 1:
Idea: Kind of surviving game but more like a finding quest. Player ultimate goal is finding the Eye of Blind.
Method (Data Struct): The map will be a weighted undirected graph with at least 7 vertices. And each vertices is a root of a singly linked list
Rule: The player start with 5 action points(AP) (properly recalculate later)
The player will be able to choose the starting vertex at the beginning. 
Each time player move to the different vertices they will lost from 1-3 action points base on the distance of the edges
Player can choose what to do in every vetices using action list (linked list)
The menu would be like
---Action----
1. Look at your status //show your AP
2. Look at the map // map will show which vertices connect to which
3. Travel // moving between vertices
4. What to do // cout choice in the linked list(explain below)
5. Go to doctor //Get rid of disease but lost AP
6. Rest //Gain 2 AP but each city only use 2 times
7. Replay 
8. Quit


Action list(linked list)
All the nodes are number. Player option will be 1-4
Each option will has random stuff from disease that cost player AP (e.g. Everytime move lost an extra AP)
Or a stupid riddle I brought down from the internet answer right get AP otherwise lost AP
Or monster encounter lost AP or chess which will random the number (each number has different case in it)

