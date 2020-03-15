#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		sort(products.begin(), products.end());
		vector<vector<string>> ans;
		vector<string> typ;
		int j = 0;

		for (int i = 0; i < products.size(); i++)
		{

			if (products[i][0] == searchWord[0])
			{
				typ.push_back(products[i]);
			}

		}


		for (auto s : searchWord)
		{
			vector<string> a;
			for (int i = 0; i < typ.size(); )
			{
				if (j >= typ[i].size())
				{

					typ.erase(typ.begin() + i);
					continue;
				}



				if (typ[i][j] == s)
				{
					a.push_back(typ[i]);
					i++;
				}

				else
					typ.erase(typ.begin() + i);

				if (a.size() > 3)
					a.resize(3);


			}
			ans.push_back(a);
			j++;
		}



		return ans;


	}
};
