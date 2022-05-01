#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RLEList.h"

struct RLEList_t{
    int amount;
    char letter;
    struct RLEList_t* next;
};

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
    if(list == NULL){
        *result = RLE_LIST_NULL_ARGUMENT;
    }
    if (index<0||index>=RLEListSize(list)){
        *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }

    while (index-list->amount>0 && (*result != (RLE_LIST_INDEX_OUT_OF_BOUNDS) && *result!=RLE_LIST_NULL_ARGUMENT)) {
        index-=list->amount;
        list=list->next;
    }

    if (*result!=RLE_LIST_SUCCESS){
        return 0;
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
    return RLE_LIST_SUCCESS;
}

RLEList RLEListCreate()
{
    RLEList ptr = malloc(sizeof(*ptr));
    if(!ptr) {
        return NULL;
    }
    ptr -> next = NULL;
    ptr -> amount = -1;
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
    if( list == NULL || value == '\0'){
        return RLE_LIST_NULL_ARGUMENT;
    }
    while(list->next != NULL){ // list go to her last cell
        list = list->next;
    }
    if (list->amount==-1){
        list->amount=1;
        list->letter=value;
    }
    if(list->letter == value){
        list->amount++;
    }
    else{
        RLEList newHead = RLEListCreate();
        if(!newHead){
            return RLE_LIST_OUT_OF_MEMORY;
        }
        newHead->next=NULL;
        newHead->letter = value;
        newHead->amount = 1;
        list->next = newHead;
    }

    return RLE_LIST_SUCCESS;
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    if(list == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if(RLEListSize(list)<=index){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }

    for( int i=0; i<index-1; i++){
        list = list->next;
    }

    RLEList toDelete = list->next;
    list->next = toDelete->next;
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
    int amount = getAmountOfDigits(list);
    int index = 0;
    if(list == NULL){
        *result = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    char* str = (char*) malloc(sizeof(char*)*(count*2+amount));
    if (str==NULL){
        *result = RLE_LIST_ERROR;
        return NULL;
    }
    for(int i =0; i<count; i++)
    {
        str[index]=list->letter;
        int digits = findNumOfDigits(list->amount);
        char* num = (char*)malloc(sizeof(char)*digits);
        sprintf(num, "%d", list->amount);
        strcat(str,num);
        index+= digits+1;
        str[index]='\n';
        index++;
        list = list->next;
    }
    if(!result){
        return NULL;
    }
    *result = RLE_LIST_SUCCESS;
    return str;
}

int findNumOfDigits(int num)
{
    int count = 0;
    while(num!=0)
    {
        count++;
        num = num/10;
    }
    return count;
}

int getAmountOfDigits(RLEList list)
{
    int count=0;
    while(list!=NULL){
        count+= findNumOfDigits(list->amount);
        list = list->next;
    }
    return count;
}