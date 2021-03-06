#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//定义菜单字符串数组
char *menu[] = {"a - add new record","d - delete record","q - quit",NULL,};

int getchoice(char *greet, char *choices[]);

int main()
{
	int choice = 0;

	if (!isatty(fileno(stdout)))		//fileno将文件流转换成文件描述符，isatty判断该描述符是否连接到一个终端
	{
		fprintf(stderr, "You are not a terminal!\n");
		exit (1);
	}

	do
	{
		choice = getchoice("Please select an action", menu);	//显示菜单信息，并等待用户输入菜单选项首字母
		printf("You have chosen: %c\n", choice);
	} while(choice != 'q');							//直到用户输入q想要退出，否则一直循环
	exit (0);
}

/* 显示菜单，及读取用户输入 */
int getchoice(char *greet, char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;

	do		//不断循环直到用户输入正确的选项
	{
		printf("Choice: %s\n", greet);
		option = choices;
		while (*option)					//通过一个while循环，将字符串数组中的所有内容显示出来
		{
			printf("%s\n", *option);
			option++;
		}

		do
		{
			selected = getchar();			//从终端读取用户输入
		} while (selected == '\n');

		option = choices;
		while (*option)
		{
			if (selected == *option[0])	//判断用户输入是否符合菜单中某个选项
			{
				chosen = 1;
				break;
			}
			option++;
		}
		if (!chosen)
		{
			printf("Incorrect choice, select again\n");
		}
	} while(!chosen);
	return selected;
}
