struct Listnode
{
	int val;
	struct Listnode *next;
}

Listnode *midnode(Listnode *head)
{
	if(NULL==head||head->next==NULL)
		return NULL;
	
	Listnode *fast=head;
	Listnode *slow=head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}