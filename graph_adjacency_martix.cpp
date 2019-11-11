/*
 * graph_adjacency_martix
 */

#include <iostream>
#include <string>
#include <vector>

#define M 500
using namespace std;

struct Vertex {
    int item;
    int degree;

    Vertex() {}

    Vertex(int item) : item(item), degree(0) {}

    void increaseDegree() {
        degree++;
    }

    void decreaseDegree() {
        degree--;
    }
};

struct Edge {
    Vertex *src;
    Vertex *dst;
    string item;

    Edge() {}

    Edge(Vertex *src, Vertex *dst) : src(src), dst(dst) {}

    void setEdgeItem(string name) {
        item = name;
    }
};

class Graph {
private:
    int v_sz;
    int max_sz;
    int cnt;
    Vertex **v;
    vector<Edge *> e;
    Edge ***mat;
public:
    Graph() {
        v_sz = 0;
        max_sz = M;
        cnt = 0;

        v = new Vertex *[M];
        for (int i = 0; i < M; i++) {
            v[i] = NULL;
        }

        mat = new Edge **[M];
        for (int i = 0; i < M; i++) {
            mat[i] = new Edge *[M];
            for (int j = 0; j < M; j++) {
                mat[i][j] = NULL;
            }
        }
    }

    void insert(int data) {
        if (v_sz + 1 > max_sz) {
            cout << 0 << endl;
            return;
        }
        if (v[data] != NULL) {
            cout << 0 << endl;
            return;
        }
        v[data] = new Vertex(data);
        v_sz++;
    }

    void insertEdge(int src, int dst) {
        if (v[src] == NULL || v[dst] == NULL) {
            cout << 0 << endl;
            return;
        }
        if (mat[src][dst] != NULL || mat[dst][src] != NULL) {
            cout << 0 << endl;
            return;
        }

        Edge *newEdge = new Edge(v[src], v[dst]);
        e.push_back(newEdge);
        mat[src][dst] = newEdge;
        mat[dst][src] = newEdge;
        v[src]->increaseDegree();
        v[dst]->increaseDegree();
    }

    void removeEdge(int src, int dst) {
        if (mat[src][dst] == NULL || mat[dst][src] == NULL) {
            return;
        }
        if (v[src] == NULL || v[dst] == NULL) {
            return;
        }
        for (int i = 0; i < (int) e.size(); i++) {
            if (e[i] == mat[src][dst] || e[i] == mat[dst][src]) {
                e.erase(e.begin() + i);
                mat[src][dst] = NULL;
                mat[dst][src] = NULL;
                v[src]->decreaseDegree();
                v[dst]->decreaseDegree();
            }
        }
    }

    void remove(int data) {
        if (v[data] == NULL) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < M; i++) {
            removeEdge(data, i);
        }
        v[data] = NULL;
        v_sz--;
        show();
    }

    void show() {
        cout << v_sz << " " << e.size() << endl;
    }
};

int main() {
    Graph graph;
    int m, n, o, input1, input2;
    cin >> m >> n >> o;
    for (int i = 0; i < m; i++) {
        cin >> input1;
        graph.insert(input1);
    }
    for (int i = 0; i < n; i++) {
        cin >> input1 >> input2;
        graph.insertEdge(input1, input2);
    }
    for (int i = 0; i < o; i++) {
        cin >> input1;
        graph.remove(input1);
    }

    system("pause");
    return 0;

}