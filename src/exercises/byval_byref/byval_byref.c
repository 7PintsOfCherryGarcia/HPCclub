#include <stdio.h>
#include <stdlib.h>

void setx(int x, int val)
{
    fprintf(stderr, "In setcx\n");
    fprintf(stderr, "\taddress of x: %p\n", (void *)&x);
    x = val;
}

void setx_byref(int *x, int val)
{
    *x = val;
}

void allocatep(int *p, int n)
{
    fprintf(stderr, "Allocating p\n");
    p = malloc(n * sizeof(int));
    fprintf(stderr, "\tp: %p\n", (void *)p);
    for (int i = 0; i < 10; i++)
        p[i] = i;

}

int max(int *array, int size)
{
    return array[size];
}

int min(int *array, int size)
{
    return array[0];
}

int median(int *array, int size)
{
    return array[0];
}

int main()
{
    int x = 23;
    //fprintf(stderr, "value of x: %d\n", x);
    //fprintf(stderr, "address of x: %p\n", (void *)&x);
    //int *p = &x;
    //fprintf(stderr, "value of p: %p\n", (void *)p);
    //fprintf(stderr, "value of p's reference: %d\n", *p);
    //*p = 4652;
    //fprintf(stderr, "value of p: %p\n", (void *)p);
    //fprintf(stderr, "value of p's reference: %d\n", *p);
    //fprintf(stderr, "value of x: %d\n", x);
    //fprintf(stderr, "address of x: %p\n", (void *)&x);
    //setx(x, 48);
    //fprintf(stderr, "x: %d\n", x);

    //setx_byref(&x, 48);
    //fprintf(stderr, "x: %d\n", x);

    //int *p = NULL;
    //int y = *p;
    //fprintf(stderr, "p: %p\n", (void *)p);
    //allocatep(p, 10);
    //fprintf(stderr, "p: %p\n", (void *)p);
    //free(p);
}
