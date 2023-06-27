CC = gcc
OUTFILE = /home/researcher/targets/libMain.so


all:	Main.cpp
	javac Main.java

	javac -h . Main.java

	# "$<" is an automatic variable which means "all dependencies"
	$(CC) -shared -fpic -o $(OUTFILE) -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux $< 


clean:
	rm -r $(OUTFILE)
