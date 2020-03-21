salida: main.cpp Partida.hpp Pieza.hpp Peon.hpp Rey.hpp Reina.hpp Alfil.hpp Torre.hpp Caballo.hpp
	g++ -o salida $^

clean: 
	rm -rf salida core