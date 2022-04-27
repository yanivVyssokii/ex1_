#include <stdio.h>
#include <stdlib.h>
#include "RLEList.h"

struct RLEList_t{
    int amount;
    char letter;
    struct RLEList_t* next;
}

int RLEListSize(RLEList list){
    if (!list){
        return -1;
    }
    int size = 0;
    while (list){
        size+=list->amount;
        list=list->next;
    }
    return size;
}

char RLEListGet(RLEList list, int index, RLEListResult *result){
    if (result!=RLE_LIST_SUCCESS){
        return 0;
    }
    if (index<0||index>=RLEListSize(list)||){
        return RLE_LIST_ERROR;
    }
    while (index-list->amount>0){
        index-=list->amount;
        list=list->next;
    }
    return list->letter;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    if (!list||!map_function){
        return RLE_LIST_NULL_ARGUMENT;
    }
    while(list){
        list->letter=(*map_function)(list->letter);
        list=list->next;
    }
    return LIST_SUCCESS;
}

RLEList RLEListCreate()
{
    RLEList ptr = malloc(sizeof(*ptr));
    if(!ptr) {
        return NULL;
    }
    ptr -> next = NULL;
    return ptr;
}

void RLEListDestroy(RLEList list)
{
    while(list) {
        RLEList toDelete = list;
        list = list->next;
        free(toDelete);
    }

}

RLEListResult RLEListAppend(RLEList list, char value)
{
    if(!list || value == NULL)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }
    struct RLEList newHead = RLEListCreate();
    if(!newHead)
    {
        return RLE_LIST_OUT_OF_MEMORY;
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    if(index == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    for( int i=0; i<index; i++){
        list = list->next;
    }
    if(RLEListSize(list)<=index){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    RLEList toDelete = list;
    list = list->next;
    free(toDelete);
    return RLE_LIST_SUCCESS;
}

int checkAmountOfNodes(RLEList list)
{
    int count = 0;
    while(list){
        count++;
        list = list->next;
    }
    return count;
}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    int count = checkAmountOfNodes(list);
    int index = 0;
    if(!list){
        *result = RLE_LIST_NULL_ARGUMENT;
    }
    char* str = (char*) malloc(sizeof(char*)*count*3);
    if (!str){
        *result = RLE_LIST_ERROR;
    }
    for(int i =0; i<count; i++)
    {
        str[index]=list->letter;
        str[index+1]=list->amount;
        str[index+2]='\n';
        index+=3;
        list = list->next;
    }
    if(!result){
        return NULL;
    }
    result = LIST_SUCCESS;
    return str;
}