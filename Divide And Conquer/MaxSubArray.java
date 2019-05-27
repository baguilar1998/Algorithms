
public class MaxSubArray {

	public static int [] findMaximumSubArray(int [] arr, int low, int high) {
		if (low == high) {
			int [] baseCase = {low,high,arr[low]};
			return baseCase;
		}
		int mid = (low+high)/2;
		
		int [] left = findMaximumSubArray(arr,low,mid);
		int [] right = findMaximumSubArray(arr,mid+1,high);
		int [] cross = findMaximumCrossSubArray(arr,low,mid,high);
		
		if(left[2] >= right[2] && left[2] >= cross[2]) return left;
		if(right[2] >= left[2] && right[2] >= cross[2]) return right;
		return cross;
	}
	
	public static int [] findMaximumCrossSubArray(int [] arr, int low, int mid, int high) {
		int [] cross = new int[3];
		int leftSum = 0;
		int leftIndex = 0;
		int sum=0;
		
		for(int i=mid; i>=low; i--) {
			sum+=arr[i];
			if(sum > leftSum) {
				leftSum = sum;
				leftIndex = i;
			}
		}
		
		
		int rightSum = 0;
		int rightIndex = 0;
		sum = 0;
		for(int i = mid+1; i<=high; i++) {
			sum+=arr[i];
			if(sum > rightSum) {
				rightSum = sum;
				rightIndex = i;
			}
		}
		
		cross[0] = leftIndex;
		cross[1] = rightIndex;
		cross[2] = leftSum+rightSum;
		return cross;
	}
	
	public static void main(String [] args) {
		int array [] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
		int [] answer = findMaximumSubArray(array,0,array.length-1);
		
		System.out.print("The maximum sub array is ");
		for(int i = answer[0]; i<=answer[1]; i++) System.out.print(array[i] + " ");
		
	}
}
