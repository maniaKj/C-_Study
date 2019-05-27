#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define QUICK_SORT(vector) quick_sort((vector), (0), (vector.size() - 1))

int partition(vector<int> & _vec, int _left, int _right)
{
	int pivot = _vec[_left], tmp, low = _left, high = _right + 1;

	do {
		do
			low++;
		while (low <= _right && _vec[low] < pivot);

		do
			high--;
		while (high >= _left && _vec[high] > pivot);
		if (low < high) SWAP(_vec[low], _vec[high], tmp);
	} while (low < high);

	SWAP(_vec[_left], _vec[high], tmp);
	return high;
}
void quick_sort(vector<int> & _vec, int _left, int _right)
{
	if (_left < _right)
	{
		int q = partition(_vec, _left, _right);
		quick_sort(_vec, _left, q - 1);
		quick_sort(_vec, q + 1, _right);
	}
}

//*******************************************************************//

vector<int> quickSortvec(vector<int> vec, int left, int right) {
    int i = left, j = right;
    int pivot = vec.at((i+j)/2);
    int temp;
    do{
        while(vec.at(i) <pivot) i++;
        while(vec.at(j) > pivot) j--;
        if(i <= j){
            temp = vec.at(i);
            vec.at(i) = vec.at(j);
            vec.at(j) = temp;
            i++;
            j--;
        }
    }while(i <= j);
    
    if(left < j)vec = quickSortvec(vec, left, j);
    if(right > i) vec = quickSortvec(vec, i, right);
    return vec;
}

//another ver
void quickSortvec(vector<vector<int>> *vec, int left, int right) {
    int i = left, j = right;
    int pivot = vec->at((i+j)/2)[2];
    vector<int> temp;
    do{
        while(vec->at(i)[2] <pivot) i++;
        while(vec->at(j)[2] > pivot) j--;
        if(i <= j){
            temp = vec->at(i);
            vec->at(i) = vec->at(j);
            vec->at(j) = temp;
            i++;
            j--;
        }
    }while(i <= j);
    
    if(left < j) quickSortvec(vec, left, j);
    if(right > i) quickSortvec(vec, i, right);
}
