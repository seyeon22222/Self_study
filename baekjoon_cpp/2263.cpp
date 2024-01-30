#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> post_order;
vector<int> in_order;
int rootNum;

int main()
{
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		in_order.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		post_order.push_back(a);
	}
	//root 정점
	rootNum = post_order[n - 1];
	//root 기준 왼쪽 노드의 개수
	int left_node_num = find(in_order.begin(), in_order.end(), rootNum) - in_order.begin();
	//root 기준 오른쪽 노드의 개수
	int right_node_num = n - left_node_num - 1;
}