
Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.



Code:


#include<bits/stdc++.h>
using namespace std;

int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high)
  {
		int mid = (low + high) / 2;
    
		// maybe an answer
  		if (arr[mid] <= x) 
      {
  			ans = arr[mid];
  			//look for smaller index on the left
  			low = mid + 1;
  		}
  		else 
      {
  			high = mid - 1; // look on the right
  		}
	}
	return ans;
}

int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) 
  {
		int mid = (low + high) / 2;
		// maybe an answer
  		if (arr[mid] >= x) 
      {
  			ans = arr[mid];
  			//look for smaller index on the left
  			high = mid - 1;
  		}
  		else 
      {
  			low = mid + 1; // look on the right
  		}
	}
	return ans;
}


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	int f = findFloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}

int main() {
	int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}
