#include<stdio.h>
#include<stdlib.h>

struct node
{
    int roll;
    struct node *next;
};

struct node *root = NULL;

void addEnd(int value)
{
    struct node *cur = root;
    if(root == NULL) {
        root = (struct node*) malloc(sizeof(struct node));

        root->roll = value;
        root->next = NULL;
    }

    else {
        while(cur->next!=NULL) {
            cur = cur->next;
        }

        struct node *temp = (struct node*) malloc(sizeof(struct node));

        temp->roll = value;
        temp->next = NULL;

        cur->next = temp;
    }
}

void print( )
{
    struct node *cur = root;

    while(cur != NULL) {
        printf("%d ", cur->roll);
        cur = cur->next;
    }

    printf("\n");
}

void find(int n)
{
    int pos = 1;
    struct node *cur = root;
    while(cur!=NULL)
    {
        if(cur->roll == n)
        {
            printf("pos = %d\n", pos);
        }
        cur = cur->next;
        pos++;
    }
}

int main()
{
    int i;
    for(i=0; i<12; i++)
    {
        addEnd(i);
    }
    print();
    find(3);

    return 0;
}
