CC := gcc
NAME := tools
c_flags := -Wall -pedantic
BD := ./build
ID := /opt/inc
INC := -I$(ID)
LIB := -L/opt/bin/lib
DST := /opt/bin/lib

object: p_$(NAME).c
	$(CC) -o $(BD)/_$(NAME).o -c -fPIC -Wall -Werror p_$(NAME).c

rel:  object
	$(CC) -shared -o $(BD)/_$(NAME).so $(BD)/_$(NAME).o

debug: object
	$(CC) -shared -o $(BD)/_$(NAME).so $(BD)/_$(NAME).o -g -DDEBUG


clean:
	rm -f $(BD)/$(NAME) $(BD)/*.o $(BD)/*.so



test: $(NAME)_test.c $(ID)/p_$(NAME).h
	$(CC) -o $(NAME)_d $(NAME)_test.c $(LIB) -l$(NAME) $(c_flags) -g -DDEBUG
	$(CC) -o $(NAME)_nd $(NAME)_test.c $(LIB) -l$(NAME) $(c_flags) -g -DNDEBUG
	./$(NAME)_d
	./$(NAME)_nd

install: rel
ifeq ("","$(wildcard $(DST)/lib$(NAME).so)")
	sudo ln -s $$PWD/$(BD)/_$(NAME).so $(DST)/lib$(NAME).so
endif
	sudo cp p_$(NAME).h /opt/inc/