int BSearch(int data[],const int x,int left,int right)
{
	if(left>right) return 0;
	unsigned long long int middle = (unsigned long long int)(left+right)/2;
	if(x==data[middle]) return 1;
	if(x<data[middle]) b_search(data,x,left,middle-1);
	else b_search(data,x,middle+1,right);
}


void QSort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;
    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right) {
      while ((numbers[right] >= pivot) && (left < right)) right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
      while ((numbers[left] <= pivot) && (left < right))
        left++;
      if (left != right) {
        numbers[right] = numbers[left];
        right--;
      }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) q_sort(numbers, left, pivot-1);
    if (right > pivot)q_sort(numbers, pivot+1, right);
}

//sort choose
void SortChoose(int mass[],size_t len)
{
	int index_min;
	for(int i = 0;i<len-1;i++)
	{
		index_min = i;
		for(int j = i+1;j<len;j++) if(mass[index_min]>mass[j]) index_min = j;
		if(index_min!=i) SWAP(mass[i],mass[index_min]);
	}
	return;
}


void SortBubble(int mass[],size_t len)
{
	for(int i = 0;i<len;i++)
	for(int k = 1;k<len;k++)
	if(mass[k-1]>mass[k]) SWAP(mass[k-1],mass[k]);
}

int FactorialRQ(int x)
{
	if(x <= 1|!x) return x;
	return x * factorialRQ(x-1);
}

int Factorial(int x)
{
	for(int i = x-1;i!=1;i--) x*=i;
	return x;
}
