CC = gcc
CFLAGS = -fpic -Wall
JAVA_FILE = natifUpd.java
OUT_DIR = /root/demo/fuzzer_from_scratch
OUTFILE = $(OUT_DIR)/natif_natifUpd.so

all:	natif_natifUpd.c

	javac -h . $(JAVA_FILE)

	jar cvf Main.jar *

	# "$<" is an automatic variable which means "all dependencies"
	$(CC) -shared $(CFLAGS) -o $(OUTFILE) -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux $< 


clean:
	rm -r libMain.so *.class $(OUTFILE)
