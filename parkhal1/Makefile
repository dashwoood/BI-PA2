all:
	@g++ -g -Wall -pedantic -Wno-long-long -O0 -ggdb src/*.cpp -o parkhal1

compile: 
	@g++ -g -Wall -pedantic -Wno-long-long -O0 -ggdb src/*.cpp -o parkhal1

run:
	@./parkhal1

clean:
	@rm parkhal1
	@rm -rf doc/
	@rm -f src/saving/*
	@rm -rf src/latex/
	@rm -f src/smart_conf.txt

doc:
	cd src ; doxygen -g smart_conf.txt ; doxygen smart_conf.txt ; mv html ../doc
