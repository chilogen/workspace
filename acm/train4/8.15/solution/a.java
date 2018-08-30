import java.util.Scanner;

public class a {
    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        main:
        while (sc.hasNext()) {
            final int n = sc.nextInt();
            if (n == 0)
                return;
            final String[] in = new String[n];
            for (int i = 0; i < n; i++)
                in[i] = sc.next().intern();
            final int[] is = new int[n];
            for (int i = 0; i < n; i++)
                if (in[i] != "x")
                    is[i] = Integer.parseInt(in[i]);
            int max = Integer.MAX_VALUE;
            int min = Integer.MIN_VALUE;
            for (int i = 1; i < n; i++)
                if (in[i] == "x")
                    if (in[i - 1] == "x") {
                        System.out.println("none");
                        continue main;
                    } else if (i % 2 == 0)
                        max = Math.min(max, is[i - 1] - 1);
                    else
                        min = Math.max(min, is[i - 1] + 1);
                else if (in[i - 1] == "x")
                    if (i % 2 == 0)
                        min = Math.max(min, is[i] + 1);
                    else
                        max = Math.min(max, is[i] - 1);
                else if (i % 2 == 0) {
                    if (is[i - 1] <= is[i]) {
                        System.out.println("none");
                        continue main;
                    }
                } else {
                    if (is[i - 1] >= is[i]) {
                        System.out.println("none");
                        continue main;
                    }
                }
            if (max > min)
                System.out.println("ambiguous");
            else if (max < min)
                System.out.println("none");
            else
                System.out.println(max);
        }
    }
}