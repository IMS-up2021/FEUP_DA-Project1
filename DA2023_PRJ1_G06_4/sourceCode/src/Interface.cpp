//
// Created by nesma on 09/03/2023.
//

#include "../header/Interface.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "../header/CSVReader.h"

using namespace std;

bool Interface::is_in(const string& choice, int lim_start, int lim_end) {
    set<string> availableChoices={"0","1","2","3","4","5","6","7","8","9"};
    if(availableChoices.find(choice)!= availableChoices.end()&&stoi(choice)>=lim_start && stoi(choice) <=lim_end ) return true;
    return false;
}

void Interface::networkDisplay(){
    ifstream n("network.csv");
    if (n.is_open()){
        string line;
        while(getline(n,line)){
            cout << line << endl;
        }
    }
    n.close();
}

int Interface::initiate(Network n) {
    MenuPrincipal: string userInput;
    cout << "Introduza o numero do comando: \n\t1. Stations Map \n\t2. Basic Services \n\t3. Operation Cost Optimization \n\t4. Reliability and Sensivity to Line Failures\n\t 5. DO THIS FIRST read file data: \n\t0. Exit Program" << endl;
    cin >> userInput;
    if (userInput == "0") exit(0);
    while(!is_in(userInput,1,5)){
        cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
        cin >> userInput;
    }

    if (userInput == "1"){
        MenuMap: string m;
        networkDisplay();
        cout << "To go back press [0]" << endl;
        cin >> m;
        if (m == "0") goto MenuPrincipal;
        while(m != "0"){ cin >> m; }
    }

        //Basic Services
    else if (userInput == "2"){
        MenuBasic: string b;
        cout << "Introduza o numero do comando: \n\t1. Maximum nº trains that can travel between two stations \n\t2. pairs of stations that require most trains \n\t3. Top-k stations in terms of maintenance need\n\t4. Check maximum arrivals \n\t0. Go back" << endl;
        cin >> b;
        if (b == "0") goto MenuPrincipal;
        while(!is_in(b,1,4)){
            cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
            cin >> b;
        }

        //if 1.
        if (b == "1"){
            MenuFlow:
            n.maxFlowStations();
            cout << "To go back press [0]" << endl;
            string m;
            cin >> m;
            if (m == "0") goto MenuBasic;
            while(m != "0"){ cin >> m; }
        }

        //if 2.
        else if (b == "2"){
            for(const pair<Station,Station>& pair : n.maxFlowPairs()){
                cout << endl << pair.first.getName()<<" -> "<<pair.second.getName();
            }
            cout <<endl<< "To go back press [0]" << endl;
            string m;
            cin >> m;
            if (m == "0") goto MenuBasic;
            while(m != "0"){ cin >> m; }
        }

        //if 3.
        else if (b == "3"){
            cout<<endl<<"Enter k for topK and then 1 for municipalities and 2 for district";
            int k;
            string option;
            cin>>k;
            cin>>option;
            n.topKmaintenance(k,option);
            cout << "To go back press[0]" << endl;
            string m;
            cin >> m;
            if (m == "0") goto MenuBasic;
            while(m != "0"){ cin >> m; }

        }

        else if (b == "4"){
            string string1;
            cout<<"insert station:";
            cin.ignore();
            getline(cin,string1);
            n.maxArriveStation(string1);
            cout << "To go back press[0] " << endl;
            string m;
            cin >> m;
            while(m != "0"){ cin >> m; }
            if (m == "0") goto MenuBasic;

        }
    }

        //Optimization
    else if (userInput == "3"){
        MenuCost: string c;
        n.maxFlowStationsDijkstra();
        cout << "To go back press [0]" << endl;
        cin >> c;
        if (c == "0") goto MenuPrincipal;
        while(c != "0"){ cin >> c; }
    }

        //Line Failures
    else if (userInput == "4"){
        MenuFailure: string f;
        cout << "Introduza o numero do comando: \n\t1. Maximum flow with reduced connectivity \n\t2. Top-K most affected Stations \n\t0. Go back" << endl;
        cin >> f;
        if (f == "0") goto MenuPrincipal;
        while(!is_in(f,1,2)){
            cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
            cin >> f;
        }

        //if 1.
        if (f == "1"){
            MenuMin: string i,j;
            cout<<"enter two stations to form an edge to be removed";
            cin.ignore();
            getline(cin,i);
            //cin.ignore();
            getline(cin,j);
            n.maxFlowSubgraph(i, j);
            cout << "To go back press [0]" << endl;
            cin >> i;
            if (i == "0") goto MenuFailure;
            while(i != "0"){ cin >> i; }
        }

        //if 2.
        if (f == "2"){
            string i,j;
            cout<<"enter two stations to form an edge to be removed";
            cin.ignore();
            getline(cin,i);
            getline(cin,j);
            n.mostAffectedByFailure(i,j);
            cout << "To go back press [0]" << endl;
            cin >> i;
            if (i == "0") goto MenuFailure;
            while(i != "0"){ cin >> i; }
        }
    }
    else if (userInput == "5"){
        string stationsPath = "../Data/stations.csv";
        string networkPath = "../Data/network.csv";
        CSVReader::read_stations(stationsPath,&n);
        CSVReader::read_network(networkPath,&n);
        cout<<"done"<<endl;
        string i;
        cout << "To go back press [0]" << endl;
        cin >> i;
        while(i != "0"){ cin >> i; }
        if (i == "0") goto MenuPrincipal;
    }

    return 0;
}


Interface::Interface() = default;


