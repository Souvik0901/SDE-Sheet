
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n)
	{
	    // code here
	    long long ma= arr[0];
	    long long mi = arr[0];
	    long long res = arr[0];
	    
	    
	    for(int i=1; i<n; i++)
	    {
	        if(arr[i]<0)
	         swap(ma, mi);
	        
	        ma = max((long long)arr[i], ma*arr[i]);
	        mi = min((long long)arr[i], mi*arr[i]);
	        
	        res = max(ma, res);
	    }
	    return res;
	}
};

