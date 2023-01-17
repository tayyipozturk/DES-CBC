#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

char* decimal_to_binary(int n) {
    int i = 0;
    char* binary = (char*)malloc(33 * sizeof(char));
    while (n > 0) {
        binary[i] = (n % 2) + '0';
        n = n / 2;
        i++;
    }
    binary[i] = '\0';
    reverse_string(binary);
    return binary;
}

int binary_to_decimal(char* binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    for (int i = len-1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += base;
        base = base * 2;
    }
    return decimal;
}

void reverse_string(char* str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* string_to_hex(char *str) {
    int len = strlen(str);
    int i;
    char *output = (char *)malloc(len * 2 + 1);
    for (i = 0; i < len; i++) {
        sprintf(output + i * 2, "%02x", str[i] & 0xff);
    }
    output[len * 2] = '\0';
    return output;
}

char* hex_to_binary(char *hex_string) {
    int len = strlen(hex_string);
    char* binary_string = (char*)malloc(len * 4 * sizeof(char));
    int i, j = 0;
    for (i = 0; i < len; i++) {
        switch (hex_string[i]) {
            case '0':
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                break;
            case '1':
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                break;
            case '2':
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                break;
            case '3':
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                break;
            case '4':
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                break;
            case '5':
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                break;
            case '6':
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                break;
            case '7':
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                break;
            case '8':
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                break;
            case '9':
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                break;
            case 'a':
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                break;
            case 'b':
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                break;
            case 'c':
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '0';
                break;
            case 'd':
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                binary_string[j++] = '1';
                break;
            case 'e':
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '0';
                break;
            case 'f':
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                binary_string[j++] = '1';
                break;
        }
    }
    return binary_string;
}

char* binary_to_hex(char* binary_string, int bits) {
    char* hex_string = (char*)malloc(bits/4 * sizeof(char));
    int i, j = 0;
    for (i = 0; i < bits; i += 4) {
        char temp[5] = {binary_string[i], binary_string[i+1], binary_string[i+2], binary_string[i+3], '\0'};
        int decimal = (int) strtol(temp, NULL, 2);
        if (decimal < 10) {
            hex_string[j++] = decimal + '0';
        } else {
            hex_string[j++] = decimal - 10 + 'a';
        }
    }
    return hex_string;
}

void shift_left(char* str, int len, int n) {
    int i;
    char temp[n];
    for (i = 0; i < n; i++) {
        temp[i] = str[i];
    }
    for (i = 0; i < len-n; i++) {
        str[i] = str[i + n];
    }
    for (i = len-n; i < len; i++) {
        str[i] = temp[i - len + n];
    }
}

char* xor_strings(char* str1, char* str2) {
    int len = strlen(str1);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        if (str1[i] == str2[i])
            result[i] = '0';
        else
            result[i] = '1';
    }
    result[len] = '\0';
    return result;
}

void permute_key(const char *key, char *permutation_key, enum permutation_type type) {
    int i;
    switch (type) {
        case permuted_choice_1:
            for (i = 0; i < 56; i++) {
                permutation_key[i] = key[PC1[i] - 1];
            }
            break;
        case permuted_choice_2:
            for (i = 0; i < 48; i++) {
                permutation_key[i] = key[PC2[i] - 1];
            }
            break;
        case initial_permutation:
            for (i = 0; i < 64; i++) {
                permutation_key[i] = key[IP[i] - 1];
            }
            break;
        case expansion_permutation:
            for (i = 0; i < 48; i++) {
                permutation_key[i] = key[E[i] - 1];
            }
            break;
        case permutation:
            for (i = 0; i < 32; i++) {
                permutation_key[i] = key[P[i] - 1];
            }
            break;
        case final_permutation:
            for (i = 0; i < 64; i++) {
                permutation_key[i] = key[FP[i] - 1];
            }
            break;
        default:
            break;
        }
}

void generate_round_keys(char* key, char** round_keys){
    char permuted_key[56];
    permute_key(key, permuted_key, 0);

    char left_half[28], right_half[28];
    for (int i = 0; i < 28; i++) {
        left_half[i] = permuted_key[i];
        right_half[i] = permuted_key[i + 28];
    }

    int round;
    for (round = 0; round < 16; round++) {
        shift_left(left_half, 28, SHIFTS[round]);
        shift_left(right_half, 28, SHIFTS[round]);
        char merged_key[56];
        for (int i = 0; i < 28; i++) {
            merged_key[i] = left_half[i];
            merged_key[i + 28] = right_half[i];
        }
        round_keys[round] = (char*)malloc(48 * sizeof(char));
        permute_key(merged_key, round_keys[round], 1);
        printf("Round %d key: %s\n", round, binary_to_hex(round_keys[round], 48));
    }
}

char* DES(char* plain_text, char** round_keys){
    char* initial_permutation = (char*)malloc(64 * sizeof(char));
    permute_key(plain_text, initial_permutation, 2);
    char left_half[32], right_half[32];
    for (int i = 0; i < 32; i++) {
        left_half[i] = initial_permutation[i];
        right_half[i] = initial_permutation[i + 32];
    }

    char expanded_right[16][48];
    for (int i = 0; i < 16; i++) {
        permute_key(right_half, expanded_right[i], 3);
        char* xor_result = xor_strings(expanded_right[i], round_keys[i]);

        int j;
        char* sbox_output = (char*)malloc(32 * sizeof(char));
        for (j = 0; j < 8; j++) {
            int row = binary_to_decimal(strndup(xor_result + (j * 6), 1) + binary_to_decimal(strndup(xor_result + (j * 6) + 5, 1)));
            int col = binary_to_decimal(strndup(xor_result + (j * 6) + 1, 4));
            char* sbox_output_binary = decimal_to_binary(S[j][row*8+col]);
            for (int k = 0; k < 4; k++) {
                sbox_output[4 * j + k] = sbox_output_binary[k];
            }
        }
        char* permutation = (char*)malloc(32 * sizeof(char));
        permute_key(sbox_output, permutation, 4);
        xor_result = xor_strings(left_half, permutation);

        if (i != 15) {
            for (int k = 0; k < 32; k++) {
                left_half[k] = right_half[k];
                right_half[k] = xor_result[k];
            }
        }
        else {
            for (int k = 0; k < 32; k++) {
                left_half[k] = xor_result[k];
            }
        }
    }
    char* merged = (char*)malloc(64 * sizeof(char));
    for (int i = 0; i < 32; i++) {
        merged[i] = left_half[i];
        merged[i + 32] = right_half[i];
    }
    char* cipher_text = (char*)malloc(64 * sizeof(char));
    permute_key(merged, cipher_text, 5);

    return cipher_text;
}

int main() {
    char* plain_text = "4e6f772069732074";

    char key[] = "0123456789abcdef";
    char* binary_key = hex_to_binary(key);

    char** round_keys = (char**)malloc(16 * sizeof(char*));
    generate_round_keys(binary_key, (char **) round_keys);

    return 0;
}