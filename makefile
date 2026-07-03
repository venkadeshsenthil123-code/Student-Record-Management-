outfile: main.o add.o del.o show.o modify.o load.o save.o sort.o reverse.o delete_all.o
	cc main.c add.c del.c show.c modify.c load.c save.c sort.c reverse.c delete_all.c -o outfile

main.o: main.c
	cc -c main.c

add.o: add.c
	cc -c add.c

del.o: del.c
	cc -c del.c

show.o: show.c
	cc -c show.c

modify.o: modify.c
	cc -c modify.c

save.o: save.c
	cc -c save.c

load.o: load.c
	cc -c load.c

sort.o: sort.c
	cc -c sort.c

reverse.o: reverse.c
	cc -c reverse.c

delete_all.o: delete_all.c
	cc -c delete_all.c

