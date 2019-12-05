/*
ID: opsopsp1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {
	ifstream in("pprime.in",ios::in);
	ofstream out("pprime.out",ios::out);
	if(!in) cout<<"Cannot open file!"<< endl;
	
	int start, end, i, pal;
	in >> start >> end;
	i = (start%2==1)?start:(start+1);
	while (i <= end)
	{
		if (i < 9)
		{
			out << i << endl;
		}
		else if (i == 11) out << 11 << endl;
		else if (i> 100 && i <1000)
		{
			for (int d1 = 1; d1 <= 9; d1+=2)
			{
    			for (int d2 = 0; d2 <= 9; d2++)
				{
					pal = 100*d1 + 10*d2 +d1;
					if (pal < start) continue;
					if (pal > end) break;
					for (int j=3;;j++)
					{
						if (pal%j == 0) break;
						if (j*j >pal)
						{
							out << pal << endl;
							break;
						}
					}
				}
				if (pal > end) break;
			}
		}
		else if (i> 10000 && i <100000)
		{
			for (int d1 = 1; d1 <= 9; d1+=2)
			{
    			for (int d2 = 0; d2 <= 9; d2++)
				{
					for (int d3 = 0; d3 <= 9; d3++)
					{
						pal = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
						if (pal < start) continue;
						if (pal > end) break;
						for (int j=3;;j++)
						{
							if (pal%j == 0) break;
							if (j*j >pal)
							{
								out << pal << endl;
								break;
							}
						}
					}
					if (pal > end) break;
				}
				if (pal > end) break;
			}
		}
		else if (i> 1000000 && i <10000000)
		{
			for (int d1 = 1; d1 <= 9; d1+=2)
			{
    			for (int d2 = 0; d2 <= 9; d2++)
				{	
        			for (int d3 = 0; d3 <= 9; d3++)
					{
						for (int d4 = 0; d4 <= 9; d4++)
						{
			   				pal = 1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
			   				if (pal < start) continue;
			   				if (pal > end) break;
			   				for (int j=3;;j++)
			   				{
			   					if (pal%j == 0) break;
			   					if (j*j >pal)
			   					{
			   						out << pal << endl;
			   						break;
								}
							}
	    				}
	    				if (pal > end) break;
					}
					if (pal > end) break;
    			}
    			if (pal > end) break;
			}
		}
		if (i < 11) i += 2;
		else if (i>10 && i <100) i = 101;
		else if (i>100 && i<10000) i = 10001;
		else if (i>10000 && i <1000000) i = 1000001;
		else break;
	}
	
	out.close();
	return 0;
}
