						//HEADER FILES

#include<stdio.h>
#include<stdlib.h>


						//TYPEDEF FOR DATA NODE

typedef struct Item_Tag
{
	float hours;
	char employee_name[20];
	char employee_address[50];
	char designation[20];
	char phone_number[11];
}item_type;


						//TYPEDEEF FOR MAIN NODE

struct node
{
	int employee_number;
	struct node *left;
	struct node *right;
	int height;
	item_type *item;
};


						//HEIGHT FUNCTION

int height(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


						//MAX FUNCTION

int max(int a, int b)
{
	return (a > b) ? a : b;
}


						//NEW NODE FUNCTION

struct node* newNode(int employee_number)
{
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->item = (item_type*)malloc(sizeof(item_type));
	printf("Enter Employee name:\n");
	scanf("%s", node->item->employee_name);
	printf("Enter Address :\n");
	scanf("%s", node->item->employee_address);
	printf("Enter Designation:\n");
	scanf("%s", node->item->designation);
	printf("Enter phone_number :\n");
	scanf("%s", node->item->phone_number);
	printf("Enter Working hours:\n");
	scanf("%f", &(node->item->hours));
	node->employee_number = employee_number;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;  //new node is initially added at leaf
	return(node);
}


						//ROTATE RIGHT FUNCTION

struct node *rightRotate(struct node *x)
{
	struct node* y = x->left;
	struct node* T = y->right;

	// Performing rotation
	y->right = x;
	x->left = T;

	// Updating heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}


						//ROTATE LEFT FUNCTION

struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T = y->left;

	// Performing rotation
	y->left = x;
	x->right = T;

	//  Updating heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}


						//GET BALANCE FACTOR FUNCTION

int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


						//INSERT FUNCTION

struct node* insert(struct node* node, int employee_number)
{
	if (node == NULL)										//INSERT
	{
		return(newNode(employee_number));
	}
	else if (employee_number == node->employee_number)		//UPDATE
	{
		printf("Enter Employee name:\n");
		scanf("%s", node->item->employee_name);
		printf("Enter Employee Address:\n");
		scanf("%s", node->item->employee_address);
		printf("Enter Designation:\n");
		scanf("%s", node->item->designation);
		printf("Enter Phone number no.:\n");
		scanf("%s", node->item->phone_number);
		printf("Enter Working hours:\n");
		scanf("%f", &node->item->hours);
		printf("RECORD MODIFIED!!!\n");
	}
	else
	{
		if (employee_number < node->employee_number)
			node->left = insert(node->left, employee_number);	//CHECKING LEFT
		else
			node->right = insert(node->right, employee_number);	//CHECKING RIGHT

		//Update height of this ancestor node
		node->height = max(height(node->left), height(node->right)) + 1;

		//Checking avlness
		int balance = getBalance(node);



		//ROTATION
		// Left Left Case
		if (balance > 1 && getBalance(node->left) >= 0)
			return rightRotate(node);

		// Left Right Case
		if (balance > 1 && getBalance(node->left) < 0)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Right Case
		if (balance < -1 && getBalance(node->right) <= 0)
			return leftRotate(node);

		// Right Left Case
		if (balance < -1 && getBalance(node->right) > 0)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}


						//MIN VALUE FUNCTION

struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}


						//DELETE FUNCTION

struct node* deleteNode(struct node* root, int employee_number)
{

	if (root == NULL)
		return root;

	if (employee_number < root->employee_number)
	{
		root->left = deleteNode(root->left, employee_number);
	}		
	else if (employee_number > root->employee_number)
	{
		root->right = deleteNode(root->right, employee_number);
	}
	else			//NODE FOUND
	{
		// Node with atmost one child
		if ((root->left == NULL) || (root->right == NULL))
		{
			struct node *temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else									// One child case
				*root = *temp;						// Copy the contents of the non-empty child

			free(temp);
		}
		else
		{
			// Find smallest in right sub-tree
			struct node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			root->employee_number = temp->employee_number;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->employee_number);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
		return root;

	// UPDATE HEIGHT OF THE CURRENT NODE
	root->height = max(height(root->left), height(root->right)) + 1;



	int balance = getBalance(root);

	//ROTATION
	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


						//GET NUM RECORDS FUNCTION

int get_num_records(struct node *root)
{
	int ret_val = 0;
	if (root != NULL)
	{
		ret_val = 1 + get_num_records(root->left) + get_num_records(root->right);
	}
	return ret_val;
}


						//HEIGHT FUNCTION

int ht(struct node *root)
{
	int ret_val = 0;
	if (root)
	{
		if (root->left == NULL && root->right == NULL)
		{
			ret_val = 1;
		}
		else
		{
			int LH, RH, Max;
			LH = ht(root->left);
			RH = ht(root->right);
			Max = max(LH, RH);
			ret_val = 1 + Max;
		}
	}
	return ret_val;
}


						//SEARCH FUNCTION

void Search(struct node *root, int num)
{
	if (root != NULL)
	{
		if (num == root->employee_number)
		{
			printf("%d\t", root->employee_number);
			printf("%s\t", root->item->employee_address);
			printf("%s\t", root->item->employee_name);
			printf("%s\t", root->item->designation);
			printf("%s\t", root->item->phone_number);
			printf("%.2f\t", root->item->hours);
		}
		else if (num < root->employee_number)
		{
			Search(root->left, num);
		}
		else
		{
			Search(root->right, num);
		}
	}

}


						// PRINT FUNCTION

void printTree(struct node *root)
{
	if (root != NULL)
	{
		printTree(root->left);
		printf("%d\t", root->employee_number);
		printf("%s\t", root->item->employee_address);
		printf("%s\t", root->item->employee_name);
		printf("%s\t", root->item->designation);
		printf("%s\t", root->item->phone_number);
		printf("%0.2f\n", root->item->hours);
		printTree(root->right);
	}
}


						//RANGE SEARCH

void rangeSearch(struct node* root, int employee_number1, int employee_number2)
{
	if (root != NULL)
	{
		if (employee_number1 <= root->employee_number)
			rangeSearch(root->left, employee_number1, employee_number2);
		if (employee_number1 <= root->employee_number && root->employee_number <= employee_number2)
		{
			printf("%d\t", root->employee_number);
			printf("%s\t", root->item->employee_address);
			printf("%s\t", root->item->employee_name);
			printf("%s\t", root->item->designation);
			printf("%s\t", root->item->phone_number);
			printf("%0.2f\n", root->item->hours);
		}
		if (employee_number2 >= root->employee_number)
			rangeSearch(root->right, employee_number1, employee_number2);
	}
}


						//MAIN FUNCTION

int main()
{
	struct node *root = NULL;
	int choice = 8, e_num, rec, n1, n2;
	while (choice)
	{
		switch (choice)
		{
		case 1:
			printf("Enter employee_number:\n");
			scanf("%d", &e_num);
			root = insert(root, e_num);
			printTree(root);
			break;
		case 2:
			if (root == NULL)
			{
				printf("List is Empty Deletion Error!!!\n");
			}
			else
			{
				printf("Enter employee_number to be deleted:\n");
				scanf("%d", &e_num);
				root = deleteNode(root, e_num);
				printTree(root);
			}
			break;
		case 3:
			printf("Enter element to be searched:\n");
			scanf("%d", &e_num);
			Search(root, e_num);
			break;
		case 4:
			rec = get_num_records(root);
			printf("No. of active record(s) is/are:%d\n", rec);
			break;
		case 5:
			rec = ht(root);
			printf("Height of the tree is:%d\n", rec);
			break;
		case 6:
			printf("Enter lower bound:\n");
			scanf("%d", &n1);
			printf("Enter upper bound:\n");
			scanf("%d", &n2);
			rangeSearch(root, n1, n2);
			break;
		case 7:
			if (root == NULL)
			{
				printf("Tree is empty!\n");
			}
			else
			{
				printTree(root);
			}
			break;
		case 8:
			printf("Enter your Choice:\n");
			printf("0 for exit\n1 to insert\n2 to delete\n");
			printf("3 to search\n4 to get_num_records\n5 for height of tree\n");
			printf("6 for range search\n7 for printing\n8 for menu\n");
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
		scanf("%d", &choice);
	}
	printf("Thank You\n");
	return 0;
}