import java.util.Arrays;
import java.util.Scanner;

public class d {
    public static final int MOD = 1_000_000_007;

    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        main:
        while (sc.hasNext()) {
            final int N = sc.nextInt();
            final int M = sc.nextInt();
            if (N == 0 && M == 0)
                return;
            final UnionFind uf = new UnionFind(N);
            for (int i = 0; i < M; i++)
                uf.union(sc.nextInt() - 1, sc.nextInt() - 1);
            final int cnt = uf.countComponents();
            int ans = 1;
            for (int i = 0; i < cnt; i++) {
                ans <<= 1;
                if (ans > MOD)
                    ans -= MOD;
            }
            if (cnt < N)
                ans++;
            System.out.println(ans);
        }
    }

    public static class UnionFind {
        final int[] tree;

        UnionFind(final int size) {
            tree = new int[size];
            Arrays.fill(tree, -1);
        }

        int root(final int idx) {
            return tree[idx] < 0 ? idx : (tree[idx] = root(tree[idx]));
        }

        boolean union(int x, int y) {
            x = root(x);
            y = root(y);
            if (x == y)
                return false;
            if (tree[x] > tree[y]) {
                final int tmp = x;
                x = y;
                y = tmp;
            }
            tree[x] += tree[y];
            tree[y] = x;
            return true;
        }

        int countComponents() {
            int cnt = 0;
            for (final int i : tree)
                if (i < 0)
                    cnt++;
            return cnt;
        }
    }
}
