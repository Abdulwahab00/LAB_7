#include<iostream>
#define COUNT 10  
using namespace std;
int n = 1;
struct node
{
	int data;
	node* LeftNode;
	node* RightNode;
	
};
class Tree 
{
public:
	node* root;
	
	Tree()
	{
		root = NULL;
	}
	void insert_node(int);
	void display(node* r);
	void Search(int);
	node* deleteNode(node* r, int v);
	int maxDepth(node* node);
	int LevelofNode(node* temp, int data, int level);
	int DegreeofNode(node* temp ,int val);
	int CountNodes(node* root);
	bool isLeaf(node* n, int val);
	bool isNonLeaf(node* n, int val);
	int LeafCount(node* root, int c);
	int nonleaf(node* root);
	bool isParent(node* n, int val);
};
bool Tree:: isParent(node* root,int val)
{
	

	bool flag = false;
	if (root == NULL)
	{
		cout << "There is no Data in your Tree Data Structure" << endl;
		return false;
	}
	node* temp = root;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			if (temp->RightNode != NULL || temp->LeftNode != NULL)
				return true;
			else
				return false;

			
		}
		else if (val > temp->data)
		{
			temp = temp->RightNode;
		}
		else
		{
			temp = temp->LeftNode;
		}
	}
	if (flag == false)
	{
		cout << "No such Data exist in your Tree" << endl;
	}
}

void Tree::display(node* r)
{
	if (r == NULL)
	{
		return;
	}
	display(r->LeftNode);
	cout << r->data << "  ";
	display(r->RightNode);
}
int Tree::nonleaf( node* root)
{
	if (root == NULL || (root->LeftNode == NULL && root->RightNode == NULL)) {
		return 0;
	}
	return 1 + nonleaf(root->LeftNode) + nonleaf(root->RightNode);
}
int Tree::LeafCount(node* root, int count) 
{
	if (root == NULL)
		return 0;

	if (root->LeftNode == NULL && root->RightNode == NULL) {
		return 1 + count;
	}
	else {
		int lc = LeafCount(root->LeftNode, count);
		int total = LeafCount(root->RightNode, lc);
		return total;
	}
}
bool Tree::isLeaf(node* root, int val)
{
	
	if (root == NULL)
	{
		cout << "There is no Data in your Tree Data Structure" << endl;
		return false;
	}
	node* temp = root;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			
			if (temp->LeftNode == NULL && temp->RightNode == NULL)

				return true;
			else
				return false;
			
		}
		else if (val > temp->data)
		{
			temp = temp->RightNode;
		}
		else
		{
			temp = temp->LeftNode;
		}
	}
	
}
bool Tree::isNonLeaf(node* root, int val)
{

	if (root == NULL)
	{
		cout << "There is no Data in your Tree Data Structure" << endl;
		return false;
	}
	node* temp = root;
	while (temp != NULL)
	{
		if (temp->data == val)
		{

			if (temp->LeftNode == NULL && temp->RightNode == NULL)

				return true;
			else
				return false;

		}
		else if (val > temp->data)
		{
			temp = temp->RightNode;
		}
		else
		{
			temp = temp->LeftNode;
		}
	}

}

int Tree::CountNodes(node* root)
{
	if (root == NULL)
		return 0;
	if (root->LeftNode != NULL)
	{
		n = n + 1;
		n = CountNodes(root->LeftNode);
	}
	if (root->RightNode != NULL)
	{
		n = n + 1;
		n = CountNodes(root->RightNode);
	}
	return n;
}
int Tree:: DegreeofNode(node* temp,int val)
{

	if (root == NULL) {
		return  -1;
	}
	else {
		
		while (temp != NULL) {
			if (val == temp->data) {
				if (temp->RightNode != NULL && temp->RightNode != NULL)
					return 2;
				else if (temp->RightNode != NULL || temp->LeftNode != NULL)
					return 1;
				else
					return 0;
				break;
			}
			else if (val < temp->data) {
				temp = temp->LeftNode;
			}
			else {
				temp = temp->RightNode;
			}
		}

	}
}

int Tree:: LevelofNode(node* temp, int dt, int level)
{

	if (temp == NULL)
	{
		return 0;
	}
	if (temp->data == dt)
	{
		return level;
	}
	int lvl = LevelofNode(temp->LeftNode, dt, level + 1);
		if (lvl != 0)
		{
			return lvl;
		}
		lvl = LevelofNode(temp->RightNode, dt, level + 1);
		return lvl;
}

int Tree:: maxDepth(node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->LeftNode);
		int rDepth = maxDepth(node->RightNode);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}
void Tree::insert_node(int val)
{
	node* new_node = new node;
	new_node->data = val;
	new_node->LeftNode = NULL;
	new_node->RightNode = NULL;
	node* temp = root;
	if (root == NULL)
	{
		root = new_node;
	}
	while (temp!=NULL)
	{
		
		 if (root->data == new_node->data)
		{
				
			break;
		}

		else if (new_node->data < temp->data && temp->LeftNode == NULL)
		{
			temp->LeftNode = new_node;
			break;
		}
		else if (new_node->data < temp->data )
		{
			temp = temp->LeftNode;
		}
		else if (new_node->data > temp->data && temp->RightNode == NULL)
		{
			temp->RightNode = new_node;
			break;
		}
		else
		{
			temp = temp->RightNode;
		}

	}
	
}

void Tree::Search(int val)
{
	bool flag=false;
	if (root == NULL)
	{
		cout << "There is no Data in your Tree Data Structure" << endl;
		return;
	}
	node* temp = root;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			cout << "Data Found" << endl;
			flag = true;
			return;
		}
		else if (val>temp->data )
		{
			temp = temp->RightNode;
		}
		else
		{
			temp = temp->LeftNode;
		}
	}
	if (flag == false)
	{
		cout << "No such Data exist in your Tree" << endl;
	}
}

node*Tree:: deleteNode(node* r, int v)
{
	
	if (r == NULL) {
		return NULL;
	}
	
	else if (v < r->data) {
		r->LeftNode = deleteNode(r->LeftNode, v);
	}
	
	else if (v > r->data) {
		r->RightNode = deleteNode(r->RightNode, v);
	}
	else {
		
		if (r->LeftNode == NULL) {
			node* temp = r->RightNode;
			delete r;
			return temp;
		}
		else if (r->RightNode == NULL) {
			node* temp = r->LeftNode;
			delete r;
			return temp;
		}
		else {
			node* current = r->RightNode;

			while (current->LeftNode != NULL) {
				current = current->LeftNode;
			}
			

			node* temp = current;
			r->data = temp->data;
			r->RightNode = deleteNode(r->RightNode, temp->data);
			
		}
	}
	return r;
}

int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()	---> Press 1" << endl
			<< "Delete()	---> Press 2" << endl
			<< "Search()	---> Press 3" << endl
			<< "LeafCount()	---> Press 4" << endl
			<< "Display()	---> Press 5" << endl
			<< "TotalNodes()	---> Press 6" << endl
			<< "isLeaf()	---> Press 7" << endl
			<< "isNonLeaf()	---> Press 8" << endl
			<< "Depth/Height()  ---> Press 9" << endl
			<<"LevelofNode() ---> press 10"<<endl
			<< "DegreeofNode() ---> press 11" << endl
			<<"InternalNodeCount()---> press 12"<<endl
			<<"IsParent() --->press 13"<<endl
			<< "Exit()		---> Press 0" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			while (val != 0000)
			{

				cout << "Enter the Element You want to insert/ Enter 0000 To exit: " << endl;
				cin >> val;
				if (val != 0000)
				{


					obj.insert_node(val);
				}
			}

			break;
		}
		case 2:
		{
			int x;
			cout << "Enter the Value You want to Delete" << endl;
			cin >> x;
			obj.deleteNode(obj.root, x);
			cout << "          DELETED!" << endl;
			break;
		}
		case 3:
		{
			int a;
			cout << "Enter the value You want to Search" << endl;
			cin >> a;
			obj.Search(a);
			break;
		}
		case 4:
		{
			cout << "Number of Leaf Node is: " << obj.LeafCount(obj.root,0) << endl;
			break;
		}
		case 5:
		{
			cout << "*****Data in your tree*****" << endl;
			
			obj.display(obj.root);
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "Total Number of Nodes: " << obj.CountNodes(obj.root);
			
			cout << endl;
			break;
		}
		case 7:
		{
			int a;
			cout << "Enter th data to check the node is leaf or not" << endl;
			cin >> a;
			if (obj.isLeaf(obj.root, a))
			{
				cout << "This Node is Leaf Node" <<endl;
			}
			else
			{
				cout << "This Node is Not Leaf Node" << endl;
			}
			cout << endl;
			break;
		}
		case 8:
		{
			int a;
			cout << "Enter th data to check the node is leaf or not" << endl;
			cin >> a;
			if (obj.isNonLeaf(obj.root, a))
			{
				cout << "This Node is Leaf Node" << endl;
			}
			else
			{
				cout << "This Node is Not Leaf Node" << endl;
			}
			cout << endl;
			break;
		}
		case 9:
		{
			cout<<"Depth of the tree is: "<<obj.maxDepth(obj.root);
			cout << endl;
		}
		case 10:
		{
			int x;
			cout << "Enter the Data of node to check its level" << endl;
			cin >> x;
			cout << "Level of Node is: " << obj.LevelofNode(obj.root, x, 0) << endl;
			break;
		}
		case 11:
		{
			int x;
			cout << "Enter the data of node to check its degree" << endl;
			cin >> x;
			cout << "Degree of Node is: " << obj.DegreeofNode(obj.root, x) << endl;
			break;
		}
		case 12:
		{
			cout << "Total Internal Nodes are: " << obj.nonleaf(obj.root)<<endl;
			break;
		}
		case 13:
		{
			int x;
			cout << "Enter the node value" << endl;
			cin >> x;
			obj.isParent(obj.root, x);
			break;
		}
		default:
		{
			cout << "Select the Correct Option" << endl;
		}


		}
	} while (opt != 0);
}