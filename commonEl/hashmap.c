/**
* Program to implement hashmap in C
*/

#include <stdio.h>
#include <stdlib.h>
#include "mtrace_gc.h"

void getCommon(int[], int[]);

struct hashMap
{
    int key;
    int value;
    struct hashMap* next;
}*common;

int main(int argc, char const *argv[])
{
    mtrace();
    int array1[10], array2[10], i;
    printf("Enter the first array (10 elements)\n");
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &array1[i]);
    }
    printf("Enter the second array(10 elements)\n");
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &array2[i]);
    }
    printf("The common elements are\n");
    getCommon(array1,array2);
    muntrace();
    gc();
    return 0;
}

void getCommon(int a[], int b[]) {
    struct hashMap* temp;
    struct hashMap* index;
    int aDone=0, bDone=0, i;
    for (i = 0; i < 10; ++i)
    {
        if (common!=NULL)
        {
            index = common;
            while(index->next!= NULL) {
                if (index->key == a[i])
                {
                    aDone = 1;
                    index->value++;
                }
                if (index->key == b[i])
                {
                    bDone = 1;
                    index->value++;
                }
                index = index->next;
                if (aDone && bDone)
                    break;
            }
            if (!aDone)
            {
                if (index->key == a[i])
                    index->value++;
                else 
                {
                    temp = (struct hashMap*)malloc(sizeof(struct hashMap));
                    temp->key = a[i];
                    temp->value = 1;
                    temp->next = NULL;
                    index->next = temp;
                }
            }
            if (!bDone)
            {
                if (index->key == b[i])
                    index->value++;
                else if (index->next!= NULL && index->next->key == b[i])
                    index->next->value++;
                else 
                {
                    temp = (struct hashMap*)malloc(sizeof(struct hashMap));
                    temp->key = b[i];
                    temp->value = 1;
                    temp->next = NULL;
                    if (index->next == NULL)
                        index->next = temp;
                    else if(index->next->next == NULL)
                        index->next->next = temp;
                    else
                        printf("See here!\n");
                }
            }
        }
        else {
            common = (struct hashMap*)malloc(sizeof(struct hashMap));
            common->key = a[i];
            common->value = 1;
            if (a[i] == b[i])
            {
                common->value++;
                common->next = NULL;
                continue;
            }
            else
            {
                temp = (struct hashMap*)malloc(sizeof(struct hashMap));
                temp->key = b[i];
                temp->value = 1;
                temp->next = NULL;
                common->next = temp;
            }
        }
        aDone = 0;
        bDone = 0;
    }

    while(common!=NULL) {
        if (common->value > 1)
            printf("%d\t", common->key);
        common = common->next;
    }
    printf("\n");
    
}