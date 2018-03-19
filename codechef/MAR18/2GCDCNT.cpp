#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

ll inp(){
	register ll c = getchar_unlocked();
	ll neg=0;
	ll ret=0;
	for(; ((c<48 || c>57) && c!='-'); c = getchar_unlocked());
	if(c=='-') {
    	neg=1;c=getchar_unlocked();
    }
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		ret = 10 * ret + c - 48;
	}
	if(neg)
		ret=-ret;
	return ret;
}

ll gcd(ll a, ll b){
	if(b<=1)
		return b;
	else
		return gcd(b,a%b);
}

struct SegmentTreeNode {
  	long long is1;

	void assignLeaf(long long value) {
		if(gcd(value,G))
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

int main(){
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n;
	n=inp();
	for(i=0;i<n;i++){
		arr[i]=inp();
	}
	q=inp();
	SegmentTree<long long,long long> st(arr, N);
	while(q--) {
		t=inp();
		l=inp();
		r=inp();
	  	if(t == 1)
        	st.update(l-1, r);
      	else
        	printf("%lld\n", st.getValue(l-1, r-1));
    }

	return 0;
}
