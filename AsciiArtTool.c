#include <stdio.h>
#include <stdlib.h>
#include "RLEList.h"
#include "AsciiArtTool.h"

RLEListResult turnListIntoImage(RLEList list, char* image){
    if (!list||!image){
        return RLE_LIST_NULL_ARGUMENT;
    }
    int index=0;
    while (!list){
        int count = list->amount;
        while(count>0) {
            image[index] = list->letter;
            index++;
            count--;
        }
        list=list->next;
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream){
    char* image = (char*) malloc(sizeof(char)* RLEListSize(list));
    turnListIntoImage(list,image);
    fputs(image,out_stream);
    free(image);
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream){

}
