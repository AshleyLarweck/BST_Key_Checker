p3: yya310p3.o BinarySearchTree.o
	gcc yya310p3.o BinarySearchTree.o -o p3
yya310p3.o: yya310p3.c BinarySearchTree.h
	gcc -c yya310p3.c -o yya310p3.o 
BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h
	gcc -c BinarySearchTree.c -o BinarySearchTree.o  
clean:
	rm -rf *.o 
	rm p3