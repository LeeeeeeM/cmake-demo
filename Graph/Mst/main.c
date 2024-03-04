#include <stdio.h>
#include <limits.h>

#define V 5  // 图的顶点数

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]) {
    int parent[V];  // 存储构建最小生成树的父节点
    int key[V];     // 存储顶点的权重值
    int mstSet[V];  // 记录顶点是否已包含在最小生成树中

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    // 初始化第一个顶点为起始节点
    parent[0] = -1;  // 第一个顶点没有父节点

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // 从未包含的顶点中选择权重最小的顶点
        mstSet[u] = 1;  // 将该顶点标记为已包含在最小生成树中

        for (int v = 0; v < V; v++) {
            // 更新与未包含的顶点相邻的顶点的权重值
            // 只考虑未包含在最小生成树中的顶点
            // 更新条件是：存在边相连，权重小于当前值
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);  // 打印最小生成树的边和权重
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}