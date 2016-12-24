// MyDataStructureProj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyLinkedList.h"

MyLinkedList<int> GetList();


int main()
{
	///*MyLinkedList<int> list;	
	//
	//list.Add(3);
	//list.Add(4);
	//list.Add(5);

	//MyLinkedList<int> list2;

	//std::cout << &list2 << std::endl;
	//list2 = list;
	//std::cout << &list2 << std::endl;*/
		
	/*
	ist.Print();
	cout << list.GetSize()<<endl;
	*/
	//list.RemoveAt(2);	
	//list.Print();
	/*
	list.Remove(3);
	list.Remove(5);

	list.Print();
	list2.Print();*/

	MyLinkedList<int> list3(GetList());
	std::cout << &list3 << std::endl;
	list3.Print();

	MyLinkedList<int> list4;
	list4 = GetList();
	std::cout << &list4 << std::endl;
	list4.Print();

	
	getchar();
    return 0;
}


MyLinkedList<int> GetList()
{
	MyLinkedList<int> list;

	list.Add(30);
	list.Add(40);
	list.Add(50);

	return list;
}