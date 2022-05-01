CC = gcc
OBJS = main.o AsciiArtTool.o RLEList.o
EXEC = AsciiArtTool
DEBUG_FLAG = -g
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
main.o: tool/main.c tool/AsciiArtTool.h RLEList.h tool/AsciiArtTool.c RLEList.c
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) tool/*.c
AsciiArtTool.o: tool/AsciiArtTool.c tool/AsciiArtTool.h RLEList.h RLEList.c
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) tool/*.c
RLEList.o: RLEList.c RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) *.c
clean:
	rm -f $(OBJS) $(EXEC)


