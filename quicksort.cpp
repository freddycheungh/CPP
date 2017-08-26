#include <iostream>

template <typename T>
int partitionArray(T* Array, int p, int q) {

	int l = p; // Left Group
	int r = q; // Right Group

	T pivot = Array[(p + q) / 2];

	do {
		while (Array[l] > pivot) {
			l++;
		}
		while (Array[r] < pivot) {
			r--;
		}
		if (l <= r) {
			std::swap(Array[l++], Array[r--]);
		}
	} while (l <= r);

	return l;

}

template <typename T>
void quickSort(T* Array, const int p, const int q) {

	int i = partitionArray(Array, p, q);

	if (p < q) {

		if (p < i - 1) { 
			quickSort(Array, p, i - 1);
		}
		if (i < q) { 
			quickSort(Array, i, q);
		}

	}

}

int main() {

	int arr[] = { 11, 5, 201, 8, 100, 88, 7, 81, 55, 110, 10, 3 ,22, 59, 1, 100 };
	//double arr[] = { 11.99, 5.99, 1.22, 4.56, 88.52, 7.6, 11.99, 110.6, 10.7, 11.99, 3.2 ,22.7, 100.2, 12.99 };

	int start = 0, end = sizeof(arr) / sizeof(arr[0]);
	//std::cout << "maaaax: " << end << std::endl;
	std::cout << "Original Array: " << std::endl;
	for (int i = 0; i < end; i++) {
		std::cout << arr[i] << ",";
	}

	std::cout << std::endl << std::endl;

	quickSort(arr, start, end - 1);

	std::cout << "Ordered Array: " << std::endl;

	for (int i = 0; i < end; i++) {
		std::cout << arr[i] << ",";
	}

	std::cout << std::endl << std::endl;

	return 0;

}
