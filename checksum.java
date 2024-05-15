import java.util.Scanner;

public class DataLinkLayerChecksum {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the data length: ");
        int dl = scanner.nextInt();

        int[] data1 = new int[dl];
        int[] data2 = new int[dl];
        int[] newdata = new int[dl];
        int[] checksum = new int[dl];

        System.out.println("Enter the first data:");
        for (int i = 0; i < dl; i++)
            data1[i] = scanner.nextInt();

        System.out.println("Enter the second data:");
        for (int i = 0; i < dl; i++)
            data2[i] = scanner.nextInt();

        for (int i = dl - 1; i >= 0; i--) {
            newdata[i] = add(data1[i], data2[i]);
        }

        System.out.print("\nData 1: ");
        printArray(data1);
        System.out.print("Data 2: ");
        printArray(data2);

        System.out.print("\nThe new data is: ");
        printArray(newdata);

        System.out.print("\nChecksum: ");
        for (int i = 0; i < dl; i++) {
            checksum[i] = com(newdata[i]);
            System.out.print(checksum[i]);
        }
        
        System.out.println("\nReceiver Side:");
        System.out.print("Data: ");
        printArray(data1);
        printArray(data2);
        printArray(checksum);

        int[] receivedData = new int[dl];
        for (int i = dl - 1; i >= 0; i--) {
            receivedData[i] = add(newdata[i], checksum[i]);
        }

        System.out.print("\nAddition: ");
        printArray(receivedData);

        System.out.print("\nCompliment: ");
        for (int i = 0; i < dl; i++) {
            System.out.print(com(receivedData[i]));
        }
    }

    public static int add(int x, int y) {
        if ((x + y) % 2 == 0)
            return 0;
        else
            return 1;
    }

    public static int com(int a) {
        if (a == 0)
            return 1;
        else
            return 0;
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
        System.out.print(" ");
    }
}

/*
Enter the data length: 5
Enter the first data:
1
0
1
0
1
Enter the second data:
0
1
1
0
1

Data 1: 10101 Data 2: 01101 
The new data is: 11000 
Checksum: 00111
Receiver Side:
Data: 10101 01101 00111 
Addition: 11111 
Compliment: 00000
=== Code Execution Successful ===
*/




