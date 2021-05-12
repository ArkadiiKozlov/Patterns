all: Patterns

Modules = Logger.o LoggerImpl.o Composite1.o main.o
Patterns: $(Modules)
	g++ -std=c++11 $(Modules) -o $@

%.o: %.cpp %.h
	g++ -std=c++11 -c $< -o $@ 

%.o: %.cpp *.h
	g++ -std=c++11 -c $< -o $@ 

clean:
	rm -f ./*.o Patterns

