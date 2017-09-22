make:
	g++ -std=c++11 *pp
	mv a.out TicTacToe
	mkfifo pipe
	rm -rf *.gch

run:
	./TicTacToe init verbose < pipe | ./TicTacToe > pipe

clean:
	rm -rf TicTacToe
	rm -rf pipe

