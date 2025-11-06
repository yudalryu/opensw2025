./bin/myapp : ./object/func1.o ./object/func2.o ./object/main.o 
	gcc -o $@ $^

./object/%.o : ./src/%.c
	gcc -o $@ -c $< -I./include

clean : 
	rm ./bin/myapp
	rm ./object/*.o