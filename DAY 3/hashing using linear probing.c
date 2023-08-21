#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct HashTable {
    int table[SIZE];
    int count;
};

int hashFunction(int key) {
    return key % SIZE;
}

void initializeHashTable(struct HashTable* ht) {
	int i;
    for (i = 0; i < SIZE; i++) {
        ht->table[i] = -1; // -1 indicates an empty slot
    }
    ht->count = 0;
}

void insert(struct HashTable* ht, int key) {
    if (ht->count == SIZE) {
        printf("HashTable is full\n");
        return;
    }

    int index = hashFunction(key);

    while (ht->table[index] != -1) {
        index = (index + 1) % SIZE; // Linear probing
    }

    ht->table[index] = key;
    ht->count++;
}

void display(struct HashTable* ht) {
	int i;
    for (i = 0; i < SIZE; i++) {
        if (ht->table[i] != -1) {
            printf("Index %d: %d\n", i, ht->table[i]);
        }
    }
}

int main() {
    struct HashTable ht;
    initializeHashTable(&ht);

    insert(&ht, 12);
    insert(&ht, 25);
    insert(&ht, 35);
    insert(&ht, 9);
    insert(&ht, 3);
    insert(&ht, 7);
    insert(&ht, 28);
    insert(&ht, 17);

    display(&ht);

    return 0;
}
