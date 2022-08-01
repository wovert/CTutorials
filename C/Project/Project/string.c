/**
 * ×Ö·û´®×·¼Ó
 */
void testString(){
	char str1[] = "abcdef";
	char str2[] = "123456";
	char dst[100];

	int i = 0;
	while (str1[i] != 0)
	{
		dst[i] = str1[i];
		i++;
	}

	int j = 0;
	while (str2[j] != 0)
	{
		dst[i + j] = str2[j];
		j++;
	}
	dst[i + j] = 0; //×Ö·û´®½áÊø·û

	printf("dst = %s\n", dst);
}