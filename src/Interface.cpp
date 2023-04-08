//
// Created by nesma on 09/03/2023.
//

#include "../header/Interface.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

bool Interface::is_in(string choice, int lim_start, int lim_end) const{
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

int Interface::initiate() {
    MenuPrincipal: string userInput;
    cout << "Introduza o numero do comando: \n\t1. Stations Map \n\t2. Basic Services \n\t3. Operation Cost Optimization \n\t4.Reliability and Sensivity to Line Failures \n\t0. Exit Program" << endl;
    cin >> userInput;
    if (userInput == "0") return 1;
    while(!is_in(userInput,1,4)){
        cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
        cin >> userInput;
    }

    //Stations Map (!!!)
    if (userInput == "1"){
        MenuMap: string m;
        networkDisplay();
        cout << "To go back press[0]" << endl;
        cin >> m;
        if (m == "0") goto MenuPrincipal;
        while(m != "0"){ cin >> m; }
    }

        //Basic Services
    else if (userInput == "2"){
        MenuBasic: string b;
        cout << "Introduza o numero do comando: \n\t1. Stations with most flow \n\t2. Top-K Maintenance \n\t3. Maximum arrivals \n\t0. Go back" << endl;
        cin >> b;
        if (b == "0") goto MenuPrincipal;
        while(!is_in(b,1,3)){
            cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
            cin >> b;
        }

        //if 1.
        if (b == "1"){
            MenuFlow: string w;
            cout << "Introduza o numero do comando: \n\t1. Global \n\t2. Personalized \n\t0. Go back" << endl;
            cin >> w;
            if (w == "0") goto MenuBasic;
            while(!is_in(w,1,3)){
                cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
                cin >> w;
            }

            //if Global
            if (w == "1") {
                MenuGlobal:
                string g;
                maxFlowStations(station1, station2);
                cout << "To go back press[0]" << endl;
                cin >> g;
                if (g == "0") goto MenuFlow;
                while (g != "0") { cin >> g; }
            }
                //if perso
            else if (w == "2"){
                MenuPer: string p;
                maxFlowStations(station1, station2);
                cout << "To go back press[0]" << endl;
                cin >> p;
                if (p == "0") goto MenuFlow;
                while(p != "0"){ cin >> p; }
            }
        }

            //if 2.
        else if (b == "2"){
            MenuTop: string t,x, k;
            cout << "Introduce the method: \n\t1. By municiple \n\t2. By district \n\t0. Go back" << endl;
            if (x == "0") goto MenuBasic;
            else{
                cout << "Enter the k: " << endl;
                cin >> k;
                int k1 = stoi(k);
                topKmaintenance(k1,x);
                cout << "To go back press[0]" << endl;
                cin >> t;
                if (t == "0") goto MenuBasic;
                while(t != "0"){ cin >> t; }
            }
        }

            //if 3.
        else if (b == "3"){
            MenuMax: string a, stb;
            cout << "Please, introduce the name of the station: " << endl;
            cin.ignore();
            getline(cin,stb);
            maxArriveStation(stb);
            cout << "To go back press[0]" << endl;
            cin >> a;
            if (a == "0") goto MenuBasic;
            while(a != "0"){ cin >> a; }
        }
    }

        //Optimization
    else if (userInput == "3"){
        MenuCost: string c;
        maxFlowStationsDijkstra(station1, station2);
        cout << "To go back press[0]" << endl;
        cin >> c;
        if (c == "0") goto MenuPrincipal;
        while(c != "0"){ cin >> c; }
    }

        //Line Failures
    else if (userInput == "4"){
        MenuFailure: string f;
        cout << "Introduza o numero do comando: \n\t1. Maximum flow with minimum connections \n\t2. Top-K most affected Stations \n\t0. Go back" << endl;
        cin >> f;
        if (f == "0") goto MenuPrincipal;
        while(!is_in(f,1,2)){
            cout << "Sintaxe errada.\nPor favor, reintroduzir:" << endl;
            cin >> f;
        }

        //if 1.
        if (f == "1"){
            MenuMin: string i;
            maxFlowSubgraph(station1, station2);
            cout << "To go back press[0]" << endl;
            cin >> i;
            if (i == "0") goto MenuFailure;
            while(i != "0"){ cin >> i; }
        }

        //if 2.
        if (f == "1"){
            MenuK: string k;
            cout << "Enter the k: " << endl;
            cin >> k;
            int k1 = stoi(k);
            mostAffectedByFailure(const string &station1, const string &station2);
            cout << "To go back press[0]" << endl;
            cin >> t;
            if (t == "0") goto MenuBasic;
            while(t != "0"){ cin >> t; }
        }
    }

    return 0;
}
