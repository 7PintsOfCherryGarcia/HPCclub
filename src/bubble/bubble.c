#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LSTSIZE 10

void b_sort(int *lst, int size)
{
    int swap = 1;
    int tmp;
    while (swap) {
        swap = 0;
        for (int i = 1; i < size; i++) {
            if (lst[i - 1] > lst[i]) {
                tmp = lst[i - 1];
                lst[i - 1] = lst[i];
                lst[i] = tmp;
                swap = 1;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int *lst = malloc(LSTSIZE * sizeof(int));
    for (int i = 0; i < LSTSIZE; i++)
        lst[i] = rand() % (100 + 1);

    fprintf(stderr, "unsorted\n");
    for (int i = 0; i < LSTSIZE; i++)
        fprintf(stderr, "\t%u\n", lst[i]);

    b_sort(lst, LSTSIZE);
    fprintf(stderr, "sorted\n");
    for (int i = 0; i < LSTSIZE; i++)
        fprintf(stderr, "\t%u\n", lst[i]);
}
