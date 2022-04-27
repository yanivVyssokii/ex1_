#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RLEList.h"
#include "AsciiArtTool.h"

char map_function (char letter);

int main(int argc, char ** argv)
{
  FILE *in_stream = fopen(argv[2],'r');
  FILE *out_stream = fopen(argv[3],'w');

  char* flag = argv[1];
  RLEList list =  asciiArtRead(in_stream);
  if(!strcmp(flag, "-e"))
  {
     asciiArtPrintEncoded(list, out_stream);
  }
  if(!strcmp(flag, "-i"))
  {
      RLEListMap(list,&map_function);
      asciiArtPrint(list,out_stream);
  }
  fclose(in_stream);
  fclose(out_stream);
}

char map_function (char letter)
{
    if(letter == '@'){
        return ' ';
    }
    if(letter == ' '){
        return '@';
    }
    return letter;
}
