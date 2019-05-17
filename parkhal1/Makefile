all:
	@mkdir -p parkhal1
	@g++ -g -Wall -pedantic -Wno-long-long -O0 -ggdb src/*.cpp -o game_engine 
	@mv game_engine parkhal1/

compile: 
	@mkdir -p parkhal1
	@g++ -g -Wall -pedantic -Wno-long-long -O0 -ggdb src/*.cpp -o game_engine 
	@mv game_engine parkhal1/

run:
	@clear
	@parkhal1/./game_engine

clean:
	@rm -f parkhal1/*
	@rm -d -f parkhal1/
	@rm -f src/savings/*
