import java.util.Scanner;
import java.io.*;

/**
 * @author tainic on Nov 28, 2018
 */
public class B {

    //private static final boolean LOCAL = "aurel".equalsIgnoreCase(System.getenv().get("USER"));
    private static final boolean LOCAL = false;

    private static final String TEST =
        "4\n" +
        "SGG";

    void solve(Scanner in, PrintWriter out) {
        in.nextInt();
        char[] a = in.next().toCharArray();
        int gold = 0;
        for (char c : a) {
            if (c == 'G') gold++;
        }
        if (gold == a.length) {
            out.println(gold);
            return;
        }

        int max = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == 'S') {
                int left = 0;
                for (int j = i - 1; j >= 0 && a[j] == 'G'; j--) {
                    left++;
                }

                int right = 0;
                for (int j = i + 1; j < a.length && a[j] == 'G'; j++) {
                    right++;
                }

                if (left + right < gold) {
                    max = Math.max(max, left + right + 1);
                } else {
                    max = gold;
                    break;
                }
            }
        }
        out.println(max);
    }

    //region main
    public static void main(String[] args) {
        Scanner in = new Scanner(!LOCAL ? System.in : new BufferedInputStream(new ByteArrayInputStream(TEST.getBytes())));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out, 2048), false);
        new B().solve(in, out);
        out.close();
    }
    //endregion

    //region imports
    //endregion

}