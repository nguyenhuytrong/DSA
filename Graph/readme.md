## Graph

### Expression

- Matrix
- Array of Edge
- Adjacency List

### Depth First Search

- Depth is priority, traversal to the deepest. Then backtrack and continue with other node

Pseudocode:

```
// Duyet tu dinh u
DFS(u){

    //Tham dinh u
    visited[u] = true;

    //Duyet cac dinh ke voi u
    for (v : adj[u]) {
        //Neu v chua tham
        if (!visited[v]) {
            DFS(v);
        }
    }

}
```

### Breadth First Search

- Breadth is priority, traversal all the child_nodes from a root, then go deeper
  Pseudocode

```
BFS(u) {
    //Queue de luu thu tu duyet
    queue = {};
    queue.push(u);
    visited[u] = true;

    //Duyet den khi queue empty
    while(!queue.empty()) {

        //Lay phan tu dau tien va xet
        v = queue.front();
        queue.pop();
        visited[v] = true;

        //Duyet qua cac dinh con chua tham cua v va day vao queue
        for (auto x : adj[v]) {
            if (!visited[x]) {
                queue.push(x);
                //Nho danh dau da tham, de khong day x vao queue nhieu lan
                visited[x] = true
            }
        }

    }
}
```

### Connected Component

- Quantity of Connected Component = Quantity of call DFS/BFS

Pseudocode

```
cnt = 0;
for (int i=1; i<=n; i++) {
    //Neu dinh i da duoc tham, nghia la i thuoc 1 tplt
    if (visited[i]) continue;

    //Neu dinh i chua duoc tham, nghia la i chua thuoc 1 tplt nao
    else {
        cnt++;
        visited[i] = true;
        DFS(i) / BFS(i);
    }
}
```

### NOTE 1: A method to build Adjacency List from Map

- Each coordinate is a Node. Each Node connects with Right Node, Left Node, Above Node, Below Node
- Method: use x-coordinate and y-coordinate to form a unique ID: with `i:m` and `j:n` then `ID = i * n + j`

Pseudocode

```
// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
            //Node ID
            int id = i * n + j;

            //Check surrounded Node and form ID
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                    int nid = ni * n + nj;
                    adj[id].push_back(nid);
                }
            }
        }
    }
}
```

### Problems

- Prob1:
- Prob2: [200. Number of Islands](https://leetcode.com/problems/number-of-islands/description/)
