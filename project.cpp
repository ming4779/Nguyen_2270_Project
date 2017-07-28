#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include "graph.hpp"
#include "graph.cpp"

using namespace std;

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
    cout<<"juv-----Juvenile stack"<<endl;
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
        cout<< "6. Re-enter current location" << endl;
        cout<< "7. More" << endl;
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
            cout<<"juv-----Juvenile stack"<<endl;
            cin>>wordin;
            g.shortestDist(wordin);
            break;
        case 6:
            cin.ignore();
            cout<<"May I get your current location? Please enter code"<<endl;
            cout<<"    ***************     "<<endl;
            cout<<"Code----Location"<<endl;
            cout<<""<<endl;
            cout<<"norst---Main stack"<<endl;
            cout<<"sci-----Science stack"<<endl;
            cout<<"asia----Asia stack"<<endl;
            cout<<"art-----Art stack"<<endl;
            cout<<"nordv---DVD stack"<<endl;
            cout<<"juv-----Juvenile stack"<<endl;
            cin>>c;
            g.getCode(c);
            break;
        case 7:
            int temp;
            cout<<"=======Option======="<<endl;
            cout<<"1. Print out book in stack"<<endl;
            cout<<"2. Get shelf's level in stack"<<endl;
            cin.ignore();
            cin>>temp;
            if(temp == 1){
            cin.ignore();
            cout<<"Stack you want to print book from"<<endl;
            cout<<"Code----Location"<<endl;
            cout<<""<<endl;
            cout<<"norst---Main stack"<<endl;
            cout<<"sci-----Science stack"<<endl;
            cout<<"asia----Asia stack"<<endl;
            cout<<"art-----Art stack"<<endl;
            cout<<"nordv---DVD stack"<<endl;
            cout<<"juv-----Juvenile stack"<<endl;
            cin>>wordin;
            g.printBook(wordin);
            }
            else if(temp == 2){
            cout<<"Stack you want to know shelf's level"<<endl;
            cout<<"    ***************     "<<endl;
            cout<<"Code----Location"<<endl;
            cout<<""<<endl;
            cout<<"norst---Main stack"<<endl;
            cout<<"sci-----Science stack"<<endl;
            cout<<"asia----Asia stack"<<endl;
            cout<<"art-----Art stack"<<endl;
            cout<<"nordv---DVD stack"<<endl;
            cout<<"juv-----Juvenile stack"<<endl;
            cin>>c;
            g.shelfLevel(c);
            }
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
