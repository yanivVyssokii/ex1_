CC = gcc
FILE_DIR = tool/
OBJS = main.o AsciiArtTool.o RLEList.o
EXEC = AsciiArtTool
DEBUG_FLAG = -g
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
main.o: tool/main.c tool/AsciiArtTool.h RLEList.h tool/AsciiArtTool.c RLEList.c
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(FILE_DIR)*.c
AsciiArtTool.o: $(FILE_DIR)AsciiArtTool.c $(FILE_DIR)AsciiArtTool.h RLEList.h RLEList.c
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $(FILE_DIR)*.c
RLEList.o: RLEList.c RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) *.c
clean:
	rm -f $(OBJS) $(EXEC)

