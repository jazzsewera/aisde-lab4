VPATH := $(shell find src/sources -type d)

SOURCES := $(shell find src -type f -name *.cpp)


tmp := $(patsubst %.cpp, %.o, $(SOURCES))
OBJECTS := $(foreach obj, $(tmp), objects/$(notdir $(obj)))


tmp := $(shell find src/headers -type d)
INCLUDEDIRS := $(foreach dir, $(tmp), -I$(dir))

INCLUDEDIRS += -I/usr/local/include


tmp := /usr/local/lib
LIBDIRS := $(foreach dir, $(tmp), -L$(dir))

LIBS = -lm -lstdc++
FLAGS = # -D_DEBUG


kolejka: $(OBJECTS)
	@$(CXX) $(LIBDIRS) $(LIBS) -o $@ objects/*.o

objects/%.o: %.cpp
	@$(CXX) $(INCLUDEDIRS) $(FLAGS) -c -o $@ $<

clean:
	@rm -f kolejka core objects/*.o
