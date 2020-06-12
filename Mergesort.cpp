//벡터 버전	
void mergei(vector<int> *vec, int l, int r)
{
	int mid = ((l + r) / 2) + 1, right = r + 1;
	int left = l;
	int * arr = new int[r - l + 1];
	r = mid;
	int arrIndex = 0;
	while (l < mid && r < right)
	{
		if ((*vec).at(l) <= (*vec).at(r))
		{
			arr[arrIndex] = (*vec).at(l);
			l++;

		}
		else
		{
			arr[arrIndex] = (*vec).at(r);
			r++;
		}
		arrIndex++;
	}
	for (; l < mid; l++, arrIndex++)
		arr[arrIndex] = (*vec).at(l);
	for (; r < right; r++, arrIndex++)
		arr[arrIndex] = (*vec).at(r);
	for (arrIndex = 0; left < right; left++, arrIndex++)
		(*vec).at(left) = arr[arrIndex];
	delete[] arr;
}
void m_sort(vector<int> *vec, int left, int j)
{
	if (left < j)
	{
		m_sort(vec, left, (left + j) / 2);
		m_sort(vec, ((left + j) / 2) + 1, j);
		mergei(vec, left, j);
	}
}


long countInversions(vector<int> arr) {
	m_sort(&arr, 0, arr.size() - 1);
	return ans;
}

