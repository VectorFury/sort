// sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
void BubbleSort(int a[], int length);
void insertSort1(int a[], int length);
void SelectSort(int a[], int length);
void ShellSort(int a[], int length);
void Shellsort2(int a[], int length);
void HeapSort(int a[], int length);
void HeapAdjust(int a[], int length, int k);
void merge(vector<int>& nums, int l1, int r1, int l2, int r2);
void MergeSort(vector<int>& nums, int start, int end);
void MergeSort1(vector<int>& nums, int start, int end);
int FindMiddle(int*p1, int iLeft, int iRight);
void QuickSort(int *p1, int ileft, int iRight);

int main()
{

	int a[] = { 8,6,10,90,60,33,22,77,12,85 };
	int Len = sizeof(a) / sizeof(a[0]);
	cout << "原顺序：" << endl;
	for (int v1 = 0; v1 < Len; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;

	//BubbleSort(a,Len);        //冒泡
	//insertSort1(a, Len);      //插入排序
	//SelectSort(a, Len);       //选择排序
	//ShellSort(a,Len);   //希尔排序
	//Shellsort2(a, Len);    
	//HeapSort(a, Len);         //堆排序
	vector<int> nums{ 8,6,10,90,60,33,22,77,12,85 };
	//MergeSort(nums, 0, 10);     //归并排序 递归实现
	//MergeSort1(nums, 0, 10);    //归并，迭代实现
	/*
	for (auto x : nums)
	cout << x << " ";
	cout << endl;
	*/

	QuickSort(a, 0, Len - 1);      //快排
	cout << "选择排序：" << endl;
	for (int v1 = 0; v1 < Len; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;


	return 0;
}


/*冒泡排序*/
void BubbleSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;

}

/*插入排序*/
void insertSort1(int a[], int length)
{

	for (int j = 1; j < length; j++)
	{
		int key = a[j];    //需要进行排序的第一个元素
		int i = j - 1;      //已经排过的元素最后一个的索引
		while (i >= 0 && key < a[i])
		{
			a[i + 1] = a[i];
			i--;           //为key找到合适的位置，比key大的值全部进行后移
		}
		a[i + 1] = key;    //将排序的key插入到a[i+1]的位置
	}

	cout << "插入排序：" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

/*选择排序*/
void SelectSort(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[index] > a[j])      //遍历得到无序序列中的最小值
			{
				index = j;            //无序序列中最小值的索引
			}
		}
		if (index != i)      //无序序列中的最小值不在无序序列的第一位的话，进行交换
		{
			int temp = a[index];
			a[index] = a[i];
			a[i] = temp;
		}
	}
	cout << "选择排序：" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

/*希尔排序*/
void ShellSort(int a[], int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)     //步长
	{
		for (int i = 0; i < gap; i++)     //按组进行排序
		{
			for (int j = i + gap; j < length; j += gap) {
				if (a[j] < a[j - gap])
				{
					int temp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k] > temp)
					{
						a[k + gap] = a[k];
						k -= gap;

					}
					a[k + gap] = temp;
				}
			}
		}
	}

	cout << "选择排序：" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

void Shellsort2(int a[], int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < length; i++)
		{
			for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
			{
				swap(a[j], a[j + gap]);
			}
		}
	}

	cout << "选择排序：" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

/*堆排序  最大堆  */
void HeapSort(int a[], int length)
{
	if (a == NULL || length <= 0)
	{
		return;
	}
	for (int i = length / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(a, length, i);          //从第二层开始建堆
	}

	for (int i = length - 1; i >= 0; --i)
	{
		std::swap(a[0], a[i]);
		HeapAdjust(a, i, 0);        //从顶点开始建堆，忽略最后一个
	}

	cout << "选择排序：" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
	return;

}

void HeapAdjust(int a[], int length, int k)
{
	int temp = a[k];
	int i = 2 * k + 1;
	while (i < length) {
		if (i + 1 < length&&a[i] > a[i + 1])
		{
			++i;
		}
		if (temp < a[i])      //不用交换
		{
			break;
		}
		a[k] = a[i];    //交换值
		k = i;                  //继续查找
		i = 2 * k + 1;
	}
	a[k] = temp;
}


/*该函数将数组下标范围[l1,r1]和[l2,r2]的有序序列合并成一个有序序列*/

void merge(vector<int>& nums, int l1, int r1, int l2, int r2)
{

	int i = l1;                                               //左半部分起始位置
	int j = l2;                                               //右半部分起始位置
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //要合并的元素个数
	vector<int> temp(n);                                      //辅助数组
	int k = 0;	                                          //辅助数组其起始位置
	while (i <= r1&&j <= r2) {                                //挑选两部分中最小的元素放入辅助数组中
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];

	}
	//如果还有剩余，直接放入到辅助数组中
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//更新原始数组元素
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}

}

/*二路归并排序（递归实现）*/
void MergeSort(vector<int>& nums, int start, int end)
{
	if (start < end) {
		int mid = (start + end) >> 1;				//分割序列
		MergeSort(nums, start, mid);				//对序列左半部分进行规并排序
		MergeSort(nums, mid + 1, end);				//对序列右半部分进行规并排序
		merge(nums, start, mid, mid + 1, end);                  //合并已经有序的两个序列
	}

}

/*二路归并排序（迭代实现）*/
void MergeSort1(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end) {
		//step为组内元素个数，step/2为左子区间元素个数
		for (int step = 2; step / 2 <n; step *= 2) {
			//每step个元素一组，组内前step/2和后step/2个元素进行合并
			for (int i = 0; i < n; i += step) {
				int mid = i + step / 2 - 1;					//左子区间元素个数为step/2
				if (mid + 1<n)							//右子区间存在元素个数则合并
														//左子区间为[i,mid]，右子区间为[mid+1, min(i+step-1, n-1)
					merge(nums, i, mid, mid + 1, min(i + step - 1, n - 1));
			}
		}
	}
}


/*快排*/
void QuickSort(int *p1, int iLeft, int iRight)
{
	if (iLeft < iRight)
	{
		int iMiddle = FindMiddle(p1, iRight, iLeft);
		QuickSort(p1, iLeft, iMiddle - 1);
		QuickSort(p1, iMiddle + 1, iRight);
	}


}

int  FindMiddle(int*p1, int iRight, int iLeft)
{
	int iTemp = p1[iLeft];
	while (iLeft<iRight)
	{
		while (iLeft<iRight&&p1[iRight] >= iTemp)
		{
			iRight--;
		}
		p1[iLeft] = p1[iRight];
		while (iLeft<iRight&&p1[iLeft] <= iTemp)
		{
			iLeft++;

		}
		p1[iRight] = p1[iLeft];
	}
	p1[iLeft] = iTemp;
	return iLeft;
}


