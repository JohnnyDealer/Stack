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
	cout << "Элемент удалён: " << this->Stack.top() << endl;
	this->Stack.pop();
	size--;
}

void MyStack::Push(int& a)
{
	this->Stack.push(a);
	cout << "Элемент добавлен" << endl;
	size++;
}

int MyStack::Top()
{
	cout << "Верхний элемент: " << this->Stack.top() << endl;
	return this->Stack.top();
}

bool MyStack::Empty()
{	
	if(this->Stack.empty())
		cout <<"Стэк пуст"<<endl;
	else 
		cout << "Стэк не пустой" << endl;
	return this->Stack.empty();
}

int MyStack::Size()
{
	cout << "Размер Стэка: " << this->Stack.size() << endl;
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
		cout << "индекс за пределами стека" << endl;
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
	cout << "Успешно сгенерировано " << amount_of_elements << " случайных чисел и записано в Стек!" << endl;
}
void MyStack::Clear()
{
	while (!Stack.empty())
		this->Stack.pop();
	this->size = 0;
	cout << "Стек успешно очищен!" << endl;
}

void MyStack::Sort_Optimized()
{
	clock_t start = clock();
	if (size <= 1)
		cout << "Массив уже отсортирован" << endl;
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
	cout << "Стэк отсортирован успешно! " << "(За " << time << " секунд)" << endl;
	cout << "F(n) = " << Fn << endl;
	cout << "O(F(n)) = " << OFn << endl;
	cout << "С1 = " << (log2(size) * (17 * size + 15) + (2 * size + 10)) / time << endl;
	cout << "С2 = " << (log2(size) * size)/time << endl;
}
void MyStack::ShowAllElements()
{	
	if (size == 0)
		cout << "Стек пуст" << endl;
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

		cout << "Весь Стек: ";

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


void MyStack::Sort()  // Вариант I
{
	clock_t start = clock();
	N_op += 2;
	if (size <= 1)  
		cout << "Массив уже отсортирован" << endl;
	else
	{
		stack<int> Temp;       N_op++;          //2 стек 
		stack<int> Change;     N_op++;          //3 стек
		int leftSide = 0;      N_op++;          //левая и правая граница
		int rightSide = 0;     N_op++;
		int mid = 0;           N_op++;          //средний элемент
		iterator = 0;          N_op++;
		int elements = 1;      N_op++;
		N_op+=1;
		for (int k = 0; k < size - 1; k++)   //При начале работы мы перемещаем все элементы (кроме первого, так как он уже отсортирован) во второй стек
		{
			Temp.push(Stack.top());      N_op += 2;
			Stack.pop(); N_op += 1;  
		}
		N_op += 1;
		for (int i = 1; i < size; i++)   //начинаем сортировать
		{
			N_op += 1;
			leftSide = 0;    N_op += 1;
			rightSide = i;   N_op += 1;
			while (leftSide < rightSide)  
			{
				N_op += 1;
				mid = (leftSide + rightSide) / 2;  N_op += 3;//подсчитываем средний элемент (его индекс)
				while (iterator != mid)      //Пока мы не дойдем до элемента, у которого индекс mid, мы будем элементы стека отправлять в третий вспомогательный стек
				{
					N_op += 1;
					Change.push(Stack.top()); N_op += 2;
					Stack.pop(); N_op += 1;
					elements--; N_op += 1;
					iterator--; N_op += 1;
				}
				N_op += 3;
				if (Temp.top() < Stack.top())     //Когда мы добрались до нужного элемента, мы сравниваем его с элементом из второго (Temp) стека
					rightSide = mid;
				else                //Если элемент из основного стека оказался меньше, чем рассматриваемый из второго (Temp), то мы продолжаем сортировку, попутно возвращая наш стек в исходный вид, то есть перебрасывая все элементы обратно из Change -> Stack
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
			
			while (leftSide != elements)    //Когда мы наконец нашли позиции (индекс), куда нужно вставить элемент, мы опять выбрасываем временно все элементы после нужного индекса в Change
			{
				N_op += 1;
				Change.push(Stack.top()); N_op += 2;
				Stack.pop(); N_op += 1;
				elements--; N_op += 1;
			}				
			Stack.push(Temp.top()); N_op += 2;
			Temp.pop(); N_op += 1;
			elements++; N_op += 1;
			while (!Change.empty())      //Ну и напоследок возвращаем все элементы из 3 стека (Change) в основной стек (Stack)
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
	cout << "Стек отсортирован успешно! " << "(За "<< time << " секунд)" << endl;
	cout << "F(n) = " << Fn << endl;
	cout << "O(F(n)) = " << OFn << endl;
	cout << "С1 = " << C1 << endl;
	cout << "С2 = " << C2 << endl;
	cout << "С3 = " << C3 << endl;
	cout << "С4 = " << C4 << endl;
	cout << "Количество операций: " << N_op << endl;
	N_op = 0;
}
void MyStack::BinaryInsertionSort()       // Вариант II
{
	//-----------------------------------------------------------------   Копирование Стэка в массив
	int* tempArray = new int[size];
	iterator = size - 1;
	while (!this->Stack.empty())
	{
		tempArray[iterator] = this->Stack.top();
		--iterator;
		this->Stack.pop();
	}
	//-----------------------------------------------------------------

	//-----------------------------------------------------------------  Сортировка скопированного массива (бинарной вставкой)
	if (size <= 1)
		cout << "Массив уже отсортирован" << endl;
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



	//----------------------------------------------------------------- "Запихивание" отсортированного массива обратно в Стэк

	for(int i =0; i < size ; i++)
		this->Stack.push(tempArray[i]);
	cout << "Стэк отсортирован успешно!" << endl;
	//-----------------------------------------------------------------
}

