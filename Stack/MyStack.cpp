#include "MyStack.h"
#include <random>
#include <time.h>


MyStack::MyStack()
{

}

MyStack::~MyStack()
{
	while (!this->Stack.empty())
		this->Stack.pop();
}

void MyStack::Pop()
{
	cout << "������� �����: " << this->Stack.top() << endl;
	this->Stack.pop();
	size--;
}

void MyStack::Push(int& a)
{
	this->Stack.push(a);
	cout << "������� ��������" << endl;
	size++;
}

int MyStack::Top()
{
	cout << "������� �������: " << this->Stack.top() << endl;
	return this->Stack.top();
}

bool MyStack::Empty()
{	
	if(this->Stack.empty())
		cout <<"���� ����"<<endl;
	else 
		cout << "���� �� ������" << endl;
	return this->Stack.empty();
}

int MyStack::Size()
{
	cout << "������ �����: " << this->Stack.size() << endl;
	return this->Stack.size();
}

int MyStack::Get(int& index)
{
	stack<int> Temp;
	int number = 0;
	int size_temp = this->Stack.size() - 1;
	for (int i = size_temp; i > index; i--)
	{
		Temp.push(Stack.top());
		Stack.pop();
	}
	number = Stack.top();
	while (!Temp.empty())
	{
		Stack.push(Temp.top());
		Temp.pop();
	}
	return number;
}
void MyStack::Insert(int& index, int& value)
{
	stack<int> Temp;
	int size_temp = this->Stack.size() - 1;
	if (index > size_temp)
		cout << "������ �� ��������� �����" << endl;
	else
	{
		for (int i = size_temp; i >= index; i--)
		{
			Temp.push(Stack.top());
			Stack.pop();
		}
		Stack.push(value);
		while (!Temp.empty())
		{
			Stack.push(Temp.top());
			Temp.pop();
		}
	}
	
}
void MyStack::Randomize(int& amount_of_elements)
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 100);
	for (int i = 0; i < amount_of_elements; i++)
	{
		Stack.push(distribution(generator));
		size++;
	}
	cout << "������� ������������� " << amount_of_elements << " ��������� ����� � �������� � ����!" << endl;
}
void MyStack::Clear()
{
	while (!Stack.empty())
		this->Stack.pop();
	this->size = 0;
	cout << "���� ������� ������!" << endl;
}

void MyStack::Sort_Optimized()
{
	clock_t start = clock();
	if (size <= 1)
		cout << "������ ��� ������������" << endl;
	else
	{
		stack<int> Temp;                             
		int leftSide = 0;                
		int rightSide = 0;
		int mid = 0;                    
		for (int k = 0; k < size - 1; k++)   
		{
			Temp.push(Stack.top());
			Stack.pop();
		}
		for (int i = 1; i < size; i++)   
		{
			leftSide = 0;
			rightSide = i;
			while (leftSide < rightSide)
			{
				mid = (leftSide + rightSide) / 2; 
				if (Temp.top() < MyStack::Get(mid))    
					rightSide = mid;
				else                
				{
					leftSide = mid + 1;
				}

			}
			MyStack::Insert(leftSide, Temp.top());
			Temp.pop();
		}
	}
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	double Fn = log2(size) * (17 * size + 15) + (2 * size + 10);
	double OFn = log2(size) * size;
	double C1 = Fn / time;
	double C2 = OFn / time;
	cout << "���� ������������ �������! " << "(�� " << time << " ������)" << endl;
	cout << "F(n) = " << Fn << endl;
	cout << "O(F(n)) = " << OFn << endl;
	cout << "�1 = " << (log2(size) * (17 * size + 15) + (2 * size + 10)) / time << endl;
	cout << "�2 = " << (log2(size) * size)/time << endl;
}
void MyStack::ShowAllElements()
{	
	if (size == 0)
		cout << "���� ����" << endl;
	else 
	{
		int* tempArray = new int[size];
		iterator = size - 1;
		while (!this->Stack.empty())
		{
			tempArray[iterator] = this->Stack.top();
			--iterator;
			this->Stack.pop();
		}

		cout << "���� ����: ";

		for (int i = 0; i < size; i++)
		{
			cout << tempArray[i] << " ";
			this->Stack.push(tempArray[i]);
		}

		/*for (int i = 0; i < size; i++)
			cout << MyStack::Get(i) << " ";*/

		cout << endl;
	}
	
}


void MyStack::Sort()  // ������� I
{
	clock_t start = clock();
	N_op += 2;
	if (size <= 1)  
		cout << "������ ��� ������������" << endl;
	else
	{
		stack<int> Temp;       N_op++;          //2 ���� 
		stack<int> Change;     N_op++;          //3 ����
		int leftSide = 0;      N_op++;          //����� � ������ �������
		int rightSide = 0;     N_op++;
		int mid = 0;           N_op++;          //������� �������
		iterator = 0;          N_op++;
		int elements = 1;      N_op++;
		N_op+=1;
		for (int k = 0; k < size - 1; k++)   //��� ������ ������ �� ���������� ��� �������� (����� �������, ��� ��� �� ��� ������������) �� ������ ����
		{
			Temp.push(Stack.top());      N_op += 2;
			Stack.pop(); N_op += 1;  
		}
		N_op += 1;
		for (int i = 1; i < size; i++)   //�������� �����������
		{
			N_op += 1;
			leftSide = 0;    N_op += 1;
			rightSide = i;   N_op += 1;
			while (leftSide < rightSide)  
			{
				N_op += 1;
				mid = (leftSide + rightSide) / 2;  N_op += 3;//������������ ������� ������� (��� ������)
				while (iterator != mid)      //���� �� �� ������ �� ��������, � �������� ������ mid, �� ����� �������� ����� ���������� � ������ ��������������� ����
				{
					N_op += 1;
					Change.push(Stack.top()); N_op += 2;
					Stack.pop(); N_op += 1;
					elements--; N_op += 1;
					iterator--; N_op += 1;
				}
				N_op += 3;
				if (Temp.top() < Stack.top())     //����� �� ��������� �� ������� ��������, �� ���������� ��� � ��������� �� ������� (Temp) �����
					rightSide = mid;
				else                //���� ������� �� ��������� ����� �������� ������, ��� ��������������� �� ������� (Temp), �� �� ���������� ����������, ������� ��������� ��� ���� � �������� ���, �� ���� ������������ ��� �������� ������� �� Change -> Stack
				{
					leftSide = mid + 1; N_op += 2;
					while (!Change.empty())  
					{
						N_op += 1;
						Stack.push(Change.top());  N_op += 2;
						Change.pop(); N_op += 1;
						elements++; N_op += 1;
					}
					iterator = elements - 1; N_op += 2;
				}

					
			}
			
			while (leftSide != elements)    //����� �� ������� ����� ������� (������), ���� ����� �������� �������, �� ����� ����������� �������� ��� �������� ����� ������� ������� � Change
			{
				N_op += 1;
				Change.push(Stack.top()); N_op += 2;
				Stack.pop(); N_op += 1;
				elements--; N_op += 1;
			}				
			Stack.push(Temp.top()); N_op += 2;
			Temp.pop(); N_op += 1;
			elements++; N_op += 1;
			while (!Change.empty())      //�� � ���������� ���������� ��� �������� �� 3 ����� (Change) � �������� ���� (Stack)
			{
				N_op += 1;
				Stack.push(Change.top());   N_op += 2;
				Change.pop();           N_op += 1;
				elements++;        N_op += 1;
			}
			iterator = elements - 1;   N_op += 2;
			N_op += 1;
		}
	}
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	double Fn = log2(size) * (17 * size + 15) + (2 * size + 10);
	double OFn = log2(size) * size;
	double C1 = Fn / time;
	double C2 = OFn / time;
	double C3 = Fn / N_op;
	double C4 = OFn / N_op;
	cout << "���� ������������ �������! " << "(�� "<< time << " ������)" << endl;
	cout << "F(n) = " << Fn << endl;
	cout << "O(F(n)) = " << OFn << endl;
	cout << "�1 = " << C1 << endl;
	cout << "�2 = " << C2 << endl;
	cout << "�3 = " << C3 << endl;
	cout << "�4 = " << C4 << endl;
	cout << "���������� ��������: " << N_op << endl;
	N_op = 0;
}
void MyStack::BinaryInsertionSort()       // ������� II
{
	//-----------------------------------------------------------------   ����������� ����� � ������
	int* tempArray = new int[size];
	iterator = size - 1;
	while (!this->Stack.empty())
	{
		tempArray[iterator] = this->Stack.top();
		--iterator;
		this->Stack.pop();
	}
	//-----------------------------------------------------------------

	//-----------------------------------------------------------------  ���������� �������������� ������� (�������� ��������)
	if (size <= 1)
		cout << "������ ��� ������������" << endl;
	else
	{
		int leftSide = 0;
		int rightSide = 0;
		int mid = 0;
		for (int i = 1; i < size; i++)
		{
			leftSide = 0;
			rightSide = i;
			int element = tempArray[i];
			while (leftSide < rightSide)
			{
				mid = (leftSide + rightSide) / 2;
				if (element < tempArray[mid])
					rightSide = mid;
				else
					leftSide = mid + 1;
			}
			for(int j = i; j > leftSide; j--)
				tempArray[j] = tempArray[j - 1];
			tempArray[leftSide] = element;
		}
	}
	//-----------------------------------------------------------------



	//----------------------------------------------------------------- "�����������" ���������������� ������� ������� � ����

	for(int i =0; i < size ; i++)
		this->Stack.push(tempArray[i]);
	cout << "���� ������������ �������!" << endl;
	//-----------------------------------------------------------------
}

