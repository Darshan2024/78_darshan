#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Graph{
public:
    map<int, list<int>> adjList;
    map<int, bool> visited;
    queue<int> q;

    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void DFS(int node){
        visited[node] = true;
        cout << node << " ";
        for(int i : adjList[node]){
            if(!visited[i]) DFS(i);
        }
    }

    void BFS(){
        if(q.empty()) return;
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i : adjList[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
        BFS();
    }
};

int main(){
    Graph g;

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges:\n";
    for(int i = 0; i < numEdges; i++){
        int src, dest;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    int choice;
    cout << "Enter 0 to perform DFS and 1 to perform BFS: ";
    cin >> choice;

    if(choice == 0){
        cout << "DFS on the given graph is: ";
        g.DFS(0);
    }
    else if(choice == 1){
        cout << "BFS on the given graph is: ";
        g.q.push(0);
        g.visited[0] = true;
        g.BFS();
    }
    else{
        cout << "Invalid choice.";
    }

    return 0;
}