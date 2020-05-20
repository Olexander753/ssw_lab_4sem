#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
#include "header.h"

int main()
{
	try {

		using ns = std::chrono::nanoseconds;

		Vector v1(5);
		std::vector<int> v2;
		Stack s1(5);
		std::stack<int> s2;
		Queue q1(5);
		std::queue<int> q2;
		
		

		cout << endl;
		cout << "\t\t\tPerformance comparison results" << endl;
		cout << "\t\t\t  (all results in nanoseconds)" << endl << endl;
		cout << "type\t\t" << "push\t\t" << "pop\t\t" << "peek\t\t" << "count\t\t" << "at" << endl;
		
		cout << "My stack\t";
		auto start = std::chrono::high_resolution_clock::now();
		s1.push(34);
		auto end = std::chrono::high_resolution_clock::now();
		auto res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		s1.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		s1.push(11);

		start = std::chrono::high_resolution_clock::now();
		s1.peek();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		s1.count();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;


		cout << "STL stack\t";
		start = std::chrono::high_resolution_clock::now();
		s2.push(99);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		s2.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		s2.push(3);

		start = std::chrono::high_resolution_clock::now();
		s2.top();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		s2.push(3);

		start = std::chrono::high_resolution_clock::now();
		s2.size();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;



		cout << endl << "My queue\t";
		start = std::chrono::high_resolution_clock::now();
		q1.push(3);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		q1.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		q1.push(12);
		start = std::chrono::high_resolution_clock::now();
		q1.peek();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		q1.count();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;


		cout << "STL queue\t";
		start = std::chrono::high_resolution_clock::now();
		q2.push(2);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		q2.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		q2.push(22);

		start = std::chrono::high_resolution_clock::now();
		q2.front();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		q2.size();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;




		cout << endl << "My vector\t";
		start = std::chrono::high_resolution_clock::now();
		v1.push(4);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		v1.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		v1.push(4);
		start = std::chrono::high_resolution_clock::now();
		v1.peek();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		v1.push(22);

		start = std::chrono::high_resolution_clock::now();
		v1.count();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t" ;

		start = std::chrono::high_resolution_clock::now();
		v1.at(0);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t" << endl;


		cout << "STL vector\t";
		start = std::chrono::high_resolution_clock::now();
		v2.push_back(22);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		v2.pop_back();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << "\t\t";

		v2.push_back(22);

		start = std::chrono::high_resolution_clock::now();
		v2.size();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		v2.at(0) = 1;
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << endl;

	}
	catch (const std::exception & exp)
	{
		cout << exp.what() << endl;
	}

	return 0;
}