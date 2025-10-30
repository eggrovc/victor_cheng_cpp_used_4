#ifndef PROJ4_H
#define PROJ4_H

using namespace std;
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct coordinates{
    double x = 0;
    double y = 0;

    coordinates() {
        x = 0;
        y = 0;
    }

    coordinates(double x1, double y1) {
        x = x1;
        y = y1;
    }

};

// Implement graph instances here and use them in main.cpp
class Proj4{

    public:

        // Helper functions
        void readFileStr(const string& file);
        void readFileChar(const string& file);
        void readFileInt(const string& file);
        void readFileStrQ10(const string& file);
        void readFilelp(const string& file);

        void print(ofstream& outFile);
        void printInt(ofstream& outFile);

        // Q2 Stuff
        void q2(const string& file, ofstream& outFile);
        bool cyclicDFS(ofstream& outFile, const string& currentNode, set<string>& visited, map<string, string>& parentMap);
        bool graphCyclic(ofstream& outFile); 

        // Q5 Stuff 
        void q5(const string& file, ofstream& outFile);
        void classifyEdges(ofstream& outFile);
        void dfs(ofstream& outFile, int u);
        
        // Q10 Stuff
        void q10(const string& file, ofstream& outFile);

        // Q11 Stuff
        void qlp(const string& file, ofstream& outFile);
        void graphicalSol(ofstream& outFile);
       
    private: 
        // Global for Q5
        set<int> allNodes;  // So it can be unique

        vector<int> visited;    // 0 = white, 1 = gray, 2 = black
        vector<int> discoveryTime;
        vector<int> finishTime;

        // map<int, int> visited;  // 0 = white, 1 = gray, 2 = black
        // map<int, int> discoveryTime;
        // map<int, int> finishTime;

        vector<int> topOrder;
        int totalTime;

        // Q 10
        map<string, int> found;
        int q10Dfs(ofstream& outFile, const string& course);

        // Q 11
        string operation;
        vector<double> costs;
        vector<vector<double>> matrix; 



        // Graphs
        map<string, vector<string>> stringGraph;
        map<int, vector<int>> graph;

        // Ran through the public functions to initialize our graphs
        void udAddEdge(int u, int v) {  // UndirectedEdge
            graph[u].push_back(v);
            graph[v].push_back(u);
        }   

        void dAddEdge(int u, int v) {    // Directed Edge
            graph[u].push_back(v);
            allNodes.insert(u);
            allNodes.insert(v);
        }

        // Strings
        void udAddEdge(string u, string v) {  // UndirectedEdge
            stringGraph[u].push_back(v);
            stringGraph[v].push_back(u);
        }   
        
        // Q10
        void dAddEdge(string u, string v) {    // Directed Edge
            stringGraph[u].push_back(v);
            stringGraph[u]; 
        }
};


#endif