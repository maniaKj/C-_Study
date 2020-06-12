int partition(vector<int> & vec, int l, int r)
{
	int pivot = vec[l], low = l, high = r + 1;	//피봇은 제일 왼쪽 값으로 지정

	do {
		do
		{
			low++;
		}
		while (low <= r && vec[low] < pivot);

		do
		{
			high--;
		}
		while (high >= l && vec[high] > pivot);
		if (low < high) {
			swap(vec[low], vec[high]);
		}
	} while (low < high);

	swap(vec[l], vec[high]);
	return high;
}
void quick_sort(vector<int> & vec, int l, int r)
{
	if (l < r)
	{
		int q = partition(vec, l, r); //분할 위치 지정 + 값 정렬
		quick_sort(vec, l, q - 1); 	//재귀적으로 퀵 정렬(왼쪽)
		quick_sort(vec, q + 1, r);	//재귀적으로 퀵 정렬(오른쪽)
	}
}
