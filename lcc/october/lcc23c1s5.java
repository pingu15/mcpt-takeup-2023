import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Person implements Comparable{
        final int a, b;
        public Person(int a, int b){
            this.a = a;
            this.b = b;
        }

        // Sort people in descending order (priority queue will take the lowest instead of highest value)
        @Override
        public int compareTo(Object o) {
            assert o instanceof Person;
            return this.b - ((Person) o).b;
        }
    }

    // is some set of people possible?
    static boolean possible(PriorityQueue<Person> pq, int k){
        int curDay = 0; // day counter
        for(int i = 0; i < k; i++){
            ++curDay;
            for(int j = 0; j < 3; j++){
                Person tp = pq.poll();
                assert tp != null;
                pq.add(new Person(tp.a, tp.b + tp.a)); // feed this person and add them back
            }
            assert !pq.isEmpty() && pq.peek().b >= curDay;
            if(pq.peek().b == curDay) return false; // if the most urgent person is 'at 0', oh no!
        }
        return true;
    }

    public static String solve(BufferedReader br) {
        try{
            String[] parts = br.readLine().split(" ");
            int n=Integer.parseInt(parts[0]), k=Integer.parseInt(parts[1]);
            parts = br.readLine().split(" ");
            int[] arr=new int[n];
            for(int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            Arrays.sort(arr);

            // binary search!
            int lo=-1, hi=n; // [hi, n) is possible
            while(hi - lo > 1){
                int mid = (lo+hi)/2;

                // add the [mid] highest people
                PriorityQueue<Person> pq = new PriorityQueue<>();
                for(int i = mid; i < n; i++) pq.add(new Person(arr[i], arr[i]));
                if(possible(pq, k)) hi = mid;
                else lo = mid;
            }

            return "" + (n-hi);
        } catch(Exception e){
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solve(br));
    }
}