import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        String[][] people = new String[N][2];

        for (int i = 0; i < N; i++) {
            people[i][0] = String.valueOf(scanner.nextInt());  
            people[i][1] = scanner.next();  
        }

        Arrays.sort(people, new Comparator<String[]>() {
            @Override
            public int compare(String[] o1, String[] o2) {
                return Integer.compare(Integer.parseInt(o1[0]), Integer.parseInt(o2[0]));
            }
        });

        for (String[] person : people) {
            System.out.println(person[0] + " " + person[1]);
        }

        scanner.close();
    }
}