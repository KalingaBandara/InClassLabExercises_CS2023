#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> totalDistances(6,0);

int dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distances[source] = 0;
    pq.push({0, source});
    
    int totalDis = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }

    // Print the shortest distances from the source to all other cities
    for (int i = 0; i < n; ++i) {
        cout << "Shortest time from city " << source << " to city " << i << ": ";
        if (distances[i] == INT_MAX)
            cout << "No path" << endl;
        else
            cout << distances[i] << endl;
        totalDis+=distances[i];
    }
    return totalDis;
}

int main() {
    int n = 6; // Number of cities
    vector<vector<pii>> graph(n);
    
    vector<int> totalDistances(n,0);
    
    // Construct the graph
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 15});
    graph[0].push_back({5, 5});
    graph[1].push_back({0, 10});
    graph[1].push_back({2, 10});
    graph[1].push_back({3, 30});
    graph[2].push_back({1, 10});
    graph[2].push_back({3, 12});
    graph[2].push_back({5, 20});
    graph[3].push_back({1, 30});
    graph[3].push_back({2, 12});
    graph[3].push_back({5, 20});
    graph[4].push_back({0, 15});
    graph[4].push_back({2, 5});
    graph[5].push_back({0, 5});
    graph[5].push_back({4, 20});

    int minDistance = 0; 
    for (int i = 0; i <= 5; ++i) {
        totalDistances[i] = (dijkstra(graph, i));
        cout <<"Average distance from city "<< i << " is " << totalDistances[i]/n<<endl;
    }
    minDistance = *min_element(totalDistances.begin(),totalDistances.end() );
    for (int i = 0; i<=5; ++i){
        if (totalDistances[i] == minDistance){
            cout<< "Minimum average distance is "<< minDistance/6 <<endl;
            cout<< "City " << i << " is suitable to build the hospital"<< endl; 
        }
    }
    
    return 0;
}
