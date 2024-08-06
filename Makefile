CXX=g++ -static
CXXFLAGS = -Wall -std=c++11
LIB_CXXFLAGS = $(CXXFLAGS) -Iinclude

LIBOBJS = obj/input.o obj/play.o obj/card.o obj/hand.o obj/deck.o
LIBRARY = lib/libfunctions.a

APP_CXXFLAGS = $(CXXFLAGS) -Iinclude
LFLAGS += -Llib -lfunctions

APPOBJS = obj/App.o 
APP = bin/App

build: $(LIBRARY)

$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

obj/%.o: src/%.cpp
	$(CXX) $(LIB_CXXFLAGS) -c $< -o $@

$(APP): $(APPOBJS) $(LIBRARY)
	$(CXX) $(APPOBJS) -o $(APP) $(LFLAGS) 

obj/App.o: app/App.cpp
	$(CXX) $(APP_CXXFLAGS) -c app/App.cpp -o obj/App.o 

app: $(APP)
	./$(APP)

clean:
	rm -f obj/*.o
	rm -f bin/*.exe
	rm -f lib/*.a