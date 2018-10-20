#include <stdio.h>




int main(void)
{
	char s[4] = "Lol";
	int x = 0;
	
	while(s[x] != '\0'){
		if(s[x] >= 'a' && s[x] <= 'z'){
			s[x] -= 32; // 32 = 'a' - 'A'
		}
		
		x++;
	}
	
	printf("%s\n", s);
	

	return 666;
}