CC = gcc
FILE_DIR = tool/
OBJS = main.o AsciiArtTool.o RLEList.o
EXEC = AsciiArtTool
DEBUG_FLAG = -g
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
main.o: main.c AsciiArtTool.h RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(FILE_DIR)*.c
AsciiArtTool.o: AsciiArtTool.c AsciiArtTool.h RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(FILE_DIR)*.c
RLEList.o: RLEList.c RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(FILE_DIR)*.c
clean:
	rm -f $(OBJS) $(EXEC)

