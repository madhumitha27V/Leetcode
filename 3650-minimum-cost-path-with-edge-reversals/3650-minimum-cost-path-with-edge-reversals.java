class Solution {
    public int minCost(int n, int[][] edges) {
    
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].add(new int[]{v, w});      
            graph[v].add(new int[]{u, 2 * w}); 
        }

        final int INF = Integer.MAX_VALUE / 2;
        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, 0}); // {cost, node}

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int curCost = top[0];
            int u = top[1];
            if (curCost > dist[u]) continue;
            if (u == n - 1) break; 

            for (int[] nxt : graph[u]) {
                int v = nxt[0], w = nxt[1];
                int newCost = curCost + w;
                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.offer(new int[]{newCost, v});
                }
            }
        }

        return dist[n - 1] >= INF ? -1 : dist[n - 1];
    }
}
