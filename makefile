#######################
###   Hash-hash
#######################


# Compiler settings
C++ = g++
WFLAGS = -Wall -pedantic
OPTFLAGS =
BIN = HashTest.exe
DOX = doxyfile

# Profiling setting
PROFLAGS =

# Directory settings
src = src
inc = inc
out = out
test = test

# Phonies
.PHONY = doc unit test clean

	
# Compilation: Test
test: unit
	$(BIN)

unit: $(out)/HashTest.o
	$(C++) -o $(BIN) $<
   
$(out)/HashTest.o: $(test)/HashTest.cpp $(wildcard $(inc)/*.hpp)
	$(C++) $(WFLAGS) -o $@ -c $<
	
	
# Doxygen
doc:
	doxygen $(DOX)
	
# Clean up
clean:
	del *.exe $(out)/*.o *.out
