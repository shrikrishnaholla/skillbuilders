/**
* Given two lists, get a list of all elements common to both lists
* Use hashMaps to achieve the same
*/

#include <stdio.h>

struct hashMap
{
    int key;
    int value;
}set[20];

void commonalize(int [], int[]);
void generateHashMap(int []);

int main(int argc, char const *argv[])
{
    int array1[10], array2[10];
    int i;
    printf("Enter the elements of the first array (10 elements)\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&array1[i]);
    }
    printf("Enter the elements of the second array (10 elements)\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&array2[i]);
    }
    commonalize(array1,array2);
    printf("The elements common to the two lists are\n");
    for (i = 0; i < 20; i++)
    {
        if (set[i].value > 1)
        {
            printf("%d\t", set[i].key);
        }
    }
    printf("\n");
    return 0;
}

void commonalize(int p[], int q[])
{
    int i, n;
    for (i = 0; i < 20; i++)
    {
        set[i].key = -1; set[i].value = -1;
    }
    generateHashMap(p);
    generateHashMap(q);
    return;
}

void generateHashMap(int a[])
{
    int i,n;
    for (i = 0; i < 10; i++)
    {
        n = a[i]%20;
        if (set[n].value == -1)
        {
            set[n].key = a[i];
            set[n].value = 1;
        }
        else
        {
            if (set[n].key == a[i])
            {
                set[n].value++;
            }
            else
            {
                n = (n+1)%20;
                while(set[n].value != -1)
                {
                    if (set[n].key == a[i])
                    {
                        set[n].value++;
                        break;
                    }
                    n = (n+1)%20;
                }
                if (set[n].value == -1)
                {
                    set[n].key = a[i];
                    set[n].value = 1;
                }
            }
        }
    }
}