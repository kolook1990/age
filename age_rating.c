#include <stdio.h>
#include <string.h>
int age_qa(char *s,char *s2,char *s3) // определение возраста по вопросу
{
	char s22[50];
	printf(s); // выводит вопрос
	s2[1]=0;
	s22[0]=0;
	while ((s22[0]!='y') & (s22[0]!='n'))
	{
		scanf("%s",s22); // ожидает ответ
		s22[1]=0;
	}
	if (strcmp(s2,s22)==0) return atoi(s3);// если ответ совпадает с ожидаемым, возвращаем возраст
	return 0;
}

int age_rating() // определение возрастной категории
{
	FILE *f;
	int age=0;
	char s[5000];
	char s2[50];
	char s3[50];
	f=fopen("QA","r");
	while (1)
	{
		fgets(s,sizeof(s),f); // чтение строк из файла ВОПРОС
		fgets(s2,sizeof(s2),f);// ОЖИДАЕМЫЙ ОТВЕТ ДЛЯ ОПРЕДЕЛЕНИЯ
		fgets(s3,sizeof(s3),f);// ВОЗРАСТНОЕ ОГРПНТЧЕНИЕ
		if (feof(f)!=0) break; // если файл закончен то выход
		age=age_qa(s,s2,s3); // определение возрастной категории по ответу
		if (age>0) break; // если возраст определили то выход
	}
	fclose(f);
	return age;
}

int main(void)
{
	printf("%d%s",age_rating(),"+\n");// вывод возрастной категории 
	return 0;
}
