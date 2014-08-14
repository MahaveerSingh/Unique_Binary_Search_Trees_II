#include <iostream>
#include<vector>

using std::vector;


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution
{
public:

	vector<TreeNode *> *generate(int start, int end)
	{
		vector<TreeNode *> *subTree = new vector<TreeNode *>();

		if(start > end)
		{
			subTree->push_back(NULL);
			return subTree;
		}

		for(int i=start; i<=end; i++)
		{
			vector<TreeNode *> *leftSubs = generate(start, i-1);
			vector<TreeNode *> *rightSubs = generate(i+1, end);

			for(int j=0; j<leftSubs->size(); j++)
			{
				for(int k=0; k<rightSubs->size(); k++)
				{
					TreeNode *node = new TreeNode(i);
					node->left = (*leftSubs)[j];
					node->right = (*rightSubs)[k];
					subTree->push_back(node);
				}
			}
		}

		return subTree;
	}




	vector<TreeNode *> generateTrees(int n)
	{
		if(n == 0)
			return *generate(1, 0);
		else
			return *generate(1, n);
	}
};


int main(int argc, const char * argv[])
{
    

    
    // insert code here...
	Solution s;
	s.generateTrees(3);
	system("pause");
    return 0;
}