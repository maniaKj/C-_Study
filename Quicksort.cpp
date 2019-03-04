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
