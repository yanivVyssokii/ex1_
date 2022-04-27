#include <stdio.h>
#include <stdlib.h>
#include "RLEList.h"
#include "AsciiArtTool.h"
#define CHUNK_SIZE 256

RLEList asciiArtRead(FILE* in_stream){

    RLEList list = RLEListCreate();
    while (fgets(buffer, CHUNK_SIZE, in_strem) != NULL) {
    {
        char letter = *buffer;
        while (*buffer == letter)
        {
            RLEListAppend(list, letter);
            buffer++;
        }
    }
    return list;
}

void turnListIntoImage(RLEList list, char* image){
    if (!list||!image){
        return;
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
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream){
    char* image = (char*) malloc(sizeof(char)* RLEListSize(list));
    turnListIntoImage(list,image);
    fputs(image,out_stream);
    free(image);
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream){
    char* str = (char*)malloc(sizeof(char)*checkAmountOfNodes(list)*3);
    RLEListResult* result;
    str=RLEListExportToString(list,result);
    fputs(str,out_stream);
    free(str);
    return RLE_LIST_SUCCESS;
}
