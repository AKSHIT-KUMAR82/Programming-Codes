// Given two polynomials P1 and P2
// Create two linked lists, 1 for each.
// The linked list should have 2 values (Coefficient and Power), along with a pointer to next node.
// After inserting the polynomials in their respective linked lists, add them together to form a third linked list.
// Output the resultant string.
// Example:  P1= "-2x^2+3x+4" P2="x^2-x+10"

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int coeff;
  int power;
  struct node *next;
};
typedef struct node node;

void push(node **front, node **rear, int co, int po)
{
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  if (temp == NULL)
  {
    printf("Insertion Failed.");
  }
  else
  {
    temp->coeff = co;
    temp->power = po;
    temp->next = NULL;
    if (*front == NULL)
    {
      (*front) = temp;
      (*rear) = temp;
    }
    else
    {
      (*rear)->next = temp;
      *rear = temp;
    }
  }
}

void display(node *f)
{
  if (f == NULL)
  {
    printf("List is Empty\n");
  }
  else
  {
    while (f->next != NULL)
    {
      printf("(%dx^%d)+", f->coeff, f->power);
      f = f->next;
    }
    printf("(%dx^%d)\n", f->coeff, f->power);
  }
}

void setList(char str[], node **f, node **r)
{
  int num = 0, count = 0, co = 0, po = 0;
  for (char *ptr = str; *ptr != '\0'; ptr++)
  {

    if ((*ptr >= '0' && *ptr <= '9') || *ptr == '-')
    {
      num = strtol(ptr, &ptr, 10);
      if (count == 0)
      {
        co = num;
        count++;
      }
      else
      {
        po = num;
        count++;
      }
    }
    if (count == 2)
    {
      push(f, r, co, po);
      count = 0;
      co = 0;
      po = 0;
    }
  }
}

void sumList(node *f1, node *f2, node **fs, node **rs)
{
  int cos = 0, pos = 0, co1 = 0, po1 = 0, co2 = 0, po2 = 0;
  while (f1 != NULL && f2 != NULL)
  {
    if (f1 == NULL)
    {
      co1 = 0;
      po1 = 0;
    }
    else
    {
      co1 = f1->coeff;
      po1 = f1->power;
    }
    if (f2 == NULL)
    {
      co2 = 0;
      po2 = 0;
    }
    else
    {
      co2 = f2->coeff;
      po2 = f2->power;
    }

    if (po1 == po2)
    {
      push(fs, rs, co1 + co2, po1);
      f1 = f1->next;
      f2 = f2->next;
    }
    else
    {
      if (po1 > po2)
      {
        push(fs, rs, co1, po1);
        f1 = f1->next;
      }
      else
      {
        push(fs, rs, co2, po2);
        f2 = f2->next;
      }
    }
  }
}

int main()
{
  char po1[] = "(4x^3)+(-2x^2)+(3x^1)+(4x^0)";
  char po2[] = "(1x^3)+(-1x^1)+(10x^0)";

  node *front1 = NULL, *rear1 = NULL;
  node *front2 = NULL, *rear2 = NULL;

  setList(po1, &front1, &rear1);
  setList(po2, &front2, &rear2);

  node *frontSum = NULL, *rearSum = NULL;

  sumList(front1, front2, &frontSum, &rearSum);
  printf("\nPolynomial 1: ");
  display(front1);
  printf("\nPolynomial 2: ");
  display(front2);
  printf("\nSum of Polynomials: ");
  display(frontSum);
}