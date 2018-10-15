#include "head.h"
#include <time.h>
#include <string>
int timSoLuongPhanTu(int i)
{
	int SoLuongPhanTu;
	if (i == 0)
	{
		SoLuongPhanTu = 1000;
	}
	else if (i == 1)
	{
		SoLuongPhanTu = 5000;
	}
	else if (i == 2)
	{
		SoLuongPhanTu = 10000;
	}
	else if (i == 3)
	{
		SoLuongPhanTu = 50000;
	}
	else if (i == 4)
	{
		SoLuongPhanTu = 100000;
	}
	else if (i == 5)
	{
		SoLuongPhanTu = 250000;
	}
	return SoLuongPhanTu;
}

string timSize(int i)
{
	string size;
	if (i == 0)
	{
		size = "1000";
	}
	else if (i == 1)
	{
		size = "5000";
	}
	else if (i == 2)
	{
		size = "10000";
	}
	else if (i == 3)
	{
		size = "50000";
	}
	else if (i == 4)
	{
		size = "100000";
	}
	else if (i == 5)
	{
		size = "250000";
	}
	return size;
}

void taoMang(int*& array,int soLuongPhanTu)
{
	array = new int[soLuongPhanTu];
	srand(time(0));
	for (int i = 0; i < soLuongPhanTu; i++)
	{
		array[i] = rand();
	}
}

void taoTenFileInput(string &fileName,string state,string size,string duoiFile)
{
	fileName = state + "\\" + size + "\\"+ state + "_" + size + duoiFile;
}

void taoTenFileOutput(string &fileName, string state, string sortAlg,string size, string duoiFile)
{
	fileName = state + "\\" + size + "\\" + sortAlg + "\\" + sortAlg+ "_" + state + "_" + size + duoiFile;
}

void ghiXuongFile(string tenFile,int* array,int soLuongPhanTu)
{
	ofstream fileOut;
	fileOut.open(tenFile, ios::out);
	for (int i = 0; i < soLuongPhanTu; i++)
	{
		fileOut << array[i] << " ";
	}
	fileOut.close();
}

void docFile(string tenFile,int*& a,int soLuongPhanTu)
{
	ifstream fileIn;
	fileIn.open(tenFile, ios::in);
	for (int i = 0; i < soLuongPhanTu; i++)
	{
		fileIn >> a[i];
	}
}

//============================================================================
//CAC HAM SAP XEP

void hoanVi(int &a, int  &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void interchangeSort(int* arr, int soLuongPhanTu)
{
	for (int i = 0; i < soLuongPhanTu - 1; i++)
	{
		for (int j = i + 1; j < soLuongPhanTu; j++)
		{
			if (arr[i] > arr[j])
			{
				hoanVi(arr[i], arr[j]);
			}
		}

	}
}

void selectionSort(int* arr, int soLuongPhanTu)
{
	int min;
	for (int i = 0; i < soLuongPhanTu - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < soLuongPhanTu; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			hoanVi(arr[i], arr[min]);
		}
	}
}

void insertionSort(int* arr, int soLuongPhanTu)
{
	int x, j;
	for (int i = 1; i < soLuongPhanTu; i++)
	{
		x = arr[i];
		j = i - 1;
		while ((j >= 0) && (arr[j] > x))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}

}

void shakerSort(int* arr, int soLuongPhanTu)
{
	int left = 1, right = soLuongPhanTu - 1, i, k;
	do
	{
		for (i = right; i >= left; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				hoanVi(arr[i], arr[i - 1]);
			}
			k = i;
		}
		left = k + 1;
		for (i = left; i <= right; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				hoanVi(arr[i], arr[i - 1]);
			}
			k = i;
		}
		right = k - 1;
	} while (left <= right);
}

void shellSort(int* arr, int soLuongPhanTu)
{
	for (int gap = soLuongPhanTu / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < soLuongPhanTu; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}

}

bool isBigger(int a, int b)
{
	return a > b ? true : false;
}
bool isSmaller(int a, int b)
{
	return a < b ? true : false;
}

void quickSort(int* arr, int left, int right, bool(*kiemTra1)(int, int), bool(*kiemTra2)(int, int))
{
	if (left < right)
	{
		int key = arr[(right + left) / 2];
		int i = left;
		int j = right;
		while (i <= j)
		{
			while (kiemTra1(arr[i], key))
			{
				i++;
			}
			while (kiemTra2(arr[j], key))
			{
				j--;
			}
			if (i <= j)
			{
				hoanVi(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		if (left < j)
			quickSort(arr, left, j, kiemTra1, kiemTra2);
		if (right > i)
			quickSort(arr, i, right, kiemTra1, kiemTra2);
	}

}

//Merge sort
void merge(int *arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int i, j, k;
	int *L = new int[n1];   
	int *R = new int[n2];	
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}
void mergeSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
//heap sort
void heapify(int *arr, int soLuongPhanTu, int i)
{
	int m = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < soLuongPhanTu && arr[left] > arr[m])
	{
		m = left;
	}
	if (right < soLuongPhanTu && arr[right] > arr[m])
	{
		m = right;
	}
	if (m != i)
	{
		hoanVi(arr[i], arr[m]);
		heapify(arr, soLuongPhanTu, m);
	}
}

void heapSort(int *arr, int soLuongPhanTu)
{
	for (int i = soLuongPhanTu / 2 - 1; i >= 0; i--)
	{
		heapify(arr, soLuongPhanTu, i);
	}
	for (int i = soLuongPhanTu - 1; i >= 0; i--)
	{
		hoanVi(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

//Radix sort
int timPhanTuLonNhat(int *arr, int soLuongPhanTu)
{
	int max = arr[0];
	for (int i = 0; i < soLuongPhanTu; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}


void demSort(int *arr, int soLuongPhanTu, int m)
{
	int *output = new int[soLuongPhanTu];
	int i;
	int dem[10] = { 0 };

	for (i = 0; i < soLuongPhanTu; i++)
	{
		dem[(arr[i] / m) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		dem[i] += dem[i - 1];
	}
	for (i = soLuongPhanTu - 1; i >= 0; i--)
	{
		output[dem[(arr[i] / m) % 10] - 1] = arr[i];
		dem[(arr[i] / m) % 10]--;
	}

	for (i = 0; i < soLuongPhanTu; i++)
	{
		arr[i] = output[i];
	}
	delete[] output;
}
void radixSort(int *arr, int soLuongPhanTu)
{
	int max = timPhanTuLonNhat(arr, soLuongPhanTu);
	for (int m = 1; max / m > 0; m *= 10)
	{
		demSort(arr, soLuongPhanTu, m);
	}
}


//binary insertion sort

int timKiemNhiPhan(int* arr, int x, int left, int right)
{
	if (right <= left)
	{
		return (x > arr[left]) ? (left + 1) : left;
	}
	int mid = (left + right) / 2;
	if (arr[mid] == x)
	{
		return mid + 1;
	}
	else if (arr[mid] > x)
	{
		return timKiemNhiPhan(arr, x, left, mid - 1);
	}
	else
	{
		return timKiemNhiPhan(arr, x, mid + 1, right);
	}
}

void binaryInsertionSort(int* arr, int soLuongPhanTu)
{
	int x, j, y;
	for (int i = 1; i < soLuongPhanTu; i++)
	{
		x = arr[i];
		j = i - 1;
		y = timKiemNhiPhan(arr, x, 0, j);
		while (j >= y)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}
}

//============================================================================
void sapxep(int* arr,int soLuongPhanTu,int type,clock_t& start, clock_t& end)
{
	if (type == 0)
	{
		start = clock();
		selectionSort(arr, soLuongPhanTu);
		end = clock();
	}
	else if (type == 1)
	{
		start = clock();
		insertionSort(arr, soLuongPhanTu);
		end = clock();
	}

	else if (type == 2)
	{
		start = clock();
		shakerSort(arr, soLuongPhanTu);
		end = clock();
	}
	else if (type == 3)
	{
		start = clock();
		shellSort(arr, soLuongPhanTu);
		end = clock();
	}
	else if (type == 4)
	{
		start = clock();
		quickSort(arr, 0, soLuongPhanTu - 1, isSmaller, isBigger);
		end = clock();
	}
	else if (type == 5)
	{
		start = clock();
		mergeSort(arr, 0, soLuongPhanTu - 1);
		end = clock();
	}
	else if (type == 6)
	{
		start = clock();
		heapSort(arr, soLuongPhanTu);
		end = clock();
	}
	else if (type == 7)
	{
		start = clock();
		radixSort(arr, soLuongPhanTu);
		end = clock();
	}
	else if (type == 8)
	{
		start = clock();
		interchangeSort(arr, soLuongPhanTu);
		end = clock();
	}
	else if (type == 9)
	{
		start = clock();
		binaryInsertionSort(arr, soLuongPhanTu);
		end = clock();
	}

}

void copyMang(int*& mangPhu, int* arr, int soLuongPhanTu)
{
	for (int i = 0; i < soLuongPhanTu; i++)
	{
		mangPhu[i] = arr[i];
	}
}

string layTenSort(int type)
{
	string sortAlg;
	if (type == 0)
	{
		sortAlg = "SelectionSort";
	}
	else if (type == 1)
	{
		sortAlg = "InsertionSort";
	}
	else if (type == 2)
	{
		sortAlg = "ShakerSort";
	}
	else if (type == 3)
	{
		sortAlg = "ShellSort";
	}
	else if (type == 4)
	{
		sortAlg = "QuickSort";
	}
	else if (type == 5)
	{
		sortAlg = "MergeSort";
	}
	else if (type ==6)
	{
		sortAlg = "HeapSort";
	}
	else if (type == 7)
	{
		sortAlg = "RadixSort";
	}
	else if (type == 8)
	{
		sortAlg = "InterchangeSort";
	}
	else if (type == 9)
	{
		sortAlg = "BinaryInsertionSort";
	}
	return sortAlg;
}

void tienHanhSapXepVaGhiXuongFile(int* a, int soLuongPhanTu,ofstream& result,string state,string size)
{
	clock_t start;
	clock_t end;
	double time;
	string tenFile;
	string duoiFile = ".out";
	string sortAlg;
	int* mangPhu = new int[soLuongPhanTu];
	for (int type = 0; type < 10; type++)
	{
		copyMang(mangPhu, a, soLuongPhanTu);
		sapxep(mangPhu, soLuongPhanTu, type,start,end);
		sortAlg = layTenSort(type);
		taoTenFileOutput(tenFile, state, sortAlg, size, duoiFile);
		ghiXuongFile(tenFile, mangPhu, soLuongPhanTu);
		time = double(end - start) / CLOCKS_PER_SEC;
		result << "," << time;
		tenFile.clear();
	}
	result << endl;
	delete[] mangPhu;
}
void xuLy(string state, int i, ofstream& result)
{
	//tao mang
	int* array;
	int soLuongPhanTu = timSoLuongPhanTu(i);
	taoMang(array,soLuongPhanTu);
	if (state.compare("Sorted") == 0)
	{
		radixSort(array, soLuongPhanTu);
	}
	else if (state.compare("NearlySorted") == 0)
	{
		radixSort(array, soLuongPhanTu / 2);
	}
	else if (state.compare("Reversed") == 0)
	{
		quickSort(array, 0, soLuongPhanTu - 1, isBigger, isSmaller);
	}
	//ghi mang vua tao vao file .inp
	string duoiFile1 = ".inp";
	string tenFile;
	string size = timSize(i);
	result << state << "," << size;
	taoTenFileInput(tenFile, state, size,duoiFile1);
	ghiXuongFile(tenFile,array,soLuongPhanTu);
	
	//docFile va gan vao mang de tien hanh sap xep
	int *a = new int[soLuongPhanTu];
	docFile(tenFile, a,soLuongPhanTu);
	tienHanhSapXepVaGhiXuongFile(a, soLuongPhanTu,result,state,size);


	delete[] array;
	delete[] a;
}


void sapXep(string state, ofstream& result)
{
	/*
		i La so luong phan tu
		i=0 : n=1000
		i=1 : n=5000;
		i=2: n=10000;
		i=3: ........
	*/
	for (int i = 0; i < 6; i++)
	{
		xuLy(state,i, result);
	}
}