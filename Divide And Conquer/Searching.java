public class Searching {

	public static int binarySearch(int [] arr, int low, int high,int value) {
		if(low == high) {
			if (low >= arr.length || low<0) return -1;
			return low;
		}
		int mid = (low+high)/2;
		if(value <= arr[mid]) return binarySearch(arr,low,mid,value);
		return binarySearch(arr,mid+1,high,value);
	}
	
	public static void main(String [] args) {
		int array [] = {1,2,3,4,5,6,7};
		int index = binarySearch(array,0,array.length,4);
		System.out.println("Your value is located at index: " +index);
		
	}
}
