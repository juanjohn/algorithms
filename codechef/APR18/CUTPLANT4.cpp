#include <stdio.h>
#include <algorithm>
typedef long long int ll;
#include <math.h>
#include <limits.h>

using namespace std;

// A utility function to get minimum of two numbers
ll minVal(ll x, ll y) { return (x < y)? x: y; }

// A utility function to get the middle index from corner indexes.
ll getMid2(ll s, ll e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range
     of array indexes. The following are parameters for this function.

    st    --> Poller to segment tree
    index --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                  by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
ll RMQUtil2(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;

    // If a part of this segment overlaps with the given range
    ll mid = getMid2(ss, se);
    return minVal(RMQUtil2(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil2(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
ll RMQ2(ll *st, ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil2(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
ll constructSTUtil2(ll arr[], ll ss, ll se, ll *st, ll si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    ll mid = getMid2(ss, se);
    st[si] =  minVal(constructSTUtil2(arr, ss, mid, st, si*2+1),
                     constructSTUtil2(arr, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
ll *constructST2(ll arr[], ll n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    ll x = (ll)(ceil(log2(n)));

    // Maximum size of segment tree
    ll max_size = 2*(ll)pow(2, x) - 1;

    ll *st = new ll[max_size];

    // Fill the allocated memory st
    constructSTUtil2(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}





// A utility function to get minimum of two numbers
ll maxVal(ll x, ll y) { return (x > y)? x: y; }

// A utility function to get the middle index from corner indexes.
ll getMid(ll s, ll e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range
     of array indexes. The following are parameters for this function.

    st    --> Poller to segment tree
    index --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                  by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MIN;

    // If a part of this segment overlaps with the given range
    ll mid = getMid(ss, se);
    return maxVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
ll RMQ(ll *st, ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    ll mid = getMid(ss, se);
    st[si] =  maxVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
ll *constructST(ll arr[], ll n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    ll x = (ll)(ceil(log2(n)));

    // Maximum size of segment tree
    ll max_size = 2*(ll)pow(2, x) - 1;

    ll *st = new ll[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

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

ll minf(ll a , ll b){
	if(a>b)
		return b;
	return a;
}

ll maxf(ll a , ll b){
	if(a>b)
		return a;
	return b;
}

bool comp (node i,node j) {
	if(i.val==j.val){
		return i.pos<j.pos;
	}
	return (i.val<j.val);
}

ll j,k,t,res,cnt,a,b,c,ini[100001],q,n,fin[100001],ini2[100001],fin2[100001];
bool flag;
node fins[100001];
ll *st;
ll *st2;

ll findcuts(ll a, ll b){
	ll l,r,i,sum=0;
	// printf("### %lld %lld \n",a,b );

	if(b<a){
		// printf("sec1 \n0 ***\n" );
		return 0;
	}else if(b==a){
		if(fin[b]==ini[b]){
			// printf("sec21 \n0 ***\n" );
			return 0;
		}
		else{
			// printf("sec22 \n1 ***\n" );
			return 1;
		}
	}else{
		// printf("sec3 " );
		ll max = RMQ(st,n,a,b);
		// printf("%lld ", max);
		l = first(fins,0,n-1,max,n);
		r = last(fins,0,n-1,max,n);
		// printf("occur %lld %lld ",l,r );
		ll pos1,pos2;
		ll flag=false;
		//printf("max %lld %lld %lld \n", max, fins[l].pos,fins[r].pos);
		// printf("{beg %lld\n",sum );
		sum += findcuts(a,fins[l].pos-1);
		// printf("beg} %lld\n", sum );

		ll prev=-1;
		for(i=l;i<r;i++){
			pos1=fins[i].pos;
			pos2=fins[i+1].pos;
			//printf("pos %lld %lld ",pos1,pos2 );
			sum+=findcuts(maxf(pos1,a)+1,minf(pos2,b)-1);
			if(fin[pos1]<ini[pos1] && pos1>=a && pos1<=b){
				flag=true;
				if(prev==-1){
					sum+=1;
					prev=fins[i].pos;
				}else{
					if(max<=RMQ2(st2,n,prev+1,pos1-1)){//what happens if range not proper###############

					}else{
						sum+=1;
						prev=fins[i].pos;
					}
				}
			}
		}
		pos1=fins[i].pos;
		//printf("{end %lld \n", sum );
		sum+=findcuts(fins[i].pos+1,b);
		//printf("end} %lld \n", sum );
		if(fin[pos1]<ini[pos1] && pos1>=a && pos1<=b){
			flag=true;
			if(prev==-1){
				sum+=1;
				prev=fins[i].pos;
			}else{
				if(max<=RMQ2(st2,n,prev+1,pos1-1)){//what happens if range not proper###############

				}else{
					sum+=1;
					prev=fins[i].pos;
				}
			}
		}

		//printf("%lld ***\n",sum );
		return sum;
	}
}

int main(){
	t=inp();
	ll i,min,max,sum;
	while(t--){
		sum=0;
		n=inp();
		for(i=0;i<n;i++){
			ini2[i]=inp();
		}
		for(i=0;i<n;i++){
			fin2[i]=inp();
		}
		cnt=0;
		sum=0;
		min=INT_MAX;
		max=INT_MIN;
		for(i=0;i<n-1;i++){
			if(fin2[i]!=fin2[i+1]){
				min=minf(min,ini2[i]);
				max=maxf(max,ini2[i]);
				ini[cnt]=min;
				if(min==fin2[i] && max!=fin2[i]){
					sum++;
				}
				fin[cnt++]=fin2[i];
				min=INT_MAX;
				max=INT_MIN;
			}else{
				min=minf(min,ini2[i]);
				max=maxf(max,ini2[i]);
			}
		}
		if(fin2[i]==fin2[i-1]){
			min=minf(min,ini2[i]);
			max=maxf(max,ini2[i]);
			ini[cnt]=min;
			if(min==fin2[i] && max!=fin2[i]){
				sum++;
			}
			fin[cnt++]=fin2[i];
			min=INT_MAX;
			max=INT_MIN;
		}else{
			ini[cnt]=ini2[n-1];
			fin[cnt++]=fin2[n-1];
		}

		n=cnt;
		//printf("%lld\n", cnt);

		// for(i=0;i<n-1;i++){
		// 	printf("%lld ", ini[i]);
		// }
		// printf("%lld\n",ini[i] );
        //
		// for(i=0;i<n-1;i++){
		// 	printf("%lld ", fin[i]);
		// }
		// printf("%lld asd\n",fin[i] );
        //
		// return 0;
		//#################################

		//printf("SUM SO FAR - %lld \n", sum);
		for(i=0;i<n;i++){
			fins[i].val=fin[i];
			fins[i].pos=i;
		}
		st = constructST(fin, n);
		st2 = constructST2(ini, n);
		//st.getValue(x, y)
		sort(fins,fins+n,comp);

		// for(i=0;i<n;i++){
		// 	printf("%lld %lld %lld\n",fins[i].val,fins[i].pos,ini[i] );
		// }

		flag=true;
		for(i=0;i<n;i++){
			if(ini[i]<fin[i]){
				flag=false;
				break;
			}
		}
		if(flag)
		printf("%lld\n", sum+findcuts(0,n-1));
		else
		printf("-1\n");

	}
	return 0;
}
