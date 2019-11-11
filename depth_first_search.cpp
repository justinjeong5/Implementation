/*
 * depth_first_search
 */

#include <iostream>
#include <string>
#include <vector>

#define M 500
using namespace std;

struct Vertex {
    int item;
    int degree;
    bool visited;

    Vertex(int item) : item(item), degree(0), visited(false) {}

    void increaseDegree() {
        degree++;
    }

    void decreaseDegree() {
        degree--;
    }

    void setVisited() {
        visited = true;
    }

    bool getVisitied() {
        return visited;
    }
};

struct Edge {
    Vertex *src;
    Vertex *dst;
    bool explored;
    bool discovery;
    bool back;
    string item;

    Edge(Vertex *src, Vertex *dst) : src(src), dst(dst), discovery(false), explored(false), back(false) {}

    void setEdgeItem(string name) {
        item = name;
    }

    void setDiscovery() {
        discovery = true;
    }

    bool getDiscovery() {
        return discovery;
    }

    void setExplored() {
        explored = true;
    }

    bool getExplored() {
        return explored;
    }

    void setBack() {
        back = true;
    }

    bool getBack() {
        return back;
    }
};

class Graph {
private:
    int v_sz;
    int max_sz;
    Vertex **v;
    vector<Edge *> e;
    Edge ***mat;
public:
    Graph() {
        v_sz = 0;
        max_sz = M;

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

    void insertVertex(int data) {
        if (v_sz + 1 > max_sz || v[data] != NULL) return;

        v[data] = new Vertex(data);
        v_sz++;
    }

    void insertEdge(int src, int dst) {
        if (v[src] == NULL || v[dst] == NULL || mat[src][dst] != NULL || mat[dst][src] != NULL) return;
        Edge *newEdge = new Edge(v[src], v[dst]);
        e.push_back(newEdge);
        v[src]->increaseDegree();
        v[dst]->increaseDegree();
        mat[src][dst] = newEdge;
        mat[dst][src] = newEdge;
    }

    void removeEdge(int src, int dst) {
        if (v[src] == NULL || v[dst] == NULL || mat[src][dst] == NULL || mat[dst][src] == NULL) return;
        for (int i = 0; i < (int) e.size(); i++) {
            if (e[i] == mat[src][dst] || e[i] == mat[dst][src]) {
                e.erase(e.begin() + i);
                mat[src][dst] = NULL;
                mat[dst][src] = NULL;
                v[src]->decreaseDegree();
                v[dst]->decreaseDegree();
                return;
            }
        }
    }

    void removeVertex(int data) {
        if (v_sz - 1 < 0 || v[data] == NULL) return;
        for (int i = 0; i < M; i++) {
            removeEdge(data, i);
        }
        v[data] = NULL;
        v_sz--;
    }

    void dfs(int start) {
        if (v[start]->getVisitied() == true) return;

        v[start]->setVisited();
        for (int i = 0; i < M; i++) {
            if (mat[start][i] != NULL) {
                if (v[i]->getVisitied() == false) {
                    mat[start][i]->setExplored();
                    mat[start][i]->setDiscovery();
                    dfs(i);
                } else {
                    if (mat[start][i]->getDiscovery() == true) continue;
                    mat[start][i]->setExplored();
                    mat[start][i]->setBack();        //���� ������ visited �̱� ������, Edge���� back ����
                }
            }
        }
    }
};

int main() {


}