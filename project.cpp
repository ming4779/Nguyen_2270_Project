#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include "graph.hpp"

using namespace std;


// Start

Graph::Graph()
{
    root = nullptr;
}

Graph::~Graph()
{
}

void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}


void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.visited = false;
        v.distance = 0;
        v.solved = false;
        v.parentG = nullptr;
        v.treeRoot = nullptr;
        vertices.push_back(v);

    }

}

bool Graph::checkVertex(string a){
    bool b = false;
    for(int i=0;i<vertices.size(); i++){
        if(vertices[i].name == a){
            b = true;
        }
    }
    return b;
}

vertex Graph::searchVer(string stackName){
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].name == stackName){
            return vertices[i];
        }
    }
}


int Graph::searchIndex(string stackName){
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].name == stackName){
            return i;
        }
    }
}

void Graph::BFS(string title){
   vertex vx = searchVer(title);
   queue <vertex> q;
   q.push(vx);
   while(!q.empty()){
        vertex n = q.front();
        n.visited = true;
        vertex a = q.back();
        cout<< n.name<<endl;
        q.pop();
        for(int i=0; i<n.adj.size(); i++){
            if(n.adj[i].v->visited == false){
                cout<<"adjacent "<<n.adj[i].v->name<<endl;
                cout<<n.adj[i].v->visited<<endl;
                n.adj[i].v->visited = true;

                q.push(searchVer(n.adj[i].v->name));
            }
        }
   }
}

void Graph::dijkstra(string start, string last){
    vertex *solvedV;

    for(int i=0; i<vertices.size(); i++){
        vertices[i].solved = false;
        vertices[i].visited = false;
        vertices[i].distance = 0;
    }
    vertex* startV = &vertices[searchIndex(start)];
    vertex* endV = &vertices[searchIndex(last)];
    startV->solved = true;
    startV->visited = true;
    startV->distance = 0;
    startV->parentG = nullptr;
    vector <vertex*> solved(0);
    solved.push_back(startV);
    while(!endV->solved){
        vertex *parent = new vertex;
        int minDist = INT_MAX;
        vector <vertex*> tempVisit(0);
        for(int x = 0; x<solved.size();x++){
            vertex *s = solved[x];
            for(int y=0;y<s->adj.size();y++){
                if(!s->adj[y].v->solved && !s->adj[y].v->visited){
                    int dist = s->distance + s->adj[y].weight;
                    if(dist<minDist){
                        solvedV = s->adj[y].v;
                        minDist = dist;
                        parent = s;
                    }
                }
            }
        }
        if(!solvedV->visited){
            solvedV->distance = minDist;
            solvedV->parentG = parent;
            solvedV->solved = true;
            solvedV->visited = true;
            solved.push_back(solvedV);
        }
        if(solved.back()->name == endV->name){
            endV->solved = true;
        }
    }

    //Print out shortest path
    int count = 0;
    int nan = 0;
    vertex *temp = solved.back();
    while(temp != nullptr){
        temp = temp->parentG;
        count++;
    }
    string namea[count];
    vertex *temp1 = solved.back();
    while(temp1 != nullptr){
        namea[nan]=temp1->name;
        temp1 = temp1->parentG;
        nan++;
    }
    cout<<"Your shortest path is"<<endl;
    cout<<"****_____________****"<<endl;
    for(int i =1;i<count;i++){
        cout<<convert(namea[count-i])<<"-->";
    }
    cout<<convert(namea[0])<<endl;
}

void Graph::printVer(){
    for(int i=0; i<vertices.size(); i++){
        cout<<vertices[i].name<<endl;
    }
}

//Binary Search Tree

void Graph::insertBook(Node*node){
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i].name == node->type){
            vertices[i].treeRoot = root;
        }
    }
    if(root == nullptr){
        root = node;
    }
    else{
        Node *temp = root;
        Node *parent = new Node("","","",-1,1,nullptr,nullptr,nullptr);
        while(temp != nullptr){


            parent = temp;
            if(node->title < temp->title){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(node->title < parent->title){
            parent->left = node;
            node->parent = parent;
        }
        else{
            parent->right = node;
            node->parent = parent;
        }
    }

}

Node *Graph::binarySearch(Node *node, string name){

    if(node!=nullptr){
        if(node->title == name){
            return node;
        }
        else if(name < node->title){
            return binarySearch(node->left,name);
        }
        else{
            return binarySearch(node->right,name);
        }
    }
    else{
        return nullptr;
    }

}

//Print book

void Graph::traversePrint(Node *currentNode){

    if(currentNode->left != NULL)
    {
        traversePrint(currentNode->left);

    }
    cout<<"Book title: "<<currentNode->title<<" Author: "<<currentNode->author<<" Publish in "<<currentNode->year<<endl;
    if(currentNode->right != NULL)
    {
        traversePrint(currentNode->right);
    }

}

//Build map & tree

void Graph::buildMap(){
    addVertex("norst");
    addVertex("sci");
    addVertex("art");
    addVertex("asia");
    addVertex("nordv");
    addEdge("norst","sci", 30);
    addEdge("sci","norst", 30);
    addEdge("norst","art", 70);
    addEdge("art","norst", 70);
    addEdge("sci","asia", 10);
    addEdge("asia","sci", 10);
    addEdge("asia","art", 50);
    addEdge("art","asia", 50);
    addEdge("art","nordv", 20);
    addEdge("nordv","art", 20);
}

void Graph::buildTree(){
    ifstream inputtext;
    string lines;
    string words;
    inputtext.open("list_of_book.txt");
    if(inputtext.is_open())
    {
        while(getline(inputtext,lines))
        {
            stringstream wordofline(lines);
            getline(wordofline,words,',');
            string getType = words;
            getline(wordofline,words,',');
            string title = words;
            getline(wordofline,words,',');
            string getAuthor = words;
            getline(wordofline,words);
            int getYear = stoi(words);
            Node *temp = new Node(getType,title,getAuthor,getYear, 1, nullptr,nullptr,nullptr);
            insertBook(temp);
        }
    }
}


//Menu function
void Graph::getCode(string a){
    startLoca = a;
    cout<<startLoca<<endl;
}

void Graph::searchBook(string a){
    Node *temp = new Node("","","",-1,1,nullptr,nullptr,nullptr);
    string stackN;
    for(int i =0; i<vertices.size();i++){
        stackN = vertices[i].name;
        vertices[i].treeRoot = root;
        temp = binarySearch(root,a);
        if(temp != nullptr){
            break;
        }
    }
    if(temp !=nullptr){
        cout<<"Book name: "<<temp->title<<endl;
        cout<<"Author: "<<temp->author<<endl;
        cout<<"Published year: "<<temp->year<<endl;
        cout<<"Library own: "<<temp->quantity<<" book"<<endl;
        cout<<"Location in "<<stackN<<endl;
    }
    else{
        cout<<"Book not found! Please re-enter title"<<endl;
    }
}

void Graph::checkIn(string a){
    Node *temp = new Node("","","",-1,1,nullptr,nullptr,nullptr);
    string stackN;
    for(int i =0; i<vertices.size();i++){
        stackN = vertices[i].name;
        vertices[i].treeRoot = root;
        temp = binarySearch(root,a);
        if(temp != nullptr){
            break;
        }
    }
    if(temp !=nullptr){
        cout<<"Thank you for returning book!"<<endl;
        cout<<"Book name: "<<temp->title<<". Status: checked"<<endl;
        temp->quantity = 1;
    }
    else{
        cout<<"Our library don't own that book! Please re-enter title"<<endl;
    }
}


void Graph::checkOut(string a){
    Node *temp = new Node("","","",-1,1,nullptr,nullptr,nullptr);
    string stackN;
    for(int i =0; i<vertices.size();i++){
        stackN = vertices[i].name;
        vertices[i].treeRoot = root;
        temp = binarySearch(root,a);
        if(temp != nullptr){
            break;
        }
    }
    if(temp !=nullptr){
        if(temp->quantity != 0){
        cout<<"Thank you enjoy the book! Please return before due date!"<<endl;
        cout<<"Book name: "<<temp->title<<". Status: check out"<<endl;
        temp->quantity = 0;
        }
        else{
            cout<<"Sorry! We are out of this book "<<temp->title<<endl;
        }
    }
    else{
        cout<<"Cannot check-out! Please re-enter title"<<endl;
    }
}

void Graph::showMap(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<"From "<<convert(vertices[i].name)<<" you can go to ";
        for(int j = 0; j < vertices[i].adj.size()-1; j++){
            //i = j;
            cout<<convert(vertices[i].adj[j].v->name)<<" & ";
        }
        cout<<convert(vertices[i].adj.back().v->name)<<endl;
    }
}

void Graph::printBook(string stackN){
    vertex *tempV = new vertex;
    if(checkVertex(stackN) == true){
        for(int i =0; i<vertices.size();i++){
            if(vertices[i].name == stackN){
                tempV = &vertices[i];
                break;
            }
        }
        tempV->treeRoot = root;
        traversePrint(root);
    }
    else{
        cout<<"You enter the wrong code"<<endl;
    }

}

void Graph::shortestDist(string found){
    if(checkVertex(found)==true){
    dijkstra(startLoca,found);
    }
    else{
        cout<<"You enter wrong code"<<endl;
    }
}

//Convert function
string Graph::convert(string a){
    string name;
    if(a == "norst"){
        name = "Main Stack";
    }
    if(a == "art"){
        name = "Art Stack";
    }
    if(a == "sci"){
        name = "Science Stack";
    }
    if(a == "nordv"){
        name = "DVD Stack";
    }
    if(a =="asia"){
        name = "Asia Stack";
    }
    return name;

}



int main()
{
    int choice;
    bool menu = false;
    string wordin;
    string c;
    Graph g;
    g.buildMap();
    g.buildTree();
    cout<<"/=================/==================/"<<endl;
    cout<<"Hello! Welcome to CU-Boulder Library"<<endl;
    cout<<"May I get your current location?"<<endl;
    cout<<"Please enter code match to stack name"<<endl;
    cout<<"//***************//"<<endl;
    cout<<"Code----Location"<<endl;
    cout<<""<<endl;
    cout<<"norst---Main stack"<<endl;
    cout<<"sci-----Science stack"<<endl;
    cout<<"asia----Asia stack"<<endl;
    cout<<"art-----Art stack"<<endl;
    cout<<"nordv---DVD stack"<<endl;
    cin>>c;
    g.getCode(c);
/////main menu
    while(!menu){

        cout<< "======Main Menu======" << endl;
        cout<< "1. Search for book" << endl;
        cout<< "2. Check in book" << endl;
        cout<< "3. Check out book" << endl;
        cout<< "4. Show library map" << endl;
        cout<< "5. Fastest way to stack " << endl;
        cout<< "6. Display book" << endl;
        cout<< "7. Re-enter current location" << endl;
        cout<< "8. Quit" << endl;
        cin>>choice;
        switch(choice){
        case 1:
            cin.ignore();
            cout<<"Enter title:" << endl;
            getline(cin,wordin);
            g.searchBook(wordin);
            break;
        case 2:
            cin.ignore();
            cout<<"Enter title:" << endl;
            getline(cin,wordin);
            g.checkIn(wordin);
            break;
        case 3:
            cin.ignore();
            cout<<"Enter title:" << endl;
            getline(cin,wordin);
            g.checkOut(wordin);
            break;
        case 4:
            g.showMap();
            break;
        case 5:
            cin.ignore();
            cout<<"Stack you want to go"<<endl;
            cout<<"Code----Location"<<endl;
            cout<<""<<endl;
            cout<<"norst---Main stack"<<endl;
            cout<<"sci-----Science stack"<<endl;
            cout<<"asia----Asia stack"<<endl;
            cout<<"art-----Art stack"<<endl;
            cout<<"nordv---DVD stack"<<endl;
            cin>>wordin;
            g.shortestDist(wordin);

            break;
        case 6:
            cin.ignore();
            cout<<"Stack you want to go"<<endl;
            cout<<"Code----Location"<<endl;
            cout<<""<<endl;
            cout<<"norst---Main stack"<<endl;
            cout<<"sci-----Science stack"<<endl;
            cout<<"asia----Asia stack"<<endl;
            cout<<"art-----Art stack"<<endl;
            cout<<"nordv---DVD stack"<<endl;
            cin>>wordin;
            g.printBook(wordin);
            break;
        case 7:
            cin.ignore();
            cout<<"May I get your current location? Please enter code accordingly"<<endl;
            cout<<"    ***************     "<<endl;
            cout<<"Code----Location"<<endl;
            cout<<""<<endl;
            cout<<"norst---Main stack"<<endl;
            cout<<"sci-----Science stack"<<endl;
            cout<<"asia----Asia stack"<<endl;
            cout<<"art-----Art stack"<<endl;
            cout<<"nordv---DVD stack"<<endl;
            cin>>c;
            g.getCode(c);
            break;
        case 8:
            menu = true;
            break;
        default:
            cout<< "Not a valid choice"<<'\n';
            cout<< "Choose again"<<'\n';
            menu = false;
            cin>>choice;
            break;
        }
    }

    return 0;
}
