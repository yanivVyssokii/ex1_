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