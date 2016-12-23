// Kth Max Subarray.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/DEC16/problems/KTHMAX

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <unordered_map>

using namespace std;

typedef struct node
{
	long long pos;
	long long val;
	node *left, *right;
	long long height;
	long long mul;
} node;

node* ROOT = NULL;

void findPreSuc(node* root, node*& pre, node*& suc, node*& curr, int pos)
{
	// Base case
	if (root == NULL)  return;

	// If pos is present at root
	if (root->pos == pos)
	{
		// the maximum value in left subtree is predecessor
		if (root->left != NULL)
		{
			node* tmp = root->left;
			while (tmp->right)
				tmp = tmp->right;
			pre = tmp;
		}

		// the minimum value in right subtree is successor
		if (root->right != NULL)
		{
			node* tmp = root->right;
			while (tmp->left)
				tmp = tmp->left;
			suc = tmp;
		}
		curr = root;
		return;
	}

	// If pos is smaller than root's pos, go to left subtree
	if (root->pos > pos)
	{
		suc = root;
		findPreSuc(root->left, pre, suc, curr, pos);
	}
	else // go to right subtree
	{
		pre = root;
		findPreSuc(root->right, pre, suc, curr, pos);
	}
}







// A utility function to get height of the tree
long height(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


struct node* newNode(long long pos,long long val)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->pos   = pos;
	newNode->val = val;
	newNode->left   = NULL;
	newNode->right  = NULL;
	newNode->height = 1;
	newNode->mul = 1;
	return(newNode);
}


struct node *rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;

	
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	
	return x;
}


struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	
	y->left = x;
	x->right = T2;

	
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	
	return y;
}


long long getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct node* insert(struct node* node, long long pos, long long val)
{
	
	if (node == NULL)
		return(newNode(pos,val));

	if (pos < node->pos)
		node->left = insert(node->left, pos, val);
	else if (pos > node->pos)
		node->right = insert(node->right, pos, val);
	else // Equal keys are not allowed in BST
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	long long balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && pos < node->left->pos)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && pos > node->right->pos)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && pos > node->left->pos)
	{
		node->left =  leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && pos < node->right->pos)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

void deleteTree(struct node* node)
{
	if (node == NULL) return;

	deleteTree(node->left);
	deleteTree(node->right);
	free(node);
}


void lvr(node *root, unordered_map<long long, long long>& mp)
{
	if (root == NULL) return;
	
	if (mp.find(root->val) == mp.end())
		mp[root->val] = 0;
	mp[root->val] = mp[root->val] + root->mul;
	lvr(root->left, mp);
	lvr(root->right, mp);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	/*long T, lp;
	long long ans;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
	cout << "Case #" << lp << ": " << ans << "\n";
	}*/

	int T;
	cin >> T;
	while (T--)
	{
		long long N, M, i, j;
		ROOT = NULL;
		cin >> N >> M;
		vector<pair<long long, long long>> arr(N);


		for (i = 0;i < N;i++)
		{
			cin >> arr[i].first;
			arr[i].second = i;
		}
		sort(arr.rbegin(), arr.rend());

		


		for (i = 0;i < N;i++)
		{
			ROOT = insert(ROOT, arr[i].second, arr[i].first);
			node *pre = NULL, *suc = NULL, *curr = NULL;
			findPreSuc(ROOT, pre, suc, curr, arr[i].second);
			if (pre != NULL)
				curr->mul = curr->mul*(curr->pos - pre->pos);
			else
				curr->mul = curr->mul*(curr->pos + 1);
			if (suc != NULL)
				curr->mul = curr->mul*(suc->pos - curr->pos);
			else
				curr->mul = curr->mul*(N - curr->pos);
		}


		unordered_map<long long, long long> mp;

		lvr(ROOT, mp);

		vector<pair<long long, long long>> arrrr;
		for (unordered_map<long long, long long>::const_iterator it = mp.begin();it != mp.end();it++)
		{
			arrrr.push_back(make_pair(it->first, it->second));
		}
		sort(arrrr.rbegin(), arrrr.rend());


		for (i = 1;i < arrrr.size();i++)
			arrrr[i].second += arrrr[i - 1].second;

		for (i = 0;i < arrrr.size();i++)
		{
			long long tmp = arrrr[i].first;
			arrrr[i].first = arrrr[i].second;
			arrrr[i].second = tmp;
		}


		while (M--)
		{
			pair<long long, long long> pp;
			cin >> pp.first;
			pp.second = 0;
			vector<pair<long long, long long>>::const_iterator it = lower_bound(arrrr.begin(), arrrr.end(), pp);
			cout << it->second << "\n";
		}
		deleteTree(ROOT);
		ROOT = NULL;
	}
	return 0;
}



