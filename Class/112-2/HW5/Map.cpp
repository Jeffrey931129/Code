#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
//#include"function.h"

namespace oj
{
	struct String
	{
		std::string str;
		String(const std::string &str_);
		String(const String &rhs);
		String& operator=(const String &rhs);
	};

	std::ostream& operator<<(std::ostream &os,const String &str);

	void insert(std::map<int,String> &ma,int key,const std::string &str);
	void output(const std::map<int,String> &ma,int begin,int end);
	void erase(std::map<int,String> &ma,int begin,int end);

	std::ostream& operator<<(std::ostream &,const std::map<int,String> &);
}

namespace oj
{
	String::String(const std::string &str_)
		:str(str_){}

	String::String(const String &rhs)
		:str(rhs.str){}

	String& String::operator=(const String &rhs)
	{
		str=rhs.str;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const String &str)
	{
		return os<<str.str;
	}
}

int main()
{
	using namespace std;
	using namespace oj;
	map<int,String> ma;
	for(string cmd;cin>>cmd;)
	{
		if(cmd=="insert")
		{
			int key;
			cin>>key>>cmd;
			insert(ma,key,cmd);
		}
		else
			if(cmd=="range")
			{
				int begin,end;
				cin>>cmd>>begin>>end;
				if(cmd=="output")
					output(ma,begin,end);
				else
					if(cmd=="erase")
						erase(ma,begin,end);
					else
						assert(false);
			}
			else
				assert(false);
		cout<<ma<<endl;
	}
}

namespace oj{
	using namespace std;
	void insert(std::map<int,String> &ma,int key,const std::string &str){
		string temp=str; auto find=ma.find(key);
		if(find!=ma.end()) temp+=find->second.str;
		ma.erase(key);
		ma.insert(pair(key,String(temp)));
	}
	void output(const std::map<int,String> &ma,int begin,int end){
		for(auto i:ma){
			if(i.first>=begin&&i.first<=end){
				cout<<i.second<<" ";
			}
		}
	}
	void erase(std::map<int,String> &ma,int begin,int end){
		for(int i=begin;i<=end;i++) ma.erase(i);
	}
	ostream& operator<<(std::ostream &out,const std::map<int,String> &ma){
		for(auto i:ma){
			out<<i.second<<" ";
		}
		return out;
	}
}