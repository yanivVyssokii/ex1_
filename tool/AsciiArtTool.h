//
// Created by User on 4/26/2022.
//

#ifndef MTMEX1__ASCIIARTTOOL_H
#define MTMEX1__ASCIIARTTOOL_H

#include "../RLEList.h"

/**
 * asciiArtRead: Returns an RLEList of the text in the file
 * @param in_stream - the file object of the input
 * @return
 *  The RLE list that represents the given file
 */
RLEList asciiArtRead(FILE* in_stream);

/**
 * asciiArtPrint: Prints the image represented by the given RLE list to the given file
 * @param list - the RLE list which represents the wanted image
 * @param out_stream - the file object the write the image into
 * @return
 *  RLE_LIST_NULL_ARGUMENT if a NULL was sent to the function.
 *  RLE_LIST_SUCCESS if the list was printed printed to the file successfully
 */
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);


/**
 * asciiArtPrintEncoded: Prints the given RLE list to the given file
 * @param list - the RLE list which represents the wanted image
 * @param out_stream - the file object the write the image into
 * @return
 *  RLE_LIST_NULL_ARGUMENT if a NULL was sent to the function.
 *  RLE_LIST_SUCCESS if the list was printed printed to the file successfully
 */
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);


#endif //MTMEX1__ASCIIARTTOOL_H
