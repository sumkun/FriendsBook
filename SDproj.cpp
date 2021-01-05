#include<iostream>
#include<cstdio>
#include<sstream>
#include<string.h>
#include <conio.h>
#include<algorithm>
#include <fstream>
#include <cstdlib>
#include <cctype>

#define pow2(n) (1 << (n))
#define MAX 100
using namespace std;
//drmore@mitaoe.ac.in
/*
 * Node Declaration
 */
struct avl_node
{
	string data;
	string password;
	struct avl_node *left;
	struct avl_node *right;
}*root;

/*
 * Class Declaration
 */
class avlTree
{
public:


	int height(avl_node *);
	int diff(avl_node *);
	avl_node *rr_rotation(avl_node *);
	avl_node *ll_rotation(avl_node *);
	avl_node *lr_rotation(avl_node *);
	avl_node *rl_rotation(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insert(avl_node *, string, string);
	void display(avl_node *, int);
	void inorder(avl_node *);
	void preorder(avl_node *);
	void postorder(avl_node *);
	avlTree()
	{
		root = NULL;
	}
	
};
class node
{
public:
	string sender;
	string reciever;
	//string post;
	node *next;

};
class node1
{
public:
	string sender;
	string reciever;
	string post;
	node1 *nxt;

};
class linkedList :public avlTree
{
public:
	node *head, *temp, *q, *p,*r;
	node1 *start,*qr; 
	string requests[MAX];
	
	//linkedList l=new linkedList();
	linkedList()
	{
		head = NULL;
		start = NULL;
		temp = NULL;
		q = NULL;
		p = NULL;
		r = NULL;
		qr = NULL;
	}
	
	void create(string send, string recieve, string message)
	{
		node1 *temp1 = new node1();
		temp1->sender = send;
		temp1->reciever = recieve;
		temp1->post = message;
		//cout << "Messgae :" << temp1->post;
		temp1->nxt = NULL;
		if (start == NULL)
		{
			start = temp1;
		}
		else
		{
			qr=start;
			while (qr->nxt != NULL)
			{
				qr = qr->nxt;
			}
			qr->nxt = temp1;
		}
	}
	/////////////////////// Send Friend Request ?
	void create(string send, string receive)
	{

		temp = new node();
		temp->sender = send;
		//temp->post = '0';
		temp->reciever = receive;
		//temp->post = '0';
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			q = head;
			while (q->next != NULL)
			{
				q = q->next;
			}
			q->next = temp;
		}
	}
	//////////////////////////   ADD FRIEND    /////////////////////////////////////
	void create(string user, string addfriend, int flag)
	{

	}
	
	int checkMessage(string username)
	{
		node1 *w;
		if (start == NULL)
		{
			//cout << "No messages" << endl;
		}
		else
		{
			w = start;
			while (w != NULL)
			{
				if (w->reciever == username)
				{
					cout << "\t\t\t" << "|-----------------------------|" << endl;
					cout << "\t\t\t" << "|" << w->sender << "          |";
					cout<< w->post << "          |" << endl;
					cout << "\t\t\t" << "|-----------------------------|" << endl;
					cout << "\t\t\t" << endl;
					
					//return 1;
				}
				else
				{
					//cout << "Not found";
					//return 0;
				}
				w = w->nxt;
			}
			return 1;

		}
	}
	void deleteRequest(string deleteNode)
	{
		q = head;
		node *t = head;
		int count = 0;
		while (q->sender != deleteNode)
		{
			q = q->next;
			count++;
		}
		//cout << count<<endl;
		if (count == 0)
		{
			if (q->next == NULL)
			{
				free(q);
				head = NULL;
				cout << "Empty" << endl;
			}
			else
			{
				//cout << "Entry successfull to the linked list having only two nodes" << endl;
				node *temp = head;
				head = q->next;
				cout << head->sender<<endl;
				free(temp);
			}
		}
		else
		{
			while (t->next != q)
			{
				t = t->next;
			}
			t->next = q->next;
			q->next = NULL;
			free(q);
		}
		q = head;
		/*while (q != NULL)
		{
			cout << "Remaining : " << q->sender << endl;
			q = q->next;
		}*/
	}
	int checkRequest(string userName,linkedList a )
	{
		linkedList obj1,obj2;
		obj1 = a;
		//obj2 = h;
			int acceptUserRequest;
			int checker = 0, count = 0;
			int inc = 0;
			string ha[MAX];


			if (head == NULL)
			{
				checker = 0;
			}
			else
			{
				
				q = head;
				while (q != NULL)
				{

					if (q->reciever == userName)
					{
						cout << "\t\t\t" << "|-----------------------------|" << endl;
						cout << "\t\t\t" << "|" << inc << "]" << q->sender << "|" << endl;
						cout << "\t\t\t" << "|-----------------------------|" << endl;

						ha[inc] = q->sender;
						inc++;
						//count++;
						checker = 1;

					}
					

					q = q->next;
					//return 1;
				//	return 0

				}
				if (checker == 1)
				{
					cout << "\t\t\t" << "___________________________________________________________________" << endl;
					cout << "\t\t\t" << endl;
					cout << "\t\t\t" << "******** fRiEnDsBooK is facing some problem ********" << endl;
					cout << "\t\t\t" << "Never accept the first request it is a spam request and will corrupt your account" << endl;
					cout << "\t\t\t" << "You can accept any request except the first one" << endl;
					cout << "\t\t\t" << "Problem will be solved as early as possible " << endl;
					cout << "\t\t\t" << "Sorry for the inconvenience " << endl;
					cout << "\t\t\t" << "You will experiance a better FriendsBook with a better features" << endl;
					cout << "\t\t\t" << "___________________________________________________________________" << endl;
					cout << endl;
					cout << endl;
					cout << "Click a friend to accept his request : " << endl;
					cin >> acceptUserRequest;

					obj2.create(userName, ha[acceptUserRequest], 1);
					obj1.deleteRequest(ha[acceptUserRequest]);
				}
					 else
				{
					cout << "No Request bro" << endl;
					return 1;
				}
				
				
				

				return 0;
			}

		
					
		
	}
			
			
			
			
		
		
		
		
	

};

int main()
{
	ofstream outfile, friend_File;
	linkedList a,b,c;
	string msg=" ",text,line1;




	cout << "\t\t\t" << "____________________________________________________________________" << endl;
	cout << endl;
	cout << "\t\t\t" << "|" << "                                                " << "                   |" << endl;
	cout << "\t\t\t" << "|" << "                         fRiEnDsBooK                               " << "|" << endl;
	cout << "\t\t\t" << "____________________________________________________________________" << endl;
	cout << endl;
	//cout << "\t\t\t" << "----------------------------------------------------------------------" << endl;
	//cout<<"-"<<"                                             \t                            "<<"-"<<endl;

	int  ch, i = 0, ch1, req;
	string item, username, password, confirmPassword, user, pass,k[MAX];
	string friends[20];
	avlTree avl;
	outfile.open("registration.txt"); // Open a file 
	friend_File.open("friend.txt");
	outfile << "start" << endl;
	cout << endl;
	//cin.ignore();
	do
	{
		cout << "\t\t\t\t\t" << "*********************************" << endl;
		cout << "\t\t\t\t\t" << "Want to register :" << endl;
		cout << "\t\t\t\t\t" << "1] Sign up" << endl;
		cout << "\t\t\t\t\t" << "2] Login " << endl;
		cout << "\t\t\t\t\t" << "*********************************" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1://Signup
			cout << "\t\t\t\t\t" << "__________________________" << endl;
			cout << endl;
			cout << "\t\t\t\t\t" << "Username : " << "\t";
			cin >> username;
			cout << "\t\t\t\t\t" << endl;
			cout << "\t\t\t\t\t" << "Password :" << "\t";
			cin >> password;
			//cout << endl;
			cout << "\t\t\t\t\t" << "__________________________" << endl;
			cout << endl;

			cout << endl;
			//outfile << "User:" << i++ << endl;
			outfile << username << " " << password;
			outfile << endl;
			friend_File << username << endl;
			//	outfile.close();
				//outfile << password << endl;
				//outfile << username << endl;
			root = avl.insert(root, username, confirmPassword);
			if (root == NULL)
			{
				cout << "Tree is Empty" << endl;

			}
			//cout << "Balanced AVL Tree:" << endl;
			//avl.display(root, 1);
			break;
		case 2://Login
			cout << "\t\t\t\t\t" << "__________________________" << endl;
			cout << endl;
			cout << "\t\t\t\t\t" << "Username : " << "\t";
			cin >> user;
			cout << "\t\t\t\t\t" << endl;
			cout << "\t\t\t\t\t" << "Password :" << "\t";
			cin >> pass;
			//cout << endl;
			cout << "\t\t\t\t\t" << "__________________________" << endl;
			cout << endl;

			string userAndPass = user + " " + pass; // Search pattern
			ifstream usersFile;
			int offset, flag = 0;
			string line;
			usersFile.open("registration.txt");
			while (!usersFile.eof())
			{
				getline(usersFile, line);
				if ((offset = line.find(userAndPass, 0)) != string::npos) {	  // if login data is found
					//cout << "found " << userAndPass << endl;
					flag = 1;
				}

				else	// if login data is not found
				{
					

				}
			}
			if (flag == 1)
			{
				ifstream friendFile;
				int i = 0, count = 0,cont,flag=0;
				
				friendFile.open("friend.txt");
				//cout << userAndPass << "" << "found";
				do
				{
					cout << "1)Find friend" << endl;
					cout << "2)Send Messages" << endl;
					cout << "3)See friend request" << endl;
					cout << "4)View messages" << endl;
					cout << "5) Logout" << endl;
					cin >> ch1;
					switch (ch1)
					{
					case 1://find friend



						while (!friendFile.eof())
						{
							getline(friendFile, friends[i]);
							i++;
							count++;
						}
						for (i = 0; i < count - 1; i++)
						{
							cout << "\t\t\t" << i << "]" << friends[i] << endl;
						}
						cout << "Select to send friend request:";
						cin >> req;
						cout << "\t\t\t" << "Friend Request sent to :" << friends[req]<<endl;
						//friendFile.close();
						a.create(user, friends[req]);

						break;
					case 2://send message 
						
						while (!friendFile.eof())
						{
							getline(friendFile, friends[i]);
							i++;
							count++;
						}
						for (i = 0; i < count - 1; i++)
						{
							cout << "\t\t\t" << i << "]" << friends[i] << endl;
						}
						cout << "Select a friend you want to chat with :";
						cin >> req;
						cout << endl;
						cout << "---------Message----------------" << endl;
						//cout << "" << "Please type a message: ";
						//getline(cin,msg);
						//cin.ignore();

						
						cin >> msg;
						//cout << friends[req];
						b.create(user, friends[req], msg);
						break;
					case 3://see friend Request
						//cout << user;
						flag=a.checkRequest(user,a);
						break;
					case 4://see messages
						flag = b.checkMessage(user);
						if (flag == 1)
						{
							cout << "No Messages" << endl;
						}
						break;
					case 5://logout
						cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;
						cout << "\t\t\t\t\t" << "Thank you for joining friendsbook" << endl;
						cout << "\t\t\t\t\t" << "We are working for your better experiance" << endl;
						cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;
						break;
					}
					cout << "-------------------------------------------------------------" << endl;
					cout << "Continue with the session press 1  and for logout press 0:"<<endl;
					cout << "-------------------------------------------------------------" << endl;
					cin >> cont;
					
				} while (cont == 1);
				
			}
			else
			{
				cout << "\t\t\t" << "___________________________________________________________" << endl;
				cout << "\t\t\t" << "Username and/or password incorrect!\n\n\n\n"<< endl;
				cout << "\t\t\t" << "___________________________________________________________" << endl;
			}
			
			break;
		}
		cout << " Do you want to continue :" << endl;
		cin >> ch;
		//cin.ignore();
	} while (ch == 1);


	
	return 0;
}

/*
 * Height of AVL Tree
 */
int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		//cout << "Left height  :" << l_height<<endl;
		int r_height = height(temp->right);
		//cout << "Right height  :" << r_height << endl;
		int max_height = max(l_height, r_height);
		//cout << "Max height : " << max_height;
		h = max_height + 1;
	}
	return h;
}

/*
 * Height Difference
 */
int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	//cout << "Balance factor- " << b_factor << endl;
	return b_factor;
}

/*
 * Right- Right Rotation
 */
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
 * Left- Left Rotation
 */
avl_node *avlTree::ll_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*
 * Left - Right Rotation
 */
avl_node *avlTree::lr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
 * Right- Left Rotation
 */
avl_node *avlTree::rl_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
 * Balancing AVL Tree
 */
avl_node *avlTree::balance(avl_node *temp)
{
	int bal_factor = diff(temp);

	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

/*
 * Insert Element into the tree
 */
avl_node *avlTree::insert(avl_node *root, string value, string password)
{
	if (root == NULL)
	{
		root = new avl_node;
		root->data = value;
		root->password = password;
		root->left = NULL;

		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value, password);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value, password);
		root = balance(root);
	}
	return root;
}

/*
 * Display AVL Tree
 */
void avlTree::display(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

/*
 * Inorder Traversal of AVL Tree
 */
void avlTree::inorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}
/*
 * Preorder Traversal of AVL Tree
 */
void avlTree::preorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "  ";
	preorder(tree->left);
	preorder(tree->right);

}

/*
 * Postorder Traversal of AVL Tree
 */
void avlTree::postorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << "  ";
}

//OUTPUT OF THE PROJECT
/*
____________________________________________________________________

|                                                                   |
|                         fRiEnDsBooK |
____________________________________________________________________


* ********************************
Want to register :
1] Sign up
2] Login
*********************************
1
__________________________

Username : sar

	Password : sar
	__________________________


	Do you want to continue :
	1
	* ********************************
	Want to register :
	1] Sign up
	2] Login
	*********************************
	1
	__________________________

	Username : tan

	Password : tan
	__________________________


	Do you want to continue :
	1
	* ********************************
	Want to register :
	1] Sign up
	2] Login
	*********************************
	2
	__________________________

	Username : tan

	Password : tan
	__________________________

	1)Find friend
	2)Send Messages
	3)See friend request
	4)View messages
	5) Logout
	1
	0]sar
	1]tan
	Select to send friend request:0
	Friend Request sent to : sar
	------------------------------------------------------------ -
	Continue with the session press 1 and for logout press 0 :
	------------------------------------------------------------ -
	1
	1)Find friend
	2)Send Messages
	3)See friend request
	4)View messages
	5) Logout
	2
	0]sar
	1]tan
	Select a friend you want to chat with : 0

	-------- - Message----------------
	hello
	------------------------------------------------------------ -
	Continue with the session press 1 and for logout press 0 :
	------------------------------------------------------------ -
	0
	Do you want to continue :
	1
	* ********************************
	Want to register :
	1] Sign up
	2] Login
	*********************************
	2
	__________________________

	Username : sar

	Password : sar
	__________________________

	1)Find friend
	2)Send Messages
	3)See friend request
	4)View messages
	5) Logout
	3
	| ---------------------------- - |
	|0]tan|
	|---------------------------- - |
	___________________________________________________________________

	* ******* fRiEnDsBooK is facing some problem ********
	Never accept the first request it is a spam request and will corrupt your account
	You can accept any request except the first one
	Problem will be solved as early as possible
	Sorry for the inconvenience
	You will experiance a better FriendsBook with a better features
	___________________________________________________________________


	Click a friend to accept his request :
0
Empty
------------------------------------------------------------ -
Continue with the session press 1 and for logout press 0 :
	------------------------------------------------------------ -
	1
	1)Find friend
	2)Send Messages
	3)See friend request
	4)View messages
	5) Logout
	4
	| ---------------------------- - |
	|tan | hello          |
	|---------------------------- - |

	No Messages
	------------------------------------------------------------ -
	Continue with the session press 1 and for logout press 0:
------------------------------------------------------------ -
0
Do you want to continue :
*/
