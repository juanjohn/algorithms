#include <stdio.h>
#include <algorithm>
typedef long long int ll;

using namespace std;

struct SegmentTreeNode {
  long long max;
  //bool one,two,three;

  void assignLeaf(long long value) {
    max=value;

  }

  void merge(SegmentTreeNode& l, SegmentTreeNode& r) {
    if(l.max>r.max){
		max=l.max;
	}else{
		max=r.max;
	}
  }

  long long getValue() {
    return max;
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

ll ceil(ll a, ll d){
	if(a%2==1)
		return a/d+1;
	return a/d;
}

struct node{
	ll val;
	ll pos;
};


/* if x is present in arr[] then returns the index of
   FIRST occurrence of x in arr[0..n-1], otherwise
   returns -1 */
ll first(node arr[], ll low, ll high, ll x, ll n)
{
    if(high >= low)
    {
        ll mid = low + (high - low)/2;
        if( ( mid == 0 || x > arr[mid-1].val) && arr[mid].val == x)
            return mid;
        else if(x > arr[mid].val)
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid -1), x, n);
    }
    return -1;
}


/* if x is present in arr[] then returns the index of
   LAST occurrence of x in arr[0..n-1], otherwise
   returns -1 */
ll last(node arr[], ll low, ll high, ll x, ll n)
{
    if (high >= low)
    {
        ll mid = low + (high - low)/2;
        if (( mid == n-1 || x < arr[mid+1].val) && arr[mid].val == x)
            return mid;
        else if (x < arr[mid].val)
            return last(arr, low, (mid -1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}

bool comp (node i,node j) {
	if(i.val==j.val){
		return i.pos<j.pos;
	}
	return (i.val>j.val);
}

ll i,j,k,t,sum,res,cnt,a,b,c,ini[100000],q,l,r,n,fin[100000];
bool flag;
node fins[100000];

ll findcuts(ll a, ll b){

	if(b<a){
		return 0;
	}else if(b==a){
		if(fin[b]==ini[b])
			return 0;
		else
			return 1;
	}else{
		ll max = st.getValue(a,b);
		l = first(fins,0,n-1,max,n);
		r = last(fins,0,n-1,max,n);
		ll pos1,pos2;
		ll flag=false;
		sum = findcuts(a,fins[l].pos-1);
		for(i=l;i<r;i++){
			pos1=fins[l].pos;
			pos2=fins[l+1].pos;
			sum+=findcuts(pos1+1,pos2-1);
			if(fin[pos1]<ini[pos1] && pos1>=a && pos1<=b)
				flag=true;

		}
		pos1=fins[i].pos;
		if(fin[pos1]<ini[pos1] && pos1>=a && pos1<=b)
			flag=true;
		if(flag)
			sum+=1;
		sum+=findcuts(fins[i].pos+1,b);

		return sum;
	}
}

int main(){

	t=inp();
	while(t--){
		n=inp();
		for(i=0;i<n;i++){
			ini[i]=inp();
		}
		for(i=0;i<n;i++){
			fin[i]=inp();
			fins[i].val=fin[i];
			fins[i].pos=i;
		}
		SegmentTree<long long,long long> st(fin, n);
		//st.getValue(x, y)
		sort(fins,fins+n,comp);

		flag=true;
		for(i=0;i<n;i++){
			if(ini[i]<fin[i]){
				flag=false;
				break;
			}
		}
		if(flag)
		printf("%lld\n", findcuts(0,n-1));
		else
		printf("-1\n");

	}
	return 0;
}
