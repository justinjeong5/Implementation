/*
 *	2019.7.28
 *	kruskal_union_find
 */
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

//kruskal - O(N log(v))의 시간 복잡도. disjoint set 방식을 이용하여 prim보다 빠름
struct Edge {
    int u, v, c;

    bool operator<(Edge &e) {        // 두 Edge를 비교하는 기준. cost.
        return c < e.c;
    }
};

int vertex_amount = 0;
int parent[MAX], set_size[MAX];
vector<Edge> kruskal_graph;

int find_parent(int node) {        //predecessor 정보를 이용하여 부모(set의 대표)를 탐색
    if (node == parent[node])
        return node;
    return parent[node] = find_parent(parent[node]);
}

void merge_set(int node1, int node2) {        //union set 함수
    node1 = find_parent(node1);
    node2 = find_parent(node2);

    if (node1 != node2)        //두 set이 다른 집합인 경우 union한다
    {
        if (set_size[node1] < set_size[node2])        //set의 원소의 갯수가 더 많은 set을 대표로 지정
            swap(node1, node2);
        parent[node1] = node2;
        set_size[node1] += set_size[node2];
        set_size[node2] = 1;
    }
}

int kruskal() {            //disjoint set 방식
    int answer = 0;
    Edge k_temp{};

    for (int i = 0; i <= vertex_amount; i++) {          //set_size와 parent 정보를 초기화
        parent[i] = i;
        set_size[i] = 1;
    }
    sort(kruskal_graph.begin(), kruskal_graph.end());        //위에서 이미 정의한 Edge의 정렬 기준으로 정렬함

    for (auto i : kruskal_graph) {
        k_temp = i;
        if (find_parent(k_temp.v) != find_parent(k_temp.u)) {
            answer += k_temp.c;
            merge_set(k_temp.v, k_temp.u);
        }
    }
    return answer;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    vertex_amount = n;
    for (auto &cost : costs) {
        kruskal_graph.push_back({cost[0], cost[1], cost[2]});
    }
    answer = kruskal();
    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> costs = {{0, 1, 1},
                                 {0, 2, 2},
                                 {1, 2, 5},
                                 {1, 3, 1},
                                 {2, 3, 8}};
    int answer = solution(n, costs);

    return 0;
}