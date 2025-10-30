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


// Implement graph instances here and use them in main.cpp
class Proj4{

    public:

        // Helper functions
        void readFileStr(const string& file);
        void readFileChar(const string& file);
        void readFileInt(const string& file);
        void readFileStrQ10(const string& file);

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
        
        // Q 11 Stuff
        void q10(const string& file, ofstream& outFile);

        void qlp(const string& file, ofstream& outFile);
       
    private: 
        // Global for Q5
        set<int> allNodes;  // So it can be unique
        map<int, int> visited;  // 0 = white, 1 = gray, 2 = black
        map<int, int> discoveryTime;
        map<int, int> finishTime;
        vector<int> topOrder;

        int totalTime;

        // Q 10
        map<string, int> found;
        int q10Dfs(ofstream& outFile, const string& course);

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