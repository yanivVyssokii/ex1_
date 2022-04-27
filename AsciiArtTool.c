#include "AsciiArtTool.h"
#include "RLElist.h"
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

