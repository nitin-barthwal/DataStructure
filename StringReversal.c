// C Program to reverse a string without 
// using temp variable 
#include <stdio.h>
 

// Function to reverse string and return revesed string 
void reversingString(char* str, int start, int end) 
{ 
	// Iterate loop upto start not equal to end 
	while (start < end) 
	{ 
		// XOR for swapping the variable 
		str[start] ^= str[end]; 
		str[end] ^= str[start]; 
		str[start] ^= str[end]; 
		++start; 
		--end; 
	
	}
} 

// Driver Code 
int main() 
{ 
	char s[] = "HelloWorld"; 
	printf("%s reversed to ",s); 
	reversingString(s, 0, 9);
	printf("%s",s); 
	return 0; 
} 
