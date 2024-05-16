Of course, here's a simplified version of the bit stuffing program:

```c
#include <stdio.h>
#include <string.h>

#define FLAG 0x7E // Flag byte
#define ESCAPE 0x7D // Escape byte

// Function to perform bit stuffing
void bitStuffing(char* input, char* stuffedOutput) {
    int i, j = 0;
    stuffedOutput[j++] = FLAG; // Start with the flag byte

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == FLAG) {
            stuffedOutput[j++] = ESCAPE; // Escape the flag byte
            stuffedOutput[j++] = input[i] ^ 0x20; // XOR with 0x20
        } else if (input[i] == ESCAPE) {
            stuffedOutput[j++] = ESCAPE; // Escape the escape byte
            stuffedOutput[j++] = input[i] ^ 0x20; // XOR with 0x20
        } else {
            stuffedOutput[j++] = input[i]; // Copy the bit
        }
    }

    stuffedOutput[j++] = FLAG; // End with the flag byte
    stuffedOutput[j] = '\0'; // Null terminate the string
}

int main() {
    // Example bit string
    char inputBits[] = "01111110 FLAG 01111110 01111101 ESCAPE 01111101 01111100 FLAG";
    
    // Buffer for stuffed output
    char stuffedOutputBit[100];

    // Perform bit stuffing
    bitStuffing(inputBits, stuffedOutputBit);

    // Print results
    printf("Original bit message: %s\n", inputBits);
    printf("Stuffed bit message: %s\n", stuffedOutputBit);

    return 0;
}
```