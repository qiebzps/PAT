/*1004 成绩排名 (20)（20 分）

读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为\

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩

其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：

Mike CS991301
Joe Math990112
*/

#include <stdio.h>

int main()
{
	/* structure data type */
	struct student{
		/* 姓名、学号、成绩 */
		char name[9];
		char id[9];
		int score;
	};

	/* declare three variables */
	int n;
	struct student studentTable[101];

	printf("Input the number:\n");
	scanf("%d",&n);

	/* get the student array  */
	int i;
	for (i = 0;i<n;i++){
		scanf("%s",studentTable[i].name);
		scanf("%s",studentTable[i].id);
		scanf("%d",&studentTable[i].score);
	}
	/* max */
	int max = 0;
	for (i = 0;i<n;i++){
		if(studentTable[max].score<studentTable[i].score){
			max = i;
		}
	}
	/* min */
	int min = 0;
	for (i = 0;i<n;i++){
		if(studentTable[min].score>studentTable[i].score){
			min = i;
		}
	}

	/* max */
	printf("%s %s\n",studentTable[max].name,studentTable[max].id);
	//printf("%s\n",studentTable[max].id);
	/* min */
	printf("%s %s\n",studentTable[min].name,studentTable[min].id);
	//printf("%s",studentTable[min].id);

	return 0;
}
