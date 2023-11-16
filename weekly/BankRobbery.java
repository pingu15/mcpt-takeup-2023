import java.util.*;
import java.io.*;

public class BankRobbery {

    // TOPIC: MULTI-SOURCE BFS

    static class Node {
        int id;
        boolean isF;
        Node(int id, boolean isF) {
            this.id = id;
            this.isF = isF; // is this your friend?
        }
    }

    @SuppressWarnings("unchecked")
    static void solve() throws IOException {
        int N = readInt(), M = readInt(), E = readInt(), S = readInt(), F = readInt();
        boolean[] exit = new boolean[N+1];
        for (int i = 0; i < E; i++) exit[readInt()] = true;
        ArrayDeque<Node> queue = new ArrayDeque<>();
        queue.add(new Node(F, true)); // add friend to bfs queue
        for(int i = 0; i < S; i++) queue.add(new Node(readInt(), false)); // add all the security guards to bfs queue
        ArrayDeque<Integer>[] adj = new ArrayDeque[N+1];
        for (int i = 1; i <= N; i++) adj[i] = new ArrayDeque<>();
        for (int i = 0; i < M; i++) {
            int a = readInt(), b = readInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        boolean[] vis = new boolean[N+1];
        boolean flag = false;
        while(!queue.isEmpty() && !flag) { // BFS
            Node cur = queue.poll();
            if(vis[cur.id]) continue;
            if(exit[cur.id] && cur.isF) flag = true; // friend has reached an exit before any security guards
            vis[cur.id] = true;
            for(int nxt : adj[cur.id]) {
                if(!vis[nxt]) queue.add(new Node(nxt, cur.isF));
            }
        }
        pr.println(flag ? "YES" : "NO");
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintStream pr;

    static String next() throws IOException {
        if (!st.hasMoreTokens())
            st = new StringTokenizer(readLine());
        return st.nextToken();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer("");
        pr = System.out;
        solve();
    }

}
