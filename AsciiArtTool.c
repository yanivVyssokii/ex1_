#include <stdio.h>
#include <stdlib.h>
#include "AsciiArtTool.h"
#include "RLEList.h"
#define CHUNK_SIZE 256


RLEList asciiArtRead(FILE* in_stream) {
    RLEList list = RLEListCreate();
    char letter=(char)fgetc(in_stream);
    do {
        if( feof(in_stream) ) {
            break ;
        }
        RLEListAppend(list, letter);
        letter=(char)fgetc(in_stream);
    } while(1);
    return list;
}

void turnListIntoImage(RLEList list, char* image)
{
    if (!list||!image){
        return;
    }
    int index=0;
    while (list!=NULL){
        int count = list->amount;
        while(count>0) {
            image[index] = list->letter;
            index++;
            count--;
        }
        list=list->next;
    }
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    char* image = (char*) malloc(sizeof(char)* RLEListSize(list));
    turnListIntoImage(list,image);
    fputs(image,out_stream);
    free(image);
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream){
    char* str;
    RLEListResult* result = (RLEListResult*)malloc(sizeof(RLEListResult*)) ;
    str=RLEListExportToString(list,result);
    free(result);
    fputs(str,out_stream);
    free(str);
    return RLE_LIST_SUCCESS;
}

