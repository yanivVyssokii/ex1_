OBJS = main.o AsciiArtTool.o RLEList.o
EXEC = AsciiArtTool
AsciiArtTool: main.o AsciiArtTool.o RLEList.o
	gcc main.o AsciiArtTool.o RLEList.o -o AsciiArtTool
main.o: main.c AsciiArtTool.h RLEList.h
	gcc -c main.c
AsciiArtTool.o: AsciiArtTool.c AsciiArtTool.h RLEList.h
	gcc -c AsciiArtTool.c
RLEList.o: RLEList.c RLEList.h
	gcc -c RLEList.c
clean:
	rm -f $(OBJS) $(EXEC)
