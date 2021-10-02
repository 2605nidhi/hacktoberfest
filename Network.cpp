#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define MAX_NODES 1000
#define O 100000000
int n;
int e;
int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int pred[MAX_NODES];

int min(int x, int y) {
  return x < y ? x : y;
}

int head, tail;
int q[MAX_NODES + 2];

void enqueue(int x) {
  q[tail] = x;
  tail++;
  color[x] = B;
}

int dequeue() {
  int x = q[head];
  head++;
  color[x] = C;
  return x;
}

// Using BFS as a searching algorithm
int bfs(int start, int target) {
  int u, v;
  for (u = 0; u < n; u++) {
    color[u] = A;
  }
  head = tail = 0;
  enqueue(start);
  pred[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == A && capacity[u][v] - flow[u][v] > 0) {
        enqueue(v);
        pred[v] = u;
      }
    }
  }
  return color[target] == C;
}

// Applying fordfulkerson algorithm
int fordFulkerson(int source, int sink) {
  int i, j, u;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  // Updating the residual values of edges
  while (bfs(source, sink)) {
    int increment = O;
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
    }
    printf("\nPath: \n");
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      flow[pred[u]][u] += increment;
      flow[u][pred[u]] -= increment;
      printf("%d <------",u);
    }
    printf("%d \tFlow is : %d\n\n",u,increment);
    // Adding the path flows
    max_flow += increment;
  }
  return max_flow;
}

int main() {
    int i,j;
    printf("Enter number of vertices and number of edges\n");
    scanf("%d%d",&n,&e);
    
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      capacity[i][j] = 0;
    }
  }
  int e1,e2,w;
  printf("Enter the edges and its weight in the form vertex1  vertex2  weight\n");
for(i=1;i<=e;i++)
{
    scanf("%d%d%d",&e1,&e2,&w);
  capacity[e1][e2] = w;

}
  int s, t;
  printf("Enter the source and the sink\n");
  scanf("%d%d",&s,&t);
  printf("Max Flow: %d\n", fordFulkerson(s, t));
}
