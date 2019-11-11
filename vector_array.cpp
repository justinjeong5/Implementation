/*
 *	2019.6.24
 *	data structure implementation - vector_array
 */
using namespace std;

class Vector {
public:
	int capacity, v_size;
	int* vector;

	Vector() {
		capacity = 8;
		v_size = 0; 
		vector = new int[capacity];
	}
	~Vector() {
		delete[] vector;
	}
	void push_back(int value) {
		if (capacity == v_size)
		{
			capacity *= 2;
			int* temp = new int[capacity];
			for (int i = 0; i < v_size; i++)
			{
				temp[i] = vector[i];
			}
			delete vector;
			vector = temp;
		}
		vector[v_size++] = value;
	}
	void pop_back() {
		if (v_size == 0)
		{
			return;
		}
		v_size--;
	}
	int size() {
		return v_size;
	}
	bool empty() {
		return !v_size;
	}
	void clear() {
		capacity = 8;
		v_size = 0;
		delete[] vector;
		vector = new int[capacity];
	}
	int &operator[](int index) {
		return vector[index];
	}
	int &operator[](const int &index)const {
		return vector[index];
	}
	void operator=(const Vector &temp_vector) {
		capacity = temp_vector.capacity;
		v_size = temp_vector.v_size;
		delete[] vector;
		vector = new int[capacity];
		for (int i = 0; i < v_size; i++)
		{
			vector[i] = temp_vector[i];
		}
	}
};
