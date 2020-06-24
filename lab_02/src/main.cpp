#include <iostream>
#include"simple_linkes_list.h"
#include"doubly_linked_list.h"
#include"ring_buffer.h"

using namespace std;

int main() {
	try {

		cout << "\t\t\tTEST simple linked list:\n";
		my_list<int> test1;

		cout << "numbers for push front in list:\n";
		for (int i = 0; i < 15; i++) {
			test1.PushFront(i * 2);
			cout << i * 2 << "\t";
		}
		cout << "\nList: \n" << test1 << endl;

		cout << "numbers for push back in list:\n";
		for (int i = 0; i < 5; i++) {
			test1.PushBack(i);
			cout << i << "\t";
		}
		cout << "\nList: \n" << test1 << endl;

		cout << "list pop front:\n";
		for (int i = 0; i < 8; i++) {
			cout << test1.PopFront() << "\t";
		}
		cout << "\n List: \n" << test1 << endl;


		cout << "list pop Back:\n";
		for (int i = 0; i < 8; i++) {
			cout << test1.PopBack() << "\t";
		}
		cout << "\n List: \n" << test1 << endl;

		cout << "insert 25 with index 1\n";
		test1.Insert(25, 1);
		cout << test1 << endl;

		cout << "Erase 25 with index 1\n";
		test1.Erase(1);
		cout << test1 << endl;

		cout << "First and last el-t's:\n";
		cout << *test1.Begin() << "\t" << *test1.End() << endl;

		cout << "Count:\n" << test1.Count() << endl;


		cout << endl << endl;
		cout << "TEST doubly linked list:\n";

		my_double_linked_list<int> test2;

		cout << "number for push front in list:\n";
		for (int i = 0; i < 15; i++) {
			test2.PushFront(i * 2);
			cout << i * 2 << "\t";
		}
		cout << "\nList: \n" << test2 << endl;

		cout << "number for push back in list:\n";
		for (int i = 0; i < 5; i++) {
			test2.PushBack(i);
			cout << i << "\t";
		}
		cout << "\nList: \n" << test2 << endl;

		cout << "list pop front:\n";
		for (int i = 0; i < 8; i++) {
			cout << test2.PopFront() << "\t";
		}
		cout << "\n List: \n" << test2 << endl;


		cout << "list pop Back:\n";
		for (int i = 0; i < 8; i++) {
			cout << test2.PopBack() << "\t";
		}
		cout << "\n List: \n" << test2 << endl;

		cout << "insert 25 with index 1\n";
		test2.Insert(25, 1);
		cout << test2 << endl;

		cout << "Erase 25 with index 1\n";
		test2.Erase(1);
		cout << test2 << endl;

		cout << "First and last el-t's:\n";
		cout << *test2.Begin() << "\t" << *test2.End() << endl;

		cout << "Count:\n" << test2.Count() << endl;


		cout << endl << endl << endl;
		cout << "Test ring buffer:\n";
		my_ring_buffer<int> test3(5);

		cout << "Element's for input to buffer(size = 5): \n";
		for (int i = 0; i < 8; i++) {
			test3.PushBack(i * 2);
			cout << i * 2 << "\t";
		}
		cout << "\nbuffer:\n" << test3 << endl;

		cout << "head:\n";
		cout << *test3.Begin() << endl;
		cout << "tail:\n";
		cout << *test3.End() << endl;

		cout << "pop 4 el-t's:\n";
		for (int i = 0; i < 4; i++) {
			cout << test3.PopFront() << "\t";
		}
		cout << "\n Buffer:\n" << test3 << endl;

		cout << "Count: " << test3.Count() << endl;


		my_list<int> test4{ 1,2,3,4 };
		my_list<int> test4_1{ 2,3,4 };
		my_list<int> test4_2{ 2,3,4,5 };
		my_list<int> test4_3{ 1,2,3 };
		my_list<int> test4_4{ 6,8 };

		std::cout << "Result of contains operation [my_list]:\n"
			<< std::boolalpha << test4.contains(test4_1) << ' '
			<< std::boolalpha << test4.contains(test4_2) << ' '
			<< std::boolalpha << test4.contains(test4_3) << ' '
			<< std::boolalpha << test4.contains(test4_4) << '\n';


		my_ring_buffer<int> test__2__4{ 1,2,3,4 };
		my_ring_buffer<int> test__2__4_1{ 2,3,4 };
		my_ring_buffer<int> test__2__4_2{ 2,3,4,5 };
		my_ring_buffer<int> test__2__4_3{ 1,2,3 };
		my_ring_buffer<int> test__2__4_4{ 6,8 };

		std::cout << "Result of contains operation [my_ring_buffer]:\n"
			<< std::boolalpha << test__2__4.contains(test__2__4_1) << ' '
			<< std::boolalpha << test__2__4.contains(test__2__4_2) << ' '
			<< std::boolalpha << test__2__4.contains(test__2__4_3) << ' '
			<< std::boolalpha << test__2__4.contains(test__2__4_4) << '\n';


		my_double_linked_list<int> test__3__4{ 1,2,3,4 };
		my_double_linked_list<int> test__3__4_1{ 2,3,4 };
		my_double_linked_list<int> test__3__4_2{ 2,3,4,5 };
		my_double_linked_list<int> test__3__4_3{ 1,2,3 };
		my_double_linked_list<int> test__3__4_4{ 6,8 };

		std::cout << "Result of contains operation [my_double_linked_list]:\n"
			<< std::boolalpha << test__3__4.contains(test__3__4_1) << ' '
			<< std::boolalpha << test__3__4.contains(test__3__4_2) << ' '
			<< std::boolalpha << test__3__4.contains(test__3__4_3) << ' '
			<< std::boolalpha << test__3__4.contains(test__3__4_4) << '\n';


		my_list<int> test_5_1{ 1,2,3 };
		my_list<int> test_5_2{ 2,99,-2 };

		std::cout << "MinMax values [my_list]\n"
			<< test_5_1.maxMin() << std::endl
			<< test_5_2.maxMin() << std::endl;

		my_double_linked_list<int> test_5_1_2{ 1,2,3 };
		my_double_linked_list<int> test_5_2_2{ 2,99,-2 };

		std::cout << "MinMax values [my_double_linked_list]\n"
			<< test_5_1_2.maxMin() << std::endl
			<< test_5_2_2.maxMin() << std::endl;

		my_ring_buffer<int> test_5_1_3{ 1,2,3 };
		my_ring_buffer<int> test_5_2_3{ 2,99,-2 };

		std::cout << "MinMax values [my_ring_buffer]\n"
			<< test_5_1_3.maxMin() << std::endl
			<< test_5_2_3.maxMin() << std::endl;

	}
	catch (const std::exception& exp) {
		cout << "Ex: " << exp.what() << endl;
	}
	return 0;
}