// sort.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "ԭ˳��" << endl;
	for (int v1 = 0; v1 < Len; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;

	//BubbleSort(a,Len);        //ð��
	//insertSort1(a, Len);      //��������
	//SelectSort(a, Len);       //ѡ������
	//ShellSort(a,Len);   //ϣ������
	//Shellsort2(a, Len);    
	//HeapSort(a, Len);         //������
	vector<int> nums{ 8,6,10,90,60,33,22,77,12,85 };
	//MergeSort(nums, 0, 10);     //�鲢���� �ݹ�ʵ��
	//MergeSort1(nums, 0, 10);    //�鲢������ʵ��
	/*
	for (auto x : nums)
	cout << x << " ";
	cout << endl;
	*/

	QuickSort(a, 0, Len - 1);      //����
	cout << "ѡ������" << endl;
	for (int v1 = 0; v1 < Len; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;


	return 0;
}


/*ð������*/
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

/*��������*/
void insertSort1(int a[], int length)
{

	for (int j = 1; j < length; j++)
	{
		int key = a[j];    //��Ҫ��������ĵ�һ��Ԫ��
		int i = j - 1;      //�Ѿ��Ź���Ԫ�����һ��������
		while (i >= 0 && key < a[i])
		{
			a[i + 1] = a[i];
			i--;           //Ϊkey�ҵ����ʵ�λ�ã���key���ֵȫ�����к���
		}
		a[i + 1] = key;    //�������key���뵽a[i+1]��λ��
	}

	cout << "��������" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

/*ѡ������*/
void SelectSort(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[index] > a[j])      //�����õ����������е���Сֵ
			{
				index = j;            //������������Сֵ������
			}
		}
		if (index != i)      //���������е���Сֵ�����������еĵ�һλ�Ļ������н���
		{
			int temp = a[index];
			a[index] = a[i];
			a[i] = temp;
		}
	}
	cout << "ѡ������" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

/*ϣ������*/
void ShellSort(int a[], int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)     //����
	{
		for (int i = 0; i < gap; i++)     //�����������
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

	cout << "ѡ������" << endl;
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

	cout << "ѡ������" << endl;
	for (int v1 = 0; v1 < length; v1++)
	{
		cout << a[v1] << " ";
	}
	cout << endl;
}

/*������  ����  */
void HeapSort(int a[], int length)
{
	if (a == NULL || length <= 0)
	{
		return;
	}
	for (int i = length / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(a, length, i);          //�ӵڶ��㿪ʼ����
	}

	for (int i = length - 1; i >= 0; --i)
	{
		std::swap(a[0], a[i]);
		HeapAdjust(a, i, 0);        //�Ӷ��㿪ʼ���ѣ��������һ��
	}

	cout << "ѡ������" << endl;
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
		if (temp < a[i])      //���ý���
		{
			break;
		}
		a[k] = a[i];    //����ֵ
		k = i;                  //��������
		i = 2 * k + 1;
	}
	a[k] = temp;
}


/*�ú����������±귶Χ[l1,r1]��[l2,r2]���������кϲ���һ����������*/

void merge(vector<int>& nums, int l1, int r1, int l2, int r2)
{

	int i = l1;                                               //��벿����ʼλ��
	int j = l2;                                               //�Ұ벿����ʼλ��
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //Ҫ�ϲ���Ԫ�ظ���
	vector<int> temp(n);                                      //��������
	int k = 0;	                                          //������������ʼλ��
	while (i <= r1&&j <= r2) {                                //��ѡ����������С��Ԫ�ط��븨��������
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];

	}
	//�������ʣ�ֱ࣬�ӷ��뵽����������
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//����ԭʼ����Ԫ��
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}

}

/*��·�鲢���򣨵ݹ�ʵ�֣�*/
void MergeSort(vector<int>& nums, int start, int end)
{
	if (start < end) {
		int mid = (start + end) >> 1;				//�ָ�����
		MergeSort(nums, start, mid);				//��������벿�ֽ��й沢����
		MergeSort(nums, mid + 1, end);				//�������Ұ벿�ֽ��й沢����
		merge(nums, start, mid, mid + 1, end);                  //�ϲ��Ѿ��������������
	}

}

/*��·�鲢���򣨵���ʵ�֣�*/
void MergeSort1(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end) {
		//stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ���
		for (int step = 2; step / 2 <n; step *= 2) {
			//ÿstep��Ԫ��һ�飬����ǰstep/2�ͺ�step/2��Ԫ�ؽ��кϲ�
			for (int i = 0; i < n; i += step) {
				int mid = i + step / 2 - 1;					//��������Ԫ�ظ���Ϊstep/2
				if (mid + 1<n)							//�����������Ԫ�ظ�����ϲ�
														//��������Ϊ[i,mid]����������Ϊ[mid+1, min(i+step-1, n-1)
					merge(nums, i, mid, mid + 1, min(i + step - 1, n - 1));
			}
		}
	}
}


/*����*/
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


