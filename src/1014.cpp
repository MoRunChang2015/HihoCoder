#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node {
    int count;
    node* next[26];
    node() {
        count = 0;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};

node* root = new node;

void triePush(char* str) {
    node* p = root;
    int temp;
    for (int i = 0; i < strlen(str); i++) {
        temp = str[i] - 'a';
        if (p->next[temp] == nullptr) {
            p->next[temp] = new node;
        }
        p = p->next[temp];
        p->count++;
    }
}

int trieFind(char* str) {
    node* p = root;
    int temp;
    for (int i = 0; i < strlen(str); i++) {
        temp = str[i] - 'a';
        if (p->next[temp] == nullptr) return 0;
        p = p->next[temp];
    }
    return p->count;
}

void deleteTrie(node* p) {
    for (int i = 0; i < 26; i++)
        if (p->next[i] != nullptr) deleteTrie(p->next[i]);
    delete p;
}

int main() {
    int i, n;
    char str[20];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        triePush(str);
    }

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        printf("%d\n", trieFind(str));
    }

    deleteTrie(root);
    return 0;
}
