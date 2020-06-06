#### 题目

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:



Only one letter can be changed at a time

Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:



Return an empty list if there is no such transformation sequence.

All words have the same length.

All words contain only lowercase alphabetic characters.

You may assume no duplicates in the word list.

You may assume beginWord and endWord are non-empty and are not the same.

Example 1:



Input:

beginWord = "hit",

endWord = "cog",

wordList = ["hot","dot","dog","lot","log","cog"]



Output:

[

  ["hit","hot","dot","dog","cog"],

  ["hit","hot","lot","log","cog"]

]

Example 2:



Input:

beginWord = "hit"

endWord = "cog"

wordList = ["hot","dot","dog","lot","log"]



Output: []



Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


找出最短路径长度的所有路径集合



你得记录一个最短路径长度吧，word ladder 已经求出来了；

你得有一个路径集合吧，然后判断当前路径的长度 和最短路径的大小，比最短路径大，就需要舍弃这个路径； so, 先求出最短路径？在接着走？有什么办法能一个BFS搞定？


BFS 的队列 是一个路径的集合` queue<vector<string> > paths;`
一开始存放的是原始路径`orginPath`(放着起始的单词）， 还要一个`unordered_set<string> words; `存放已经访问过的单词, 两个int型变量，level 存放当前路径的长度，minlevel 存放最小的路径长度

开始循环， paths不为空进入循环
1. 取队列paths的第一个路径curPath
2. curPath长度 大于当前路径长度， 说明有重复
3. 获取curPath的最后一个元素curPath.back()
4. 修改最后一个元素的每位元素值，和字典中元素对比，有的话就新建一个路径，再和目标单词对比，一样则是最小路径，更新到结果res里，不一样的，则放到Paths中, 这一波会形成多个路径在path集合里

**为什么不在for循环里，使用一个词，就删掉这个词？（类似wordladder i的那种做法）**
答：这是防止两个最短路径里会使用同一个词，如下面的例子，red->rex->tex  和 red->ted->tex 都会使用tex，如果第一次使用，就删掉了tex, 那么后面的一个最短路径就查不到了；

"red"
"tax"
["ted","tex","red","tax","tad","den","rex","pee"]
预期结果：[["red","rex","tex","tax"],["red","ted","tex","tax"],["red","ted","tad","tax"]]

**那应该是什么时候删除访问过的词？** 
答：层序遍历 分层的时候， 也就是 当队列中放入的路径长度 比上一次放入的路径长度大的时候

跑一边记录下循环过程，可以发现，删除的时候，就像BFS 在层序遍历二叉树时，是进入到下一层的时候才会删除已访问过的单词，这也就保证了["red","rex","tex","tax"]和 ["red","ted","tex","tax"] 两个结果会公用tex的时候，tex不会被删除，同时进入下一层删除已访问过的单词，最大限度减少算法的时间复杂度；
```
当前路径为：red
新建的路径：red->ted
新建的路径：red->rex
当前路径为：red->ted
删除已访问过的单词：	ted	rex
新建的路径：red->ted->tad
新建的路径：red->ted->tex
当前路径为：red->rex
新建的路径：red->rex->tex
当前路径为：red->ted->tad
删除已访问过的单词：	tex	tad
新建的路径：red->ted->tad->tax
当前路径为：red->ted->tex
新建的路径：red->ted->tex->tax
当前路径为：red->rex->tex
新建的路径：red->rex->tex->tax
当前路径为：red->ted->tex->tax
删除已访问过的单词：	tax
```

```
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> res;
		unordered_set<string> dict(wordList.begin(), wordList.end());
		vector<string> p{ beginWord }; // p 是起始路径，在p中吧起始单词放进去

		if (dict.find(endWord) == dict.end()) return res; 
		if (dict.find(beginWord) != dict.end()) dict.erase(beginWord);

		queue<vector<string>> paths;  // 所有路径的路径集 paths 
		paths.push(p);
		// level 是上一个入队列的路径的长度  minlevel是记录最短路径的长度
		int level = 1, minLevel = INT_MAX;

		unordered_set<string> words; //用来记录已经循环过的路径中的词
		
		while (!paths.empty()) {

			auto curPath = paths.front(); 
			paths.pop();
			// 如果该路径的长度大于 上一个入队列的路径的长度level，也就是分层的时候，开始删除已访问过的单词 
			if (curPath.size() > level) {
				for (string w : words)
				{
					dict.erase(w);
				}
				words.clear();
				level = curPath.size();
				if (level > minLevel) break;
			}
			string last = curPath.back();
			for (int i = 0; i < last.size(); ++i) {
				string newLast = last;
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					newLast[i] = ch;
					if (!dict.count(newLast)) continue;
					words.insert(newLast);
					vector<string> nextPath = curPath;
					nextPath.push_back(newLast);
					if (newLast == endWord) {
						res.push_back(nextPath);
						minLevel = level;
					}
					else 
						paths.push(nextPath);
				}
			}
		}
		return res;
	}
};
```

加日志版本,方便调试理解
```
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> res;
		unordered_set<string> dict(wordList.begin(), wordList.end());
		vector<string> p{ beginWord }; // p 是起始路径，在p中吧起始单词放进去

		if (dict.find(endWord) == dict.end()) return res; 
		if (dict.find(beginWord) != dict.end()) dict.erase(beginWord);

		queue<vector<string>> paths;  // 所有路径的路径集 paths 
		paths.push(p);
		// level 是上一个入队列的路径的长度  minlevel是记录最短路径的长度
		int level = 1, minLevel = INT_MAX;

		unordered_set<string> words; //用来记录已经循环过的路径中的词
		
		std::ofstream log;
		log.open("F:\\1.txt", std::ios::app);
		while (!paths.empty()) {

			auto curPath = paths.front(); 
			paths.pop();

			log << "当前路径为：";
			for (string w : curPath)
			{
				if (w == curPath.front())
					log << w;
				else
					log << "->" << w;
			}
			log << endl;
			// 如果该路径的长度大于 上一个入队列的路径的长度level，也就是分层的时候，开始删除已访问过的单词 
			if (curPath.size() > level) {
				log << "删除已访问过的单词：";
				for (string w : words)
				{
					log << "\t" << w;
					dict.erase(w);
				}
				log << endl;
				words.clear();
				level = curPath.size();
				if (level > minLevel) break;
			}
			string last = curPath.back();
			for (int i = 0; i < last.size(); ++i) {
				string newLast = last;
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					newLast[i] = ch;
					if (!dict.count(newLast)) continue;
					words.insert(newLast);
					vector<string> nextPath = curPath;
					nextPath.push_back(newLast);
					if (newLast == endWord) {
						res.push_back(nextPath);
						minLevel = level;
					}
					else 
						paths.push(nextPath);

					log << "新建的路径：";
					for (string w : nextPath)
					{
						if (w == nextPath.front())
							log << w;
						else
							log << "->" << w;
					}
					log << endl;;
				}
			}
		}
		log.close();
		return res;
	}
};

int main()
{
	string beginWord("red"), endWord("tax");
	vector<string> wordList;
	wordList.push_back("ted");
	wordList.push_back("tex");
	wordList.push_back("red");
	wordList.push_back("tax");
	wordList.push_back("tad");
	wordList.push_back("den");
	wordList.push_back("rex");
	wordList.push_back("pee");

	Solution sol;
	vector<vector<string> > res = sol.findLadders(beginWord, endWord, wordList);

	return 0;

```









