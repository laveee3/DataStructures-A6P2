void SortedMergeRecur(Node*& Xhead, Node*& Yhead, Node*& Zhead)
{
	int countX = FindListLength(Xhead), 
		 countY = FindListLength(Yhead), 
		 countZ = FindListLength(Zhead);
	
	cout << "count of X, Y, Z are " << countX << ", " << countY << ", " 
			<< countZ << endl;

	ShowAll(cout, Xhead);
	ShowAll(cout, Yhead);
	ShowAll(cout, Zhead);

	Node* Zcur = Zhead;
	if (countZ > 0){
		while (Zcur->link != 0)
			Zcur = Zcur->link;
	}


	if (countX == 0 && countY == 0)
		return;
	
	if (countX == 0 && countY != 0)
	{
		Zcur->link = Yhead;
		Yhead = 0;
	}
	
	if (countX != 0 && countY == 0)
	{
		Zcur->link = Xhead;
		Xhead = 0;
	}

	if (countX != 0 && countY != 0)
	{	
		cout << "Right Here" << endl;

		if (Xhead->data < Yhead->data)
		{
			cout << "X is less" << endl;
			//InsertAsTail(Zhead, Xhead->data);
			Zcur->link = Xhead;
			Xhead = Xhead->link;		
			Zcur->link->link = 0;
			SortedMergeRecur(Xhead->link, Yhead, Zhead);
		}
		else
		{
			cout << "Y is less" << endl;
			//InsertAsTail(Zhead, Yhead->data);
			if (Zcur == 0)
				Zcur = Yhead;
			else
				Zcur->link = Yhead;
			cout << "1	Y is less" << endl;
			//Yhead = Yhead->link;
			ShowAll(cout, Yhead);
			cout << "2	Y is less" << endl;
			Zcur->link->link = 0;
			SortedMergeRecur(Xhead, Yhead->link, Zhead);
		}
		//ShowAll(cout, Zhead);
		//SortedMergeRecur(Xhead, Yhead->link, Zhead);
	}
}


