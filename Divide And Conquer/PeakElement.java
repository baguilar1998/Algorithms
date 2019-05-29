/**
 * An element A[i] is a peak element if it is not smaller than its neighbor(s)
 * 
 * A[i-1] <= A[i] <= A[i+1] for 0 <= i <= N-1
 * A[i-1] <= A[i] if i = N-1
 * A[i] <= A[i+1] if i =0
 * 
 * There might be multiple peak elements in an array, but we just need to
 * find any peak element
 * 
 * The solution below is in a similar format to the maximum sub-array problem
 * where you want to find the biggest peak elements in the left-sub array, the 
 * right-sub array and anything in between those sub arrays.
 * 
 * This has a running time of O(nlgn), but it can be improved to O(lgn) manipulating
 * the binary serach algorithm
 *
 */
public class PeakElement {

	public static int peakElement(int [] arr, int start, int end) {
		if(start == end) {
			return arr[start];
		}
		
		int mid = (start+end)/2;
		
		int leftPeakElement = peakElement(arr,start,mid);
		int rightPeakElement = peakElement(arr,mid+1,end);
		int middlePeakElement = middlePeakElement(arr,start,mid,end);
		
		if(leftPeakElement > rightPeakElement && leftPeakElement > middlePeakElement)
			return leftPeakElement;
		if(rightPeakElement > leftPeakElement && rightPeakElement > middlePeakElement)
			return rightPeakElement;
		return middlePeakElement;
	}
	
	public static int middlePeakElement(int [] arr,int start,int mid,int end) {
		int leftPeak = arr[mid];
		for(int i = mid; i > start; i--) {
			boolean left =false, right = false;
			if(i-1<0) {
				left = true;
			} else if(arr[i-1] < arr[i]){
				left = true;
			}
			
			if(i+1 > start) {
				right = true;
			} else if(arr[i+1] < arr[i]) {
				right = true;
			}
			
			if((left && right) && leftPeak<arr[i]) leftPeak = arr[i];
		}
		
		int rightPeak = arr[mid];
		for(int i = mid+1; i < end; i++) {
			boolean left =false, right = false;
			if(i-1<0) {
				left = true;
			} else if(arr[i-1] < arr[i]){
				left = true;
			}
			
			if(i+1 > end) {
				right = true;
			} else if(arr[i+1] < arr[i]) {
				right = true;
			}
			
			if((left && right) && leftPeak<arr[i]) rightPeak = arr[i];
		}
		
		if(leftPeak>rightPeak)return leftPeak;
		return rightPeak;
	}
	
	public static void main(String [] args) {
		int array1 [] = {8,9,10,2,5,6};
		System.out.println(peakElement(array1,0,array1.length-1));
		int array2 [] = {8,9,10,12,15};
		System.out.println(peakElement(array2,0,array2.length-1));
		int array3 [] = {10,8,6,5,3,2};
		System.out.println(peakElement(array3,0,array3.length-1));
	}
}
