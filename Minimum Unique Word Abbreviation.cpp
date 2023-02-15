string minAbbreviation(string& target, vector<string>& dict){
  
  vector<int> a;
  a.reserve(dict.size());

  for(int i=0; i<len(dict); ++i)
    if(len(target) == len(dict[i])){
      int mask=0;
      for(int j=0; j<len(target); ++j)
        if(dict[i][j] == target[j])
          mask |= (1ll<<(dict[i][j]-'a'));
      a.eb(mask);
    }

  if(a.empty())
    return to_string(len(target));

  //cout << a << endl;
  int ln = len(target);
  int Mask=0;

  for(int mask=1; mask < (1<<len(target)); ++mask){
    bool chk=true;
    for(auto bits: a)
      if((mask & bits) == mask){
        chk=false;
        break;
      }
    
    if(!chk)
      continue;
    
    int cnt1=0, cnt2=0, in=-1;
    for(int i=0; i<len(target); ++i){
      if(mask & (1ll<<i))
        cnt1++, in=0;
      else{
        if(in != 1)
          ++cnt2;
        in=1;
      }
    }

    if(cnt1+cnt2 < ln){
      ln=cnt1+cnt2;
      Mask=mask;
    }
  }

  //cout << ln << '\n' << Mask << '\n';
  string ans;
  int cnt=0;
  for(int i=0; i<len(target); ++i){
    if(Mask & (1ll << i)){
      if(cnt)
        ans += to_string(cnt);
      ans += target[i];
      cnt=0;
    }
    else
      cnt++;
  }
  if(cnt)
    ans += to_string(cnt);
  return ans;
}
