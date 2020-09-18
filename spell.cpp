#include "head.h"

map<string, string> map_;

bool init()//const string& filename
{
	ifstream ifs("C:\\Users\\test.txt");
	if (!ifs)
	{
		cout << "file read error" << endl;
		return false;
	}
	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		string key, value;
		iss >> key >> value;
		
		map_.insert(make_pair(key, value));
	//	cout << key << "****" << value << endl;
	}
	ifs.close();
	return true;
}
void show()
{
	map<string, string>::const_iterator mit = map_.begin();
	for (; mit != map_.end(); ++mit)
	{
		cout << mit->first << " --> " << mit->second << endl;
	}
}


vector<pair<string, int> > dict_;
map<string, set<int> > index_table_;

void show_dict()
{
	auto iter = dict_.begin();
	for (; iter != dict_.end(); ++iter)
	{
		std::cout << iter->first << "-->"
			<< iter->second << std::endl;
	}
}

void show_index_table()
{
	auto iter = index_table_.begin();
	for (; iter != index_table_.end(); ++iter)
	{
		std::cout << iter->first << "-->";
		auto sit = iter->second.begin();
		for (; sit != iter->second.end(); ++sit)
		{
			std::cout << *sit << " ";
		}
		std::cout << std::endl;
	}
}

void read_from(const char* dictpath)
{
	std::ifstream in("C:\\Users\\test.txt");
	if (!in)
	{
		std::cout << __DATE__ << " " << __TIME__
			<< __FILE__ << " " << __LINE__
			<< ": dict read error" << std::endl;
		exit(-1);
	}

	std::string line;
	while (getline(in, line))
	{
		std::stringstream ss(line);
		std::string key;
		int value;
		ss >> key >> value;
		dict_.push_back(make_pair(key, value));
	}
	in.close();
}

void record_to_index(int idx)
{
	std::string key;
	std::string word = dict_[idx].first;
	for (std::size_t iidx = 0; iidx != word.size(); ++iidx)
	{
		char ch = word[iidx];

		{
			key = word.substr(iidx, 1);
		}
		index_table_[key].insert(idx);
	}
}
void dic_init(const char* dictPath, const char* cnDictPath)
{
	read_from(dictPath);
	//read_from(cnDictPath);
	//创建索引表
	for (size_t idx = 0; idx != dict_.size(); ++idx)
	{
		record_to_index(idx);
	}
}

class A
{
	/*A operator+(int a)
	{
		
	}*/
};

int main()
{
	A a;

	a = a + 1;

	return 0;
}