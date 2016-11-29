SOURCES =	main.cpp \
		sdlglutils.cpp\
                accueil.cpp\
                game.cpp\
                ennemis.cpp\
                lib_fst.cpp
OBJECTS	=	$(SOURCES:.cpp=.o)	
LIBS	=	$(shell sdl-config --cflags --libs) -lglut -lGLU -lGL -ljpeg -lm -lSDL_image -lSDL_mixer

all: $(OBJECTS)
	g++ $(SOURCES) -o Cube $(LIBS)

%o: %cpp
	g++ -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

superclean : clean
	rm -rf $(TARGET)


