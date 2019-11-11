/*
 *	2019.7.28
 *	prim_priority_queue
 */
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 101

//prim - O(N^2)의 시간 복잡도. priority_queue를 이용하여 탐색
bool visit[MAX];
pair<int, int> p_temp;
vector<pair<int, int>> prim_graph[MAX];

int prim() {                //priority queue 방식
    memset(visit, false, sizeof(visit));
    int answer = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, p_temp.first});        //최초 시작인 vertex를 입력하고 가중치를 0으로 두여 pq에 시작 정보를 입력
    while (!pq.empty()) {
        int cost = -pq.top().first;            //priority_queue는 delete_max가 default임으로 -를 사용하여 시간절약.
        int vertex = pq.top().second;
        pq.pop();

        if (!visit[vertex]) {
            visit[vertex] = true;
            answer += cost;
            for (auto & i : prim_graph[vertex]) {
                int next_cost = i.first;
                int next_vertex = i.second;
                if (!visit[next_vertex])
                    pq.push({-next_cost, next_vertex});        //priority_queue는 delete_max가 default임으로 -를 사용하여 시간절약.
            }
        }
    }
    return answer;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    p_temp = {0, INT_MAX};
    for (auto & cost : costs) {
        prim_graph[cost[0]].emplace_back(cost[2], cost[1]);
        prim_graph[cost[1]].emplace_back(cost[2], cost[0]);
        if (cost[2] < p_temp.second)
            p_temp = {cost[0], cost[2]};
    }
    answer = prim();
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