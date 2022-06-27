// 乱数生成
// https://ja.wikipedia.org/wiki/メルセンヌ・ツイスタ
//std::default_random_engine engine{}; // for debug
#include <random>
class UniDist {  // 一様乱数
   std::random_device seed;
   std::mt19937 engine;
   std::uniform_int_distribution<int> udist;
public:
   UniDist(int first, int last) // [first, last] 
      :seed{}, engine{seed()}, udist{first,last}{}
   auto get(){ return udist(engine); }
};

class ExpDist{ // unit時間にtimes回発生する条件の乱数
   std::random_device seed;
   std::mt19937 engine;
   std::exponential_distribution<double> edist;
   double unit;
public:
   ExpDist(double lambda, double u =1.0)
      :seed{}, engine{seed()}, edist{lambda}, unit{u}{}
   // 次に起こるまでの時間
   auto get(){ return edist(engine)*unit; }
};
