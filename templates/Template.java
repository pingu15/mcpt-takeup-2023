import java.util.*;
import java.io.*;

public class Template {

    static void solve() throws IOException {
        // write code here
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