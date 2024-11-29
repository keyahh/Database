#ifndef HEAPCPP
#define HEAPCPP
#include "Heap.h"

template<typename T>
Heap<T>::Heap()
{
}

template<typename T>
Heap<T>::Heap(const std::initializer_list<T>& list)
{
	for (auto& x : list)
	{
		push(x);
	}
}

template<typename T>
void Heap<T>::push(const T& item)
{
	_nodes.push_back(item);
	reheapifyUp(_nodes.size() - 1);
}

template<typename T>
void Heap<T>::pop()
{
	_nodes[0] = _nodes[_nodes.size() - 1];
	_nodes.pop_back();
	reheapifyDown(0);
}

template<typename T>
T& Heap<T>::top()
{
	return _nodes[0];
}

template<typename T>
bool Heap<T>::empty()
{
	return _nodes.empty();
}

template<typename T>
int Heap<T>::size()
{
	return _nodes.size();
}


template<typename T>
void Heap<T>::reheapifyUp(int childIndex)
{
	int parentIndex = getParentIndex(childIndex);
	if (parentIndex < _nodes.size() && parentIndex >= 0)
	{
		if (_nodes[parentIndex] < _nodes[childIndex])
		{
			std::swap(_nodes[parentIndex], _nodes[childIndex]);
			reheapifyUp(parentIndex);
		}
	}
}

template<typename T>
void Heap<T>::reheapifyDown(int parentIndex)
{
	int GCI = getGreaterChildIndex(parentIndex);
	if(GCI < _nodes.size())
	{
		if (_nodes[parentIndex] < _nodes[GCI])
		{
			std::swap(_nodes[parentIndex], _nodes[GCI]);
			reheapifyDown(GCI);
		}
	}

}

template<typename T>
int Heap<T>::getParentIndex(int childIndex)
{
	return (childIndex - 1) / 2;
}

template<typename T>
int Heap<T>::getLeftChildIndex(int parentIndex)
{
	return 2 * parentIndex + 1;
}

template<typename T>
int Heap<T>::getRightChildIndex(int parentIndex)
{
	return 2 * parentIndex + 2;
}

template<typename T>
int Heap<T>::getGreaterChildIndex(int parentIndex)
{
	int left = getLeftChildIndex(parentIndex);
	int right = getRightChildIndex(parentIndex);
	return max(left, right);
}

template<typename T>
int Heap<T>::max(int leftChildIndex, int rightChildIndex)
{
	if(leftChildIndex < _nodes.size() && rightChildIndex < _nodes.size())
	{
		if (_nodes[leftChildIndex] >= _nodes[rightChildIndex])
			return leftChildIndex;
		else
			return rightChildIndex;
	}

	return -1;
}


#endif