 int kthElement(int arr1[], int arr2[], int n, int m, int k)
 {
      vector<int>v;
      int i=0,j=0;
      while(i<n  and j<m)  
      {    
        if(arr1[i]==arr2[j]){
           v.push_back(arr1[i]);
           v.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            v.push_back(arr2[j]);
            j++;
        }
        else{
            v.push_back(arr1[i]);
            i++;
        }
      }

          while(i<n){
              v.push_back(arr1[i]);
              i++;
          }
          while(j<m){
              v.push_back(arr2[j]);
              j++;
          }


      int ans=v[k-1];
      return ans;
}
