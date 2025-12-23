#include <stdio.h>

#define MAX 20

int hashTable[MAX];
int m;

void initialize() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}


int hashFunction(int key) {
    return key % m;
}


void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        printf("Collision occurred at address %d\n", index);
        int i = (index + 1) % m;

        while (i != index) {
            if (hashTable[i] == -1) {
                hashTable[i] = key;
                return;
            }
            i = (i + 1) % m;
        }
        printf("Hash table is full\n");
    }
}


void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    initialize();

    printf("Enter number of employee records (n): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}

