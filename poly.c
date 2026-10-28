
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *createNode(int c, int e)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}

struct node *createp()
{
    struct node *head = NULL, *temp, *newNode;
    int n, i, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);

        newNode = createNode(c, e);

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *head = NULL, *temp = NULL, *newNode;
    int c, e;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            c = p1->coeff + p2->coeff;
            e = p1->exp;

            if (c != 0)
            {
                newNode = createNode(c, e);

                if (head == NULL)
                    head = newNode;
                else
                    temp->next = newNode;

                temp = newNode;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            newNode = createNode(p1->coeff, p1->exp);

            if (head == NULL)
                head = newNode;
            else
                temp->next = newNode;

            temp = newNode;
            p1 = p1->next;
        }
        else
        {
            newNode = createNode(p2->coeff, p2->exp);

            if (head == NULL)
                head = newNode;
            else
                temp->next = newNode;

            temp = newNode;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        newNode = createNode(p1->coeff, p1->exp);

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        newNode = createNode(p2->coeff, p2->exp);

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
        p2 = p2->next;
    }

    return head;
}

void display(struct node *p)
{
    if (p == NULL)
    {
        printf("0");
        return;
    }

    while (p != NULL)
    {
        printf("%dx^%d", p->coeff, p->exp);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }

    printf("\n");
}

int main()
{
    struct node *p1, *p2, *sum;

    printf("Enter first pcreatepnomial:\n");
    p1 = createp();

    printf("Enter second pcreatepnomial:\n");
    p2 = createp();

    printf("\nFirst pcreatepnomial: ");
    display(p1);

    printf("Second pcreatepnomial: ");
    display(p2);

    sum = addp(p1, p2);

    printf("Sum of pcreatepnomials: ");
    display(sum);

    return 0;
}
