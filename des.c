#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
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

int binary_to_decimal(char* binary, int len) {
    int decimal = 0;
    int base = 1;
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
    char* binary_string = (char*)malloc(len * 4 * sizeof(char)+1);
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

char* xor_strings(char* str1, char* str2, int len) {
    char* result = (char*)malloc(len);
    for (int i = 0; i < len; i++) {
        if (str1[i] == str2[i])
            result[i] = '0';
        else
            result[i] = '1';
    }
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
    }
}

char* generate_random_initialization_vector() {
    srand(time(NULL));
    char* iv = (char*)malloc(64 * sizeof(char));
    for (int i = 0; i < 64; i++) {
        iv[i] = rand() % 2 + '0';
    }
    return iv;
}

void padding(char* binary_plain_text, int len) {
    int padding_len = (64 - len) % 64;
    if (padding_len > 4) {
        strcat(binary_plain_text, "1000");
    }
    for (int i = 4; i < padding_len; i++) {
        strcat(binary_plain_text, "0");
    }
}

char** divide_plain_text_to_blocks(char* plain_text, int len) {
    int blocks = len / BLOCK_SIZE;
    if (len % BLOCK_SIZE != 0) {
        blocks++;
    }
    char** divided = (char**)malloc(blocks * sizeof(char*));
    for (int i = 0; i < blocks; i++) {
        divided[i] = (char*)malloc(BLOCK_SIZE * sizeof(char));
        strncpy(divided[i], plain_text + i * BLOCK_SIZE, BLOCK_SIZE);
    }
    return divided;
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
        char* xor_result = xor_strings(expanded_right[i], round_keys[i], 48);
//        printf("Round %d: %s\n", i + 1, binary_to_hex(xor_result, 48));

        int j;
        char* sbox_output = (char*)malloc(32 * sizeof(char));
        for (j = 0; j < 8; j++) {
            char row[2] = { xor_result[j * 6], xor_result[j * 6 + 5] };
            char column[4] = { xor_result[j * 6 + 1], xor_result[j * 6 + 2], xor_result[j * 6 + 3], xor_result[j * 6 + 4] };
            int row_int = binary_to_decimal(row, 2);
            int col_int = binary_to_decimal(column, 4);
            int sbox_val = S[j][16 * row_int + col_int];
//            printf("S:%d: j:%d\n",sbox_val ,j);
            char* sbox_val_binary = decimal_to_binary(sbox_val);
            for (int k = 0; k < 4; k++) {
                sbox_output[j * 4 + k] = sbox_val_binary[k];
            }
        }
        printf("S box output: %s\n", binary_to_hex(sbox_output, 32));
        char* permutation = (char*)malloc(32 * sizeof(char));
        permute_key(sbox_output, permutation, 4);
        printf("Round %d permutation: %s\n", i + 1, binary_to_hex(permutation, 32));
        xor_result = xor_strings(left_half, permutation, 32);
        printf("XOR %d: %s\n", i + 1, binary_to_hex(xor_result, 32));

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

char** DES_CBC(char** blocks, unsigned long block_count, char* iv, char** round_keys, int mode) {
    char** cipher_block = (char**)malloc(block_count * sizeof(char*));
    char* cipher_text;
    char* xor_result;
    char* block;
    char* previous_block = iv;
    int i;
    for (i = 0; i < block_count; i++) {
        block = blocks[i];
        if (mode == 0) {
            xor_result = xor_strings(block, previous_block, BLOCK_SIZE);
            cipher_text = DES(xor_result, round_keys);
            cipher_block[i] = cipher_text;
            strncpy(iv, cipher_text, 64);
            previous_block = block;
        }
        else {
            cipher_text = DES(block, round_keys);
            xor_result = xor_strings(cipher_text, previous_block, BLOCK_SIZE);
            cipher_block[i] = xor_result;
            strncpy(iv, block, 64);
            previous_block = block;
        }
    }
    return cipher_block;
}


int main() {
    struct timeval start, end;

    char* plain_text = "4e6f772069732074";
    char* binary_plain_text = hex_to_binary(plain_text);
    padding(binary_plain_text, strlen(binary_plain_text));
    char** blocks = divide_plain_text_to_blocks(binary_plain_text, strlen(binary_plain_text));
    unsigned long block_count = strlen(binary_plain_text) / BLOCK_SIZE;

    char key[] = "0123456789abcdef";
    char* binary_key = hex_to_binary(key);

    char** round_keys = (char**)malloc(16 * sizeof(char*));
    generate_round_keys(binary_key, (char **) round_keys);

    char* IV = generate_random_initialization_vector();
    char* init_vector = "fe5567e8d7695508";
    char* binary_init_vector = hex_to_binary(init_vector);
    IV = binary_init_vector;

    char* cipherText = DES(binary_plain_text, round_keys);
    printf("Cipher text: %s\n", binary_to_hex(cipherText, 64));

    gettimeofday(&start, NULL);

    printf("Plain text: %s\n", plain_text);

//    char** encrypted_block = DES_CBC(blocks, block_count, IV, round_keys, 0);
//    int i;
//    for(i=0; i<block_count; i++){
//        char* block = malloc(64 * sizeof(char));
//        strncpy(block, encrypted_block[i], 64);
//        printf("Encrypted %d: %s\n",i , binary_to_hex(block, 64));
//    }

//    char** decrypted_block = DES_CBC(encrypted_block, block_count, IV, round_keys, 1);
//    for(i=0; i<block_count; i++){
//        char* block = malloc(64 * sizeof(char));
//        strncpy(block, decrypted_block[i], 64);
//        printf("Decrypted %d: %s\n", i, binary_to_hex(block, 64));
//    }

//    gettimeofday(&end, NULL);
//    printf("Generating keys took %lu microseconds\n", (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec);

    return 0;
}