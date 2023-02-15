int wordsTyping(vector<string>& sentence, int rows, int cols){
  int num=0, index=0, res=0;
  for(int i=0; i<rows; ++i){
    while(index + len(sentence[num]) <= cols){
      index += len(sentence[num])+1;
      ++num;
      if(num == len(sentence)){
        num=0;
        res++;
      }
    }
    index=0;
  }
  return res;
}
