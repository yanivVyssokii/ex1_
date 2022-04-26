//
// Created by User on 4/26/2022.
//

#ifndef MTMEX1__ASCIIARTTOOL_H
#define MTMEX1__ASCIIARTTOOL_H

#include "RLEList.h"

/**
 * asciiArtRead: Returns an RLEList of the text in the file
 *
 */
RLEList asciiArtRead(FILE* in_stream);

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);


#endif //MTMEX1__ASCIIARTTOOL_H
