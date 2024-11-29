#pragma once

template <typename T>
struct TreeNode
{
	T data;
	TreeNode<T>* leftChild = nullptr;
	TreeNode<T>* rightChild = nullptr;
	int height = 1;
};