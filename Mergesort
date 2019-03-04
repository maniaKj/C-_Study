//벡터 버전	
void mergei(vector<int> *a, int i, int j)
{
	int ni = ((i + j) / 2) + 1, nj = j + 1;
	int s = i;
	int * arr = new int[j - i + 1];
	j = ni;
	int k = 0;
	while (i < ni && j < nj)
	{
		if ((*a).at(i) <= (*a).at(j))
		{
			arr[k] = (*a).at(i);
			i++;

		}
		else
		{
			arr[k] = (*a).at(j);
			j++;
		}
		k++;
	}
	for (; i < ni; i++, k++)
		arr[k] = (*a).at(i);
	for (; j < nj; j++, k++)
		arr[k] = (*a).at(j);
	for (k = 0; s < nj; s++, k++)
		(*a).at(s) = arr[k];
	delete[] arr;
}
void m_sort(vector<int> *a, int i, int j)
{
	if (i < j)
	{
		m_sort(a, i, (i + j) / 2);
		m_sort(a, ((i + j) / 2) + 1, j);
		mergei(a, i, j);
	}
}

long countInversions(vector<int> arr) {
	m_sort(&arr, 0, arr.size() - 1);
	return ans;
}

