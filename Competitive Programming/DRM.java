/**
 DRM Encryption is a new kind of encryption. Given an encrypted string (which we’ll call a DRM message), 
the decryption process involves three steps: Divide, Rotate and Merge. 
This process is described in the following example with 
the DRM message “EWPGAJRB”:

Divide
– First, divide the message in half to “EWPG” and “AJRB”.
Rotate
– For each half, calculate its rotation value by summing up the values of each character (A=0,B=1,…,Z=25). 
The rotation value of “EWPG” is 4+22+15+6=47. Rotate each character in “EWPG” 47 positions forward (wrapping from Z to A when necessary) to obtain the new string 
“ZRKB”. Following the same process on “AJRB” results in “BKSC”.
Merge
– The last step is to combine these new strings (“ZRKB” and “BKSC”) by rotating each character in the first string by the 
value of the corresponding character in the second string. For the first position, rotating ‘Z’ by ‘B’ means moving it forward 1 character, 
which wraps it around to ‘A’. Continuing this process for every character results in the final decrypted message, “ABCD”.
 */

import java.util.Hashtable;
public class DRM {
	
	public static String DRMDecrptor(String message) {
		
		if(message.length()%2 != 0) {
			System.out.println("Message cannot be decrypted");
			return message;
		}
		
		Hashtable<Character,Integer> letterValues = new Hashtable<>();
		for(int i=0;i<26;i++) {
			char c = (char) ('A' + i);
			letterValues.put(c, i);
		}
		
		int mid = (message.length()-1)/2;
		int leftSum = 0;
		for(int i=0;i<=mid;i++) {
			char c = message.charAt(i);
			leftSum+=letterValues.get(c); 
		}
		
		String leftHalf = "";
		for(int i=0;i<=mid;i++) {
			int c = message.charAt(i);
			int rotation = (((c-65)+leftSum)%26) + 65;
			leftHalf+= Character.toString((char)rotation);
		}
		
		int rightSum = 0;
		for(int i=mid+1;i<message.length();i++) {
			char c = message.charAt(i);
			rightSum+=letterValues.get(c); 
		}
		
		String rightHalf = "";
		for(int i=mid+1;i<message.length();i++) {
			int c = message.charAt(i);
			int rotation = ((c-65)+rightSum)%26 + 65;
			rightHalf+= Character.toString((char)rotation);
		}
		
		String decryptedMessage = "";
		for(int i=0;i<leftHalf.length();i++) {
			int c1 = leftHalf.charAt(i);
			int c2 = rightHalf.charAt(i);
			
			int rotation = ((c1-65)+(c2-65))%26 +65;
			decryptedMessage+= Character.toString((char)rotation);
		}
		
		return decryptedMessage;
	}
	public static void main(String [] args) {
		String DRMMessage = "UEQBJPJCBUDGBNKCAHXCVERXUCVK";
		System.out.println(DRMDecrptor(DRMMessage));
	}
}
