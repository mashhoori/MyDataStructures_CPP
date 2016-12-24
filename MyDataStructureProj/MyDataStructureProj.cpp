// MyDataStructureProj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyLinkedList.h"

int main()
{
	MyLinkedList<int> list;	
	
	list.Add(3);
	list.Add(4);
	list.Add(5);

	MyLinkedList<int> list2;

	std::cout << &list2 << std::endl;
	list2 = list;
	std::cout << &list2 << std::endl;
		
	/*
	ist.Print();
	cout << list.GetSize()<<endl;
	*/
	//list.RemoveAt(2);	
	//list.Print();
	
	list.Remove(3);
	list.Remove(5);

	list.Print();
	list2.Print();


	getchar();
    return 0;
}

