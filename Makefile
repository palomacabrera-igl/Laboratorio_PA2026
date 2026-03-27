CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
OBJS = DTFecha.o DTRefer.o Publicacion.o ArticuloRevista.o Libro.o PaginaWeb.o Investigador.o main.o
TARGET = lab0

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

DTFecha.o: DTFecha.cpp DTFecha.h
	$(CXX) $(CXXFLAGS) -c DTFecha.cpp

DTRefer.o: DTRefer.cpp DTRefer.h DTFecha.h
	$(CXX) $(CXXFLAGS) -c DTRefer.cpp

Publicacion.o: Publicacion.cpp Publicacion.h DTFecha.h DTRefer.h
	$(CXX) $(CXXFLAGS) -c Publicacion.cpp

ArticuloRevista.o: ArticuloRevista.cpp ArticuloRevista.h Publicacion.h
	$(CXX) $(CXXFLAGS) -c ArticuloRevista.cpp

Libro.o: Libro.cpp Libro.h Publicacion.h
	$(CXX) $(CXXFLAGS) -c Libro.cpp

PaginaWeb.o: PaginaWeb.cpp PaginaWeb.h Publicacion.h
	$(CXX) $(CXXFLAGS) -c PaginaWeb.cpp

Investigador.o: Investigador.cpp Investigador.h DTFecha.h Publicacion.h
	$(CXX) $(CXXFLAGS) -c Investigador.cpp

main.o: main.cpp DTFecha.h ArticuloRevista.h Libro.h PaginaWeb.h Investigador.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean