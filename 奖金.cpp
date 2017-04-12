/*�����޵еķ�����2005������Ӣ��˧�����ܾ�ѡ��ʤ����Yali Company�ܾ���Mr.Z����ã�������ÿλԱ�������𡣹�˾������ÿ���˱�
���ڹ�˾�Ĺ���Ϊ��׼���������ǵõ�����Ķ��١�
����Mr.Z�����ٿ�m����̸��ÿλ�μӻ�̸�Ĵ���������Լ��������������ΪԱ��a�Ľ���Ӧ�ñ�b�ߣ���Mr.Z����Ҫ�ҳ�һ�ֽ��𷽰���
�����λ������������ͬʱʹ���ܽ��������١�ÿλԱ����������Ϊ100Ԫ��

�����ݷ�Χ��
��������n<=10000��m<=20000��


�����ʽ
    ��һ����������n,m����ʾԱ�������ʹ�������
    ����m�У�ÿ��2������a,b����ʾĳ��������Ϊ��a��Ա������Ӧ�ñȵ�b��Ա���ߡ� 

�����ʽ
    ���޷��ҵ��Ϸ��������������Poor Xed�����������һ������ʾ�����ܽ���

��������
2 1
1 2
�������
201*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int outdegree[10010];
vector<int> father[10010];
int bonus[10010];

int max(int a, int b) {
    return a > b? a: b;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
	    bonus[i] = 100;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        outdegree[a]++;
        father[b].push_back(a);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(outdegree[i] == 0 && !father[i].empty())
            q.push(i);
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        for(vector<int>::iterator it = father[k].begin(); it != father[k].end(); ++it)
        {
            outdegree[*it]--;
            bonus[*it] = max(bonus[*it], bonus[k] + 1);
            if(outdegree[*it] == 0)
                q.push(*it);
        }
    }
    
    bool flag = true;
    for(int i = 1; i <= n; i++)
        if(outdegree[i] != 0) {
            flag = false;
            cout << "Poor Xed\n";
            break;
        }
    if(flag) {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += bonus[i];
        cout << sum << "\n";
    }
    
    return 0;
}          
