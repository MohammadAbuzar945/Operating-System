/*Mohammad Abuzar   
	SP19-BCS-089   */

simpletron:	simpletron.c	libsimpletron.a
	gcc	-o	simpletron.exe	simpletron.c	-L.	-lsimpletron
	 
libsimpletron.a:	util.o
	ar	cr	libsimpletron.a	util.o
	
util.o:	util.c
	gcc	-c	util.c
    
remove:
	rm	simpletron.exe	libsimpletron.a	util.o	simpletron.o
	
	
tar:
	tar	-cvf	SP19-BCS-089.tar	simpletron.c	myheader.h	util.c	makefile
	
untar:
	tar	-xcf	SP19-BCS-089.tar		    
    		
