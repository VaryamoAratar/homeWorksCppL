#include <iostream>
#include <exception>

//Обертка для перегрузки оператора [] для столбцов
template<typename T>
class TWrapper
{
public:
	TWrapper(int cols, T* arr) : _cols(cols), _arr(arr)
	{};

	T& operator [] (int j)
	{
		if (j < 0 || j >= _cols)
		{
			throw std::out_of_range("out_of_range");
		}

		return _arr[j];
	}
		T& operator [] (int j) const
	{
		if (j < 0 || j >= _cols)
		{
			throw std::out_of_range("out_of_range");
		}

		return _arr[j];
	}

private:
	T* _arr;
	int _cols;
};
//Шаблонный класс таблицы
template<class T>
class Table
{
public:
	//Конструктор
	Table(int rows, int cols) :_rows(rows), _cols(cols)
	{
		_arr = new  T * [_rows];
		for (int i = 0; i < _rows; i++)
		{
			_arr[i] = new T[_cols]{ 0 };
		}
	};
	//Деструктор
	~Table()
	{
		for (int i = 0; i < _rows; i++)
		{
			delete[] _arr[i];
		}
		delete[] _arr;
	};
	//Конструктор копирования
	Table(const Table& copy)
	{
		_rows = copy._rows;
		_cols = copy._cols;
		_arr = new T * [_rows];
		for (int i = 0; i < _rows; i++)
		{
			_arr[i] = new T[_cols]{ 0 };
		}
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++)
			{
				_arr[i][j] = copy._arr[i][j];
			}
		}
	};
	// Оператор =
	Table& operator = (const Table& copy)
	{
		if (this != &copy)
		{
			for (int i = 0; i < _rows; i++)
			{
				delete[] _arr[i];
			}
			delete[] _arr;
			_rows = copy._rows;
			_cols = copy._cols;
			_arr = new T * [_rows];
			for (int i = 0; i < _rows; i++)
			{
				_arr[i] = new T[_cols]{ 0 };
			}
			for (int i = 0; i < _rows; i++)
			{
				for (int j = 0; j < _cols; j++)
				{
					_arr[i][j] = copy._arr[i][j];
				}
			}
		}
		return *this;
	}
	//Перегруженный оператор [] для строк
	TWrapper<T> operator [] (int i)
	{
		if (i < 0 || i >= _rows)
		{
			throw std::out_of_range("out_of_range");
		}
		TWrapper<T> result(_cols, _arr[i]);

		return result;
	}
	const TWrapper<T> operator [] (int i) const
	{
		if (i < 0 || i >= _rows)
		{
			throw std::out_of_range("out_of_range");
		}
		TWrapper<T> result(_cols, _arr[i]);

		return result;
	}

	int get_rows() { return _rows; }
	int get_cols() { return _cols; }
	//Возвращает пару ROWS and COLS
	std::pair<int, int> Size() const
	{
		return { _rows , _cols };
	}
private:
	T** _arr;
	int _rows;
	int _cols;
};



int main(int argc, char* agrv[])
{
	Table<int> test(8, 7);
	try
	{
	test[0][0] = 4;
	test[1][1] = 5;
	std::cout << "Size of table: " << test.Size().first << 'x' << test.Size().second << std::endl;
	for (int i = 0; i < test.get_rows(); i++)
	{
		for (int j = 0; j < test.get_cols(); j++)
		{
			std::cout << test[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
	return 0;
}