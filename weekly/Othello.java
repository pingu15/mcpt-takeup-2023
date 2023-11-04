// Author: Max Sun

import java.util.*;
import java.io.*;

public class Othello {

    // IDEA: 2D-PSA
    // psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1]

    static void solve() throws IOException {
        int N = readInt(), M = readInt(), X = readInt(), Y = readInt(), L = readInt(), ans = 0;
        int[][] board = new int[N+1][N+1];
        for (int i = 0; i < M; i++) {
            int x = readInt(), y = readInt(), w = readInt(), h = readInt();
            board[x][y]++;
            board[x+w][y]--;
            board[x][y+h]--;
            board[x+w][y+h]++;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                board[i][j] += (i == 0 ? 0 : board[i-1][j]) + (j == 0 ? 0 : board[i][j-1]) - (i == 0 || j == 0 ? 0 : board[i-1][j-1]);
                if(board[i][j]%2==1 && !(i >= X && j >= Y && i < X+L && j < Y+L)) ans++; // check if square is white
            }
        }
        pr.println(N*N-ans + " " + ans);
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