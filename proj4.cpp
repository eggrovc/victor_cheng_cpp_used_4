#include "proj4.h"

// Question 2 Part a and b
void Proj4::q2(const string& file, ofstream& outFile){
    stringGraph.clear();
    readFileStr(file);
    // print(outFile);
    // outFile << Proj4::graphCyclic(outFile) << endl;
    auto start = chrono::high_resolution_clock::now();

    graphCyclic(outFile);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    outFile << endl << "# Running Time: " << duration.count() << " microseconds." << endl << endl;

    stringGraph.clear();
    readFileChar(file);

    start = chrono::high_resolution_clock::now();

    graphCyclic(outFile);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);

    outFile << endl << "# Running Time: " << duration.count() << " microseconds." << endl << endl;

    outFile << "------------------------------------------------------" << endl << endl;
    // print(outFile);

}

bool Proj4::graphCyclic(ofstream& outFile) {
    set<string> visited;
    
    map<string, string> parentMap; 
    
    for (auto const& pair : this->stringGraph) {
        const string& node = pair.first;

        if (visited.find(node) == visited.end()) {
            
            parentMap[node] = ""; 
            
            if (cyclicDFS(outFile, node, visited, parentMap)) {
                return true; 
            }
        }
    }

 
    outFile << "No Cycle" << endl;
    return false;
}

bool Proj4::cyclicDFS(ofstream& outFile, const string& currentNode, set<string>& visited, map<string, string>& parentMap) {
    
    visited.insert(currentNode);

    for (const string& neighbor : this->stringGraph[currentNode]) {
        
        if (visited.find(neighbor) == visited.end()) {

            parentMap[neighbor] = currentNode; 
            
            if (cyclicDFS(outFile, neighbor, visited, parentMap)) {
                return true;
            }

        } else if (neighbor != parentMap[currentNode]) {
            
            string curr = currentNode;
            while (curr != neighbor) {
                outFile << curr << ", ";
                curr = parentMap[curr];
            }
            
            outFile << neighbor << ", " << currentNode << endl;

            return true;
        }
    }
    return false;
}

// Question 5
void Proj4::q5(const string& file, ofstream& outFile){
    readFileInt(file);
    // printInt(outFile);

    classifyEdges(outFile);

}

void Proj4::classifyEdges(ofstream& outFile) {
    // 1. Initialize all nodes
    totalTime = 0;
    topOrder.clear();
    for (int node : allNodes) {
        visited[node] = 0;
        discoveryTime[node] = 0;
        finishTime[node] = 0;
    }

    outFile << "Topological sorted nodes in sequence" << endl << endl;
    for (int node : allNodes) {
        if (visited[node] == 0) {
            dfs(outFile, node);
        }
    }

    reverse(topOrder.begin(), topOrder.end());

    // Print topOrder
    outFile << endl << endl;
    
    for (int node : topOrder) {
        outFile << node << " ";
    }

    outFile << endl << endl;
}

void Proj4::dfs(ofstream& outFile, int u) {
    visited[u] = 1;
    discoveryTime[u] = totalTime++;

    for (int v : graph[u]) {
        outFile << "Edge (" << u << ", " << v << ") -- Type: ";

        if (visited[v] == 0) {
            outFile << "T (Tree)" << endl;
            dfs(outFile, v);
        } else if (visited[v] == 1) {
            outFile << "B (Backward)" << endl;

        } else if (visited[v] == 2) {
            if (discoveryTime[u] < discoveryTime[v]) {
                outFile << "F (Forward)" << endl;
            } else {
                outFile << "C (Cross)" << endl;
            }
        }
    }

    visited[u] = 2;
    finishTime[u] = totalTime++;
    
    topOrder.push_back(u);

}

// Question Q10
void Proj4::q10(const string& file, ofstream& outFile){
    readFileStrQ10(file);
    // print(outFile);

    int minSems = 0;
    for (const auto& pair : stringGraph) {
        const string& course = pair.first;
        minSems = max(minSems, q10Dfs(outFile, course));
    }

    outFile << "Minimum Semesters Required: " << minSems << endl;
}

int Proj4::q10Dfs(ofstream& outFile, const string& course) {
    if (found.count(course)) {
        return found[course];
    }

    if (stringGraph.find(course) == stringGraph.end()) {
        found[course] = 1;
        return 1;
    }

    const vector<string>& prereqs = stringGraph.at(course);

    int maxReq = 0;
    for (const string& n : prereqs) {
        maxReq = max(maxReq, q10Dfs(outFile, n));
    }

    found[course] = maxReq + 1;
    return found[course];
}


// void Proj4::qlp(const string& file, ofstream& outFile){


// }

// Helper Functions
void Proj4::readFileStr(const string& file) {
    ifstream currFile(file);
    string currLine;

    while (getline(currFile, currLine)) {
        if (currLine.empty()) {
            break;;
        }
        stringstream line(currLine);
        string u, v;
        
        line >> u >> v;

        this->udAddEdge(u, v);
        }
}

void Proj4::readFileChar(const string& file) {
    ifstream currFile(file);
    string currLine;
    bool extra = false;
    bool oneRepeat = true;

    while (getline(currFile, currLine)) {
        if (!currLine.empty() && extra == false) {
            continue;
        } else if (currLine.empty() && oneRepeat == true) {
            extra = true;
            oneRepeat = false;
            continue;
        }

        stringstream line(currLine);
        string u, v;
        
        line >> u >> v;

        this->udAddEdge(u, v);
        }
}

// Q5
void Proj4::readFileInt(const string& file) {
    ifstream currFile(file);
    string currLine;

    while (getline(currFile, currLine)) {
        if (currLine.empty()) {
            break;;
        }
        stringstream line(currLine);
        int u, v;
        
        line >> u >> v;

        this->dAddEdge(u, v);
        }
}

// Q10
void Proj4::readFileStrQ10(const string& file) {
    ifstream currFile(file);
    string currLine;

    while (getline(currFile, currLine)) {
        if (currLine.empty()) {
            break;;
        }
        stringstream line(currLine);
        string u, v;
        
        if (line >> u >> v) {
            this->dAddEdge(u, v);
            
        } else if (line) {
            stringGraph[u];
        }
    }
}

void Proj4::print(ofstream& outFile) {

    for (const auto& pair : stringGraph) {
        outFile << "Node: " << pair.first << " -> Neighbors: [ ";

        for (const auto& n : pair.second) {
            outFile << n << " ";
        }

        outFile << "]" << endl; 
    }

    outFile << endl;

}

void Proj4::printInt(ofstream& outFile) {

    for (const auto& pair : graph) {

        for (const auto& n : pair.second) {
            outFile << "Edge (" << pair.first << ", " << n << ")" << " -- " <<  "Type " << endl ;
        }

    }

    outFile << endl;

}