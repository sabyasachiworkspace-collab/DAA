#include <stdio.h>
#include <stdlib.h>
// Structure for Huffman Tree Node
struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};
// Create a new node
struct Node* newNode(char data, unsigned freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Print Huffman Codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    // If leaf node, print code
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}
// Find two nodes with minimum frequency
void sortNodes(struct Node* nodes[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (nodes[j]->freq > nodes[j+1]->freq) {
                struct Node* temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
    }
}

// Build Huffman Tree
struct Node* buildTree(char data[], int freq[], int n) {
    struct Node* nodes[20];

    for (int i = 0; i < n; i++)
        nodes[i] = newNode(data[i], freq[i]);

    while (n > 1) {
        sortNodes(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        nodes[0] = top;
        nodes[1] = nodes[n-1];
        n--;
    }

    return nodes[0];
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(data) / sizeof(data[0]);
    struct Node* root = buildTree(data, freq, n);
    int arr[20], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}
