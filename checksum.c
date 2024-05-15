import java.util.Arrays;

public class HammingCode {
    // Store input bits
    static int[] input = new int[32];
    // Store Hamming code
    static int[] code = new int[32];

    public static void main(String[] args) {
        // Given input message bit
        input[0] = 0;
        input[1] = 1;
        input[2] = 1;
        input[3] = 1;
        int N = 4;

        // Function Call
        solve(input, N);
    }

    // Function to calculate bit for ith position
    static int ham_calc(int position, int c_l) {
        int count = 0;
        int i = position - 1;

        // Traverse to store Hamming Code
        while (i < c_l) {
            for (int j = i; j < Math.min(i + position, c_l); j++) {
                // If current bit is 1
                if (code[j] == 1)
                    count++;
            }
            // Update i
            i = i + 2 * position;
        }
        return count % 2 == 0 ? 0 : 1;
    }

    // Function to calculate Hamming code
    static void solve(int[] input, int n) {
        int i, p_n = 0, c_l, j, k;
        i = 0;
        // Find msg bits having set bit
        // at x'th position of number
        while (n > Math.pow(2, i) - (i + 1)) {
            p_n++;
            i++;
        }
        c_l = p_n + n;
        j = k = 0;
        // Traverse the msgBits
        for (i = 0; i < c_l; i++) {
            // Update the code
            if (i == ((int) Math.pow(2, k) - 1)) {
                code[i] = 0;
                k++;
            }
            // Update the code[i] to the
            // input character at index j
            else {
                code[i] = input[j];
                j++;
            }
        }

        // Traverse and update the Hamming code
        for (i = 0; i < p_n; i++) {
            // Find current position
            int position = (int) Math.pow(2, i);
            // Find value at current position
            int value = ham_calc(position, c_l);
            // Update the code
            code[position - 1] = value;
        }

        // Print the Hamming Code
        System.out.print("The generated Code Word is: ");
        for (i = 0; i < c_l; i++) {
            System.out.print(code[i]);
        }
    }
}
