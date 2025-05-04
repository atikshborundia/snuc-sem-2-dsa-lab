//This program is used to implement treeADT using linked list
#include <cstdio>
#include <cstdlib>

class tree {
private:
    struct node {
        char data;
        struct node *left;
        struct node *right;
    } *root;

public:
    tree() {
        root = NULL;
    }

    struct node **getroot() {
        return &root;
    }

    struct node *getrootnode() {
        return root;
    }

    void insert(char num, struct node **temp);
    void preorder(struct node *temp);
    void inorder(struct node *temp);
    void postorder(struct node *temp);
    bool search(struct node *temp, char num);
};

int main() {
    int sel = 1;
    char cha;
    tree t1;

    while (sel != 6) {
        printf("\nEnter 1 to insert\nEnter 2 to Preorder\nEnter 3 to Inorder\nEnter 4 to Postorder\nEnter 5 to Search\nEnter 6 to Exit\n");
        scanf("%d", &sel);
        switch (sel) {
            case 1:
                printf("Enter the character to be inserted\n");
                scanf(" %c", &cha);
                t1.insert(cha, t1.getroot());
                break;
            case 2:
                printf("Preorder traversal: ");
                t1.preorder(t1.getrootnode());
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                t1.inorder(t1.getrootnode());
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                t1.postorder(t1.getrootnode());
                printf("\n");
                break;
            case 5:
                printf("Enter the number to be searched\n");
                scanf(" %c", &cha);
                if (t1.search(t1.getrootnode(), cha)) {
                    printf("%c found in the tree\n", cha);
                } else {
                    printf("%c not found in the tree\n", cha);
                }
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}

//This function is used to insert a element in the tree
void tree::insert(char num, struct node **temp) {
    if (*temp == NULL) {
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        temp1->data = num;
        temp1->left = NULL;
        temp1->right = NULL;
        *temp = temp1;
        printf("Inserted %c\n", num);
        return;
    }

    char ch;
    printf("Enter l for left or r for right to be inserted\n");
    scanf(" %c", &ch);

    if (ch == 'l') {
        insert(num, &((*temp)->left));
    } else if (ch == 'r') {
        insert(num, &((*temp)->right));
    } else {
        printf("Enter valid input\n");
        insert(num, temp);
    }
}

// This function is used to show the elements in preorder
void tree::preorder(struct node *temp) {
    if (temp != NULL) {
        printf("%c ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

// This function is used to show the ements in inoder
void tree::inorder(struct node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%c ", temp->data);
        inorder(temp->right);
    }
}

// This function is used to show the elements in postorder
void tree::postorder(struct node *temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%c ", temp->data);
    }
}

// This function is used to search a element in the tree
bool tree::search(struct node *temp, char num) {
    if (temp == NULL) {
        return false;
    }

    if (temp->data == num) {
        return true;
    }

    return search(temp->left, num) || search(temp->right, num);
}