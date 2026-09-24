#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
char stk[100];
int top = -1;
void push(char x)
{
    top++;
    stk[top] = x;   }
char pop()
{  char x = stk[top];
    top--;   return x;   } 
int pre(char x)
{
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;    }
int infixtopostfix(char in[], char post[])
{    int i = 0, j = 0;
    char x;
    push('(');
    strcat(in, ")");
    while (in[i] != '\0')
    { 
         if (isdigit(in[i]))
        {
            while (isdigit(in[i]))     {
                post[j] = in[i];
                i++;
      j++;
            }
                post[j] = ' ';
               j++;
         }
        else if (in[i] == '(')
        {
            push('(');
            i++;
        }
        else if (in[i] == ')')
        {
            while (stk[top] != '(')
            {
                post[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else
        {
            while (top != -1 && pre(stk[top]) >= pre(in[i]))
            {
                post[j] = pop();
                j++;
            }

            push(in[i]);
            i++;
        }
    }

    post[j] = '\0';
    return 0;
}

int eva(char post[])
{
    strcat(post, ")");

    int s[100], t = -1, i = 0, a, b, n;

    while (post[i] != ')')
    {
        if (isdigit(post[i]))
        {
            n = 0;

            while (isdigit(post[i]))
            {
                n = n * 10 + (post[i] - '0');
                i++;
            }

            t++;
            s[t] = n;
        }
        else if (post[i] != ' ')
        {
            a = s[t--];
            b = s[t--];

            if (post[i] == '+')
            {
                t++;
                s[t] = b + a;
            }
            else if (post[i] == '-')
            {
                t++;
                s[t] = b - a;
            }
            else if (post[i] == '*')
            {
                t++;
                s[t] = b * a;
            }
            else if (post[i] == '/')
            {
                t++;
                s[t] = b / a;
            }
            else if (post[i] == '^')
            {
                t++;
                s[t] = (int)pow(b, a);
            }

            i++;
        }
        else
            i++;
    }

    return s[t];
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter infix: ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", eva(postfix));

    return 0;
}
