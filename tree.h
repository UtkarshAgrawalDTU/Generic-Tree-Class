#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode			//TreeNode class
{
	public:
		int data;
		vector< TreeNode* > children;	//vector of pointers to TreeNode
		
	TreeNode(int data) : data(data)		//initialisation list
	{}
	
};


class tree
{
	private:
		
	TreeNode* root;
	
	void displayTreeLevel(TreeNode* root)		//private function which displays tree level wise
	{
		if(root == NULL)
			return;
	
		queue <TreeNode*> q;
		q.push(root);
	
		while(!q.empty())
		{
			int count = q.size();
			for(int i=0; i<count; i++)
			{
			
				TreeNode* curr= q.front();
				q.pop();
				cout<<curr->data<<" ";
	
				for(int i=0; i<curr->children.size(); i++)
				q.push(curr->children[i]);	
			}
			
		}	
	}
		
	
	void displayTreePre(TreeNode * root)		//PreOrder traversal
	{
		if(root == NULL)
			return;
	
		cout<<root->data<<" ";
	
		for(int i=0; i<root->children.size(); i++)
			displayTreePre(root->children[i]);
		
	}
	
	
	void displayTreePost(TreeNode* root)		//PostOrder traversal
	{
		if(root == NULL)
			return;
	
		for(int i=0; i< root->children.size(); i++)
			displayTreePre(root->children[i]);
	
		cout<<root->data<<" ";	
	}

	
	
	public:
		tree(): root(NULL)
		{}
		
		
	void createTreeLevel()			// Creates tree in Level- Wise Input
	{
			
		int data;
		cin>>data;
		root = new TreeNode(data);
		root->data = data;
	
		queue< TreeNode * > q;
	
		q.push(root);
	
		while(!q.empty())
		{
			int childcount;
			TreeNode * curr = q.front();
			cin>>childcount;
		
			for(int i=0; i<childcount; i++)
			{
				cin>>data;
				TreeNode * child = new TreeNode(data);
				curr->children.push_back(child);
				q.push(child);
			}
		
			q.pop();
		}
	
	}
	
	void displayTreeLevel()
	{
		displayTreeLevel(root);
		cout<<endl;
	}
	
	void displayTreePre()
	{
		displayTreePre(root);
		cout<<endl;
	}

	void displayTreePost()
	{
		displayTreePost(root);
		cout<<endl;
	}
		
};

