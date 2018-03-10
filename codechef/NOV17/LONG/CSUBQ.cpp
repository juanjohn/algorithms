//QSET from https://www.codechef.com/JAN15/problems/QSET

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long L,R;

struct SegmentTreeNode {
	long long n,nl,nr,size,maxv,maxpv;

	void assignLeaf(long long value) {
		if(value>=L && value<=R){
    		size=1;
			maxv=value;
			maxpv=value;
			n=1;
			nl=1;
			nr=1;
    	}
    	else{
    		size=1;
			maxv=value;
			maxpv=-1;
			n=0;
			nl=0;
			nr=0;
    	}
	}

	void merge(SegmentTreeNode& l, SegmentTreeNode& r) {
		size=l.size+r.size;
		maxv=max(l.maxv,r.maxv);
		//maxpv=
		n=l.n+r.n+(l.nr1-l.nr2)*(r.nl2-r.nl1);
		nl=







		size=l.size+r.size;
		max=max(max(l.max,r.max),l.nr+r.nl);
		n=l.n+r.n+l.nr*r.nl;
		nl=l.nl;
		nr=r.nr;
		if(l.nl==l.size)
			nl=l.nl+r.nl;
		if(r.nr==r.size)
			nr=r.nr+l.nr;
		maxv=max(l.maxv,r.maxv);
	}

	long long getValue() {
		return n;
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
  long long N, i, A[500000], Q, x, y, operation;
  char str[100001];
  scanf("%lld%lld%lld%lld", &N,&Q,&L,&R);
  for (i = 0; i < N; ++i){
    A[i]=0;
  }
  SegmentTree<long long,long long> st(A, N);
  for (i = 0; i < Q; ++i) {
    scanf("%lld %lld %lld", &operation, &x, &y);
    if (operation == 1)
      st.update(x-1, y);
    else
      printf("%lld\n", st.getValue(x-1, y-1));
  }

  return 0;
}
