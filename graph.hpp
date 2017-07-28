#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;


struct Node{
    string type;
    string title;
    string author;
    int year;
    int quantity;
    Node *left;
    Node *right;
    Node *parent;
    Node(string _type, string _title, string _author,int _year, int _quantity,
         Node *_left = nullptr, Node *_right =nullptr, Node *_parent = nullptr):
             type(_type), title(_title), author(_author), year(_year), quantity(_quantity), left(_left),
             right(_right), parent(_parent){}
};

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};


struct vertex{
    bool visited;
    bool solved;
    string name;
    int distance;
    vertex *parentG;
    Node *treeRoot;
    vector<adjVertex> adj;
};


class Graph
{
    public:
        Graph();
        ~Graph();
        // Graph public function
        bool checkVertex(string);
        void buildMap();
        void BFS(string);
        // Tree public function
        void buildTree();
        // Menu public function
        void getCode(string);
        void searchBook(string);
        void checkIn(string);
        void checkOut(string);
        void showMap();
        void shortestDist(string);
        void printBook(string);
        void shelfLevel(string);

    protected:
    private:
        //Graph
        string startLoca;
        vector<vertex> vertices =vector<vertex >(0) ;
        void addEdge(string v1, string v2, int weight);
        void addVertex(string name);
        void dijkstra(string, string);
        vertex searchVer(string);
        int searchIndex(string);
        //Tree
        int count;
        int maxi;
        Node *binarySearch(Node *node, string);
        void insertBook(int, Node *node);
        void traversePrint(Node *currentNode);
        void level(Node *node);
        //Convert code to name
        string convert(string);

};

#endif
