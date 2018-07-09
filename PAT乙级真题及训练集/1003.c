/*1003 我要通过！(20)（20 分）

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；\

    任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；\
    如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (&lt10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：

YES
YES
YES
YES
NO
NO
NO
NO
*/
/*思路：
 * 例如AAPATAA
 * 如果能找到P与T的下标，外加一个strlen(),就能知道P前的A的个数，P与T之间的A的个数，P后边的A的个数
 *												a						b					c
 * 1.PT之间至少要有一个A，所以!(b<1)
 * 2.a*b=c
 *
 * 另外P T 个数分别为1
 * */
#include <stdio.h>
#include <string.h>

int yesornot(char str[]);

int main()
{
	int n;
	char str[101];
	//printf("Input the number:\n");
	scanf("%d",&n);
	while(n--){
		if(yesornot(str)){
			printf("YES\n");
		}
		else
			printf("NO\n"); }

	return 0;
}

int yesornot(char str[]){
	scanf("%s",str);
	int posP,posT;
	int countP = 0,countT = 0;

	for (int i = 0; i < strlen(str); i++){
		if(str[i] == 'P'){
			posP = i;
			countP++;
		}
		else if(str[i] == 'T'){
			posT = i;
			countT++;
		}
		else if(str[i] == 'A'){
		}
		else 
			return 0;
	}
	int a,b,c;
	a = posP;
	b = posT - posP - 1;
	c = strlen(str) - posT - 1;

	if(
			a * b != c 
			||countP != 1
			||countT != 1
			||b<1
			){
		return 0;
	}
	else
		return 1;

}
