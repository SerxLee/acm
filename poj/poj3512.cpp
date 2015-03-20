#include <iostream>
using namespace std;

int num = 0;
int num_of_odd = 0;
//Trie
struct Node{
	int id;//表示一个串，为了给并查集提供服务
	int cnt;//系统存储了多少个本串
	Node* next[26];
	Node(){
		id = -1;
		cnt = 0;
		int i = 0;
		for(i = 0; i < 26; i++){
			next[i] = NULL;
		}
	}
};

Node* root = new Node();

int insert(char* str){
	Node* p = root;
	int i = 0;
	for(i = 0; i < strlen(str); i++){
		if(p->next[str[i] - 'a'] == NULL){
			Node *q = new Node();
			p->next[str[i] - 'a'] = q;
		}
		p = p->next[str[i] - 'a'];
	}

	p->cnt++;
	if(p->cnt & 1){
		num_of_odd++;
	} else {
		num_of_odd--;
	}

	if(-1 == p->id){
		p->id = ++num;
	}
	return p->id;
}

//并查集	
int rank[500002] = {0};
int parent[500002] = {0};
int find_set(int x) {
    if (0 == parent[x]) {
       return -1;
    }

    if (parent[x] != x) {
        parent[x] = find_set(parent[x]);
    }

    return parent[x];
}

void make_set(int x) {
    if (find_set(x) == -1) {
        parent[x] = x;
        rank[x] == 0;
    }
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;

    if (rank[x] == rank[y]) {
        parent[x] = y;
        rank[y]++;
    } else if (rank[x] < rank[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
    }
}



int main(){

//	freopen("2513.txt", "r", stdin);

	char str1[11];
	char str2[11];
	while(scanf("%s", str1) != EOF){
		scanf("%s", str2);
		int a = insert(str1);
		int b = insert(str2);
		make_set(a);
		make_set(b);
		union_set(a, b);
	}
	
	if(num_of_odd != 0 && num_of_odd != 2){
		cout << "Impossible" << endl;
		return 0;
	}
	int i = 0;
	int temp = find_set(1);
	for(i = 2; i <= num; i++){
		if(find_set(i) != temp){
			break;
		}
	}
	if(i <= num){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	return 0;
}