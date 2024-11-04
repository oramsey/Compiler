# Owen Ramsey
# lab9
# April 22, 2024

#
# the lab 9 executable creates lex.yy.c from our lex code
# it creates y.tab.c from our y file
# gcc compiles all the .c files
# test asm makes the machime code 
# test mars makes the machine code and runs it

all:	lab9 
   
lab9: ast.c lab9.l lab9.y symtable.c emit.c 
	lex lab9.l 
	yacc -d lab9.y  
	gcc  ast.c lex.yy.c y.tab.c symtable.c emit.c  -o lab9 

test: 
		./lab9 < varTest.c

testasm:
		./lab9  -o foo < varTest.c

testmars:
		./lab9  -o foo < varTest.c
		java -jar Mars4_5.jar sm foo.asm
	

clean:
	rm -f lab9 
