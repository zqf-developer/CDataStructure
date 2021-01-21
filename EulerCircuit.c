#include <stdio.h> //使用库函数printf和scanf

int EulerCircuit(int mat[10][10], int n); //函数声明

//空行，以下是主函数

int main() {

	int mat[10][10] = {
		{0,1,2,2},
		{1,0,1,1},
		{2,1,0,0},
		{2,1,0,0}
	};

	//调用函数得到通奇数个桥的顶点个数
	int num = EulerCircuit(mat, 4);

	//多于2个顶点通奇数个桥
	if (num > 2) {
		printf("有%d个地方通奇数个桥，不存在欧拉回路\n", num);
	}
	else if(num == 2 || num == 0)//有两个顶点通奇数个桥或没有顶点通奇数个桥
	{
		printf("存在欧拉回路\n");
	}

	//将0返还操作系统，表明程序正常结束
	return 0;

}

//定义其它函数，七桥问题对应的数据模型
int EulerCircuit(int mat[10][10], int n) //函数定义，二维数组作为形参
{
	int i, j, degree, count = 0;//count 累计通奇数个桥的顶点个数
	for (i = 0; i < n; i++) //依次累加每一行的元素
	{
		degree = 0;//degree存储通过顶点i的桥数，初始化为0
		for(j = 0; j < n; j++)//依次处理每一列的元素
		{
			degree = degree + mat[i][j];//将通过顶点i的桥数求和
		}
		if (degree % 2 != 0) //桥数为奇数
		{
			count++;//累计
		}
	}

	return count;//结束函数，并将count返回到调用处
}

