#ifndef Header_h_
#define Header_h_
#include <iostream>
#include <sstream>
#include <climits>


using namespace std;

struct Vector
{
    private:
        int razmerV { 0 };
        int vmestimostV { 0 };
        int* arr { nullptr };
        int lecsicCompare(const Vector&  v1,const Vector& v2) const
        { 
            for (int i = 0; i < v1.count() && i < v2.count(); i++)
                if (v1.at(i) == v2.at(i))
                    continue; 
                else
                    return v1.at(i) - v2.at(i);
      
            if (v1.count() < v2.count())
                return (v1.count()-v2.count()); 
            else if (v1.count() > v2.count())
                return (v1.count()-v2.count()); 
            else
                return 0;
        } 

    public:    
        Vector () = default;
        explicit Vector(int isize)
        {
            vmestimostV = isize;
            arr = new int[vmestimostV];
        };
        ~Vector()
        {
            delete[] arr;
        };
        void Vin()
        {
            for (int i = 0; i < vmestimostV; i++)
            {
                arr[i] = rand() % 20;
                razmerV++;
            }
        };
        void Vout()
        {
            for (int i = 0; i < razmerV; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        };

        void push(int k)
        {
            if(vmestimostV > razmerV)
            {
                arr[razmerV++] = k;
                return;
            }
            int* arrq = new int[razmerV + 1];
            for (int i = 0; i < razmerV; i++)
            {
                arrq[i] = arr[i];
            }
            arrq[razmerV] = k;
            razmerV++;
            delete[] arr;
            arr = arrq;
        };
        void pop()
        {
            if (razmerV == 0) throw logic_error("Vector pustoy");
            if(vmestimostV > razmerV)
            {
                arr[razmerV--] = 0;
                return;
            }
            razmerV--;
            int* arrq = new int[razmerV];
            for (int i = 0; i < razmerV; i++)
            {
                arrq[i] = arr[i];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (razmerV == 0) throw logic_error("Vector pustoy");
            return arr[razmerV - 1];
        };
        int count() const
        {
            return razmerV;
        };
        int at(int index) const
        {
            if ((index < 0) || (index >= razmerV))
            {
                throw out_of_range("Ne dostypno At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < razmerV; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range(" Vne diapazona: 2147483647");
            return result;
        };

        void concatstruct(const Vector& v1)
        {
            for (int i = 0; i < v1.count(); i++)
                this->push(v1.at(i));
        };
        static Vector concatstructs(const Vector& v1, const Vector& v2)
        {
            Vector concatedVector(0);
            concatedVector.concatstruct(v1);
            concatedVector.concatstruct(v2);
            return concatedVector;
        };

        bool operator == (const Vector& obj) const
        {
            return (lecsicCompare((*this), obj) == 0);
        }

        bool operator > (const Vector& obj) const
        {
            return (lecsicCompare((*this), obj) > 0);
        }

        bool operator < (const Vector& obj) const
        {
            return (lecsicCompare((*this), obj) < 0);
        }

        bool operator <= (const Vector& obj) const
        {
            return (lecsicCompare((*this), obj) <= 0);
        }

        bool operator >= (const Vector& obj) const
        {
            return (lecsicCompare((*this), obj) >= 0);
        }

        bool operator != (const Vector& obj) const
        {
            return (lecsicCompare((*this), obj) != 0);
        }
};

struct Stack
{
    private:
        int razmerS { 0 };        
        int vmestimostS { 0 };
        int* arr { nullptr };
        int lecsicCompare(const Stack&  v1,const Stack& v2) const
        { 
            for (int i = 0; i < v1.count() && i < v2.count(); i++)
                if (v1.at(i) == v2.at(i))
                    continue; 
                else
                    return v1.at(i) - v2.at(i);
      
            if (v1.count() < v2.count())
                return (v1.count()-v2.count()); 
            else if (v1.count() > v2.count())
                return (v1.count()-v2.count()); 
            else
                return 0;
        } 
    public:
        Stack () = default;
        explicit Stack(int isize)
        {
            vmestimostS = isize;
            arr = new int[vmestimostS];

            for (int i = 0; i < vmestimostS; i++)
            {
                arr[i] = 0;
            }
        };
        ~Stack()
        {
            delete[] arr;
        };
        void Vin()
        {
            for (int i = 0; i < vmestimostS; i++)
            {
                arr[i] = rand() % 20;
                razmerS++;
            }
        };
        void Vout()
        {
            for (int i = 0; i < razmerS; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        };
        void push(int k)
        {
            if(vmestimostS > razmerS)
            {
                arr[razmerS++] = k;
                return;
            }
            int* arrq = new int[razmerS + 1];
            for (int i = 0; i < razmerS; i++)
            {
                arrq[i] = arr[i];
            }
            arrq[razmerS] = k;
            razmerS++;
            delete[] arr;
            arr = arrq;
        };
        void pop()
        {
            if (razmerS == 0) throw logic_error("Stack pustoy");
            if(vmestimostS > razmerS)
            {
                arr[razmerS--] = 0;
                return;
            }
            razmerS--;
            int* arrq = new int[razmerS];
            for (int i = 0; i < razmerS; i++)
            {
                arrq[i] = arr[i];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (razmerS == 0) throw logic_error("Stack pustoy");
            return arr[razmerS - 1];
        };
        int count() const
        {
            return razmerS;
        };
        int at(int index) const
        {
            if ((index < 0) || (index >= razmerS))
            {
                throw out_of_range("Ne dostypno At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < razmerS; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Vne diapazona: 2147483647");
            return result;
        };

        void concatstruct(const Stack& s1)
        {
            for (int i = 0; i < s1.count(); i++)
                this->push(s1.at(i));
        };
        static Stack concatstructs(const Stack& s1, const Stack& s2)
        {
            Stack concatedStack(0);
            concatedStack.concatstruct(s1);
            concatedStack.concatstruct(s2);
            return concatedStack;
        };

        bool operator == (const Stack& obj) const
        {
            return (lecsicCompare((*this), obj) == 0);
        }

        bool operator > (const Stack& obj) const
        {
            return (lecsicCompare((*this), obj) > 0);
        }

        bool operator < (const Stack& obj) const
        {
            return (lecsicCompare((*this), obj) < 0);
        }

        bool operator <= (const Stack& obj) const
        {
            return (lecsicCompare((*this), obj) <= 0);
        }

        bool operator >= (const Stack& obj) const
        {
            return (lecsicCompare((*this), obj) >= 0);
        }

        bool operator != (const Stack& obj) const
        {
            return (lecsicCompare((*this), obj) != 0);
        }
};

struct Queue
{
    private:
        int razmerQ{ 0 };
        int vmestimostQ { 0 };
        int* arr{ nullptr };
        int lecsicCompare(const Queue&  v1,const Queue& v2) const
        { 
            for (int i = 0; i < v1.count() && i < v2.count(); i++)
                if (v1.at(i) == v2.at(i))
                    continue; 
                else
                    return v1.at(i) - v2.at(i);
      
            if (v1.count() < v2.count())
                return (v1.count()-v2.count()); 
            else if (v1.count() > v2.count())
                return (v1.count()-v2.count()); 
            else
                return 0;
        } 
    public:
        Queue() = default;

        explicit Queue(int isize)
        {
            vmestimostQ = isize;
            arr = new int[vmestimostQ];

            for (int i = 0; i < vmestimostQ; i++)
            {
                arr[i] = 0;
            }
        };
        ~Queue()
        {
            delete[] arr;
        };
        void Vin()
        {
            for (int i = 0; i < vmestimostQ; i++)
            {
                arr[i] = rand() % 20;
            }
        };
        void Vout()
        {
            for (int i = 0; i < razmerQ; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        };
        void push(int k)
        {
            if(vmestimostQ > razmerQ)
            {
                arr[razmerQ++] = k;
                return;
            }
            int* arrq = new int[razmerQ + 1];
            for (int i = 0; i < razmerQ; i++)
            {
                arrq[i] = arr[i];
            }
            arrq[razmerQ] = k;
            razmerQ++;
            delete[] arr;
            arr = arrq;
        };
        void pop()
        {
            if (razmerQ == 0) throw logic_error("Queue pustaya");
            if(vmestimostQ > razmerQ)
            {
                for (int i = 0; i < razmerQ; ++i)
                {
                    arr[i] = arr[i+1];
                }
                arr[razmerQ] = 0;
                razmerQ--;
                return;
            }
            razmerQ--;
            int* arrq = new int[razmerQ];
            for (int i = 0; i < razmerQ; i++)
            {
                arrq[i] = arr[i + 1];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (razmerQ == 0) throw logic_error("Queue pustaya");
            return arr[0];
        };
        int count() const
        {
            return razmerQ;
        };
        int at(int index) const
        {
            if ((index < 0) || (index >= razmerQ))
            {
                throw out_of_range("Ne dostypno At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < razmerQ; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Vne diapazona: 2147483647");
            return result;
        };

        void concatstruct(const Queue& q1)
        {
            for (int i = 0; i < q1.count(); i++)
                this->push(q1.at(i));
        };
        static Queue concatstructs(const Queue& q1, const Queue& q2)
        {
            Queue concatedQueue(0);
            concatedQueue.concatstruct(q1);
            concatedQueue.concatstruct(q2);
            return concatedQueue;
        };

        bool operator == (const Queue& obj) const
        {
            return (lecsicCompare((*this), obj) == 0);
        }

        bool operator > (const Queue& obj) const
        {
            return (lecsicCompare((*this), obj) > 0);
        }

        bool operator < (const Queue& obj) const
        {
            return (lecsicCompare((*this), obj) < 0);
        }

        bool operator <= (const Queue& obj) const
        {
            return (lecsicCompare((*this), obj) <= 0);
        }

        bool operator >= (const Queue& obj) const
        {
            return (lecsicCompare((*this), obj) >= 0);
        }

        bool operator != (const Queue& obj) const
        {
            return (lecsicCompare((*this), obj) != 0);
        }
};
#endif 