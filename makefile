all:
	g++ ./src/source.cpp -o archive_file_creator.exe -Wall

clean:
	del archive_file_creator.exe *.o