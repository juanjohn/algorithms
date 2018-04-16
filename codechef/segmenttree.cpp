//QSET from https://www.codechef.com/JAN15/problems/QSET

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct SegmentTreeNode {
  long long nofn3,nofl2,nofl1,nofl3,nofr1,nofr2,nofr3;
  bool one,two,three;

  void assignLeaf(long long value) {
    if(value%3==0){
      one=two=false;
      three=true;
      nofn3=1;
      nofl1=0;
      nofl2=0;
      nofl3=1;
      nofr1=0;
      nofr2=0;
      nofr3=1;
    }else if(value%3==1){
      two=three=false;
      one=true;
      nofn3=0;
      nofl1=1;
      nofl2=0;
      nofl3=0;
      nofr1=1;
      nofr2=0;
      nofr3=0;
    }
    else{
      one=three=false;
      two=true;
      nofn3=0;
      nofl1=0;
      nofl2=1;
      nofl3=0;
      nofr1=0;
      nofr2=1;
      nofr3=0;
    }

  }

  void merge(SegmentTreeNode& l, SegmentTreeNode& r) {
    nofn3=l.nofn3+r.nofn3+l.nofr2*r.nofl1+l.nofr1*r.nofl2+l.nofr3*r.nofl3;
    nofl2=l.nofl2+l.one*r.nofl1+l.two*r.nofl3+l.three*r.nofl2;
    nofl1=l.nofl1+l.one*r.nofl3+l.two*r.nofl2+l.three*r.nofl1;
    nofl3=l.nofl3+l.one*r.nofl2+l.two*r.nofl1+l.three*r.nofl3;
    nofr1=r.nofr1+r.one*l.nofr3+r.two*l.nofr2+r.three*l.nofr1;
    nofr3=r.nofr3+r.one*l.nofr2+r.two*l.nofr1+r.three*l.nofr3;
    nofr2=r.nofr2+r.one*l.nofr1+r.two*l.nofr3+r.three*l.nofr2;
    if((l.one && r.two) || (l.two && r.one) || (l.three && r.three)){
      one=two=false;
      three=true;
    }
    else if((l.three && r.one) || (l.one && r.three) || (l.two && r.two)){
      three=two=false;
      one=true;
    }
    else{
      one=three=false;
      two=true;
    }
  }

  long long getValue() {
    return nofn3;
  }
};

template<class T, class V>
class SegmentTree {
  SegmentTreeNode* nodes;
  long long N;

public:
  SegmentTree(T arr[], long long N) {
    this->N = N;
    nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }

  ~SegmentTree() {
    delete[] nodes;
  }

  V getValue(long long lo, long long hi) {
    SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }

  void update(long long index, T value) {
    update(1, 0, N-1, index, value);
  }

private:
  void buildTree(T arr[], long long stIndex, long long lo, long long hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }

    long long left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }

  SegmentTreeNode getValue(long long stIndex, long long left, long long right, long long lo, long long hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];

    long long mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);

    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
  }

  long long getSegmentTreeSize(long long N) {
    long long size = 1;
    for (; size < N; size <<= 1L);
    return size << 1L;
  }

  void update(long long stIndex, long long lo, long long hi, long long index, T value) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(value);
      return;
    }

    long long left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);

    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};

int main() {
  long long N, i, A[100000], M, x, y, operation;
  char str[100001];
  scanf("%lld%lld", &N,&M);
  scanf("%s",str);
  for (i = 0; i < N; ++i){
    A[i]=str[i]-48;
  }
  SegmentTree<long long,long long> st(A, N);
  for (i = 0; i < M; ++i) {
    scanf("%lld %lld %lld", &operation, &x, &y);
    if (operation == 1)
      st.update(x-1, y);
    else
      printf("%lld\n", st.getValue(x-1, y-1));
  }

  return 0;
}
