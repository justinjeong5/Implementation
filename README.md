# ***ALGORITHM***

**Basic operation**
-------
     primitive operation 중에서 input size N에 비례하는 operation

이제 다루게 될 sorting algorithm은 원소간의 크기 비교를 통해서 할 수 있으므로 대부분 comparison operation을 중심으로 분석한다. 그밖에도 basic operaion은 +, -, *, /, %, ==, !=, <, >, =, 함수호출 등 여러가지가 있다. 

<br>
**Analysis of algorithm**
-----
     experimental analysis와 theorical analysis가 있다.  
- emperimental analysis
    - shortcoming
        1. 직접 코드를 작성하여 분석한다.
        1. 모든 input N에 대해 확인하는 것은 거의 불가능하다.
        1. computer의 성능에 따라 결과가 다를 수 있다.

- theorical analysis
    - merit 
        1. psuedo code에서 분석한다.
        1. 모든 input에 대한 분석이 가능하다.
        1. computer의 성능을 고려하지 않는다.

<br>
**Optimality**
-----
     문제의 complexity인 F(n)과 algorithm의 complexity인 W(n)가 점근적으로 같으면 optimal이다.

<br>
**arithemtic_geometric series**
-----

![수식1](https://www4f.wolframalpha.com/Calculate/MSP/MSP87951567ac1f0b8bi97g000030fh7gd590dgf727?MSPStoreType=image/gif&s=49) 


![수식2](https://www5b.wolframalpha.com/Calculate/MSP/MSP127341i5b1eba6405c616000063a3f87dg53h4g99?MSPStoreType=image/gif&s=49)<br>
이 식은 앞으로 배우게 될 asymtotic analysis에서 자주 등장하게 될 수식이다.
<br><br>

![수식3](https://www5b.wolframalpha.com/Calculate/MSP/MSP45821fi15e214i8c7cf500004c207ebb95h5ba84?MSPStoreType=image/gif&s=50)

![수식4](https://www5b.wolframalpha.com/Calculate/MSP/MSP75301h0b609cag268b7d000020c3ad668e56ah90?MSPStoreType=image/gif&s=31)
<br>
위의 두 식은 asymtotic analysis에 의해서 최고차항만 사용하게 된다.
간단히 소개하자면 asymtotic analysis에서는 input size N을 매우 큰 수로 상정한다. 따라서 고등학교 수학에서 배웠던 극한의 개념을 떠올려보면, 최고차항의 크기만으로 서로간의 크기를 비교한다. 이는 수식이 갖는 "증가율"이 어느쪽이 더 큰지 비교하는 것과 같은 결과이다.

<br>
**worst case analysis**
-----
<br>
나중에 마무리하자....

<br>

***Sorting Algtorithm***
=====
> `Insertion sort`<br>
> `Quick sort`<br>
> `Merge sort`<br>
> `Headp sort`<br>
> `Radix sort`<br>


| sorting algorithm | complexity of problem | complexity of algorithm | average time| optimality |
|:---:|:---:|:---:|:---:|:---:|
| Insertion sort | O(nlog(n)) | O(n^2) | O(n^2 / 4) | X |
| Quick sort | O(nlog(n)) | O(n^2) | O(nlog(n)) | X |
| Merge sort | O(nlog(n)) | O(nlog(n)) | - | O |
| Heap sort | O(nlog(n)) | O(nlog(n)) | - | O |
| Radix sort | - | O(n) | - | - | 

**Application of Sorting**
----
sorting을 공부하기에 앞서, 과연 sorting이 필요한지 이야기해보자. 위 표를 보니 정수 배열을 비교연산을 통해 정렬하는 문제의 복잡도는 O(nlog(n))으로 merge sort와 heap sort인 경우에는 최적화된 정렬 알고리즘이다. 

<br>

| input order | sorting algorithm | complexity of problem | complexity of algorithm | optimality |
|---|---|:---:|:---:|:---:|
| unsorted | binary search | O(n) | O(n) | O |
| sorted | binary search | O(log(n)) | O(log(n)) | O |

binary search의 경우 정렬되지 않은 상태의 배열이 주어지면 O(n) 시간에, 크기 순서대로 정렬된 상태의 배열이 주어지면 O(log(n))의 시간에 원하는 수를 찾아 낼 수 있다. N개의 input에 대해 O(log(n))의 시간이 든다면 sort에 비해 overhead도 적고 깔끔할텐데도 sort를 해야하는 이유는 data의 활용도 측면에 있다. 존재하는 자료를 가지고 새로운 의미를 가진 data를 창출할 때, data가 정렬 된 상태라면 효율성이 더 좋다. 이때 증가한 효율성이 sorting에서 발생한 overhead보다 더 크기떄문에 sorting은 매우 가치있는 일이다. 


**`Insertion Sort`**
----
insertion sort는 가장 기본적인 정렬 알고리즘이다. 구현하기 가장 쉽고, input size가 충분히 작은 경우라면 상당히 짧은 시간에 정렬을 완료할 수 있다. 앞으로 보게 될 다른 소팅 알고리즘과의 또 다른 insertion sort만의 차이는 입력을 받으면서 수행 할 수 있느냐에 있다. 실제로는 입력을 사용자로부터 모두 받은 뒤에 insertion sort를 진행하겠지만 이론적으로 insertion sort는 입력으로 원소가 하나씩 들어올떄마다 정렬시킬 수 있다. 이런 특성 가진 함수를 Online 함수라고 한다. 또한 입력을 정렬하기 위해 추가적인 공간이 필요한데 insertion sort의 경우에는 O(1)의 추가공간만 소요되게 만들 수 있다. 추가 공간이 O(1), 또는 O(logn)에 bounded되는 경우를 inplace algorithm이라고 한다.
> online 함수 : 입력이 들어올떄 마다 정렬한 결과와 입력을 모두 다 받은 후 한번에 정렬한 결과가 같은 함수

> inplace algorithm : 추가적으로 드는 공간이 O(1)인 경우. 재귀적으로 호출되면서 inplace인 경우는 추가공간이 O(logN)이다.

<br>

다음은 입력이 E = <3, 7, 2, 5, 1, 4>인 경우의 도식이다.

*******************[insertion sort](https://upload.wikimedia.org/wikipedia/commons/e/ea/Insertion_sort_001.PNG)


    sorted sequence : 위 그림의 회색 부분이 sorted sequence이다. 
    key : 현재 정렬하고자 하는 값으로, sorted sequence에 삽입될 대상이다.

**pseudo code**
----

```c++
void insertionSort(Element[] E, int n)
int xindex;
for (xindex = 1; xindex < N; xindex++)
    Element current = E[xindex];
    key x = current.key;
    int xLoc = shiftVacRec(E, xindex, x);
    E[xLoc] = current;
return;
```

```c++
int shiftVacRec(Element[] E, int vacant, Key x)
int xLoc;
if(vacant == 0)
    xLoc = vacant;
else if(E[vacant - 1].key <= x)
    xLoc = vacant;
else
    E[vacant] = E[vacant - 1];
    xLoc = shiftVacRec(E, vacant - 1, x);
return xLoc;
```

**worst case analysis**
----
     insertion sort의 최악의 수행시간 : 입력이 내림차순으로 들어오는 경우, sorted sequence를 매번 sorted sequence의 크기만큼 비교연산을 수행해야 하는 경우.

n개의 입력에 대해 첫번째 원소는 비교연산을 수행할 sorted sequence의 원소가 존재하지 않는다. 이후 정렬을 실행할때 마다 하나씩 sorted sequence의 크기가 증가하다가 더 이상 비교할 input의 원소가 없으면 종료된다.


| 남은 비교 대상 | sorted sequence의 크기 | 비교 연산의 수 | 
|:---:|:---:|:---:|
| n | 0 | 0 |
| n - 1 | 1 | 0 |
| n - 2 | 2 | 1 |
| ... | ... | ... |
| 1 | n -1 | n - 2 |
| 0 | n | n - 1 |

이 모든 비교 연산의 수를 더하면

![insertion_sort_worst_analysis_series](https://www5a.wolframalpha.com/Calculate/MSP/MSP1559523631590gi53da360000534e09bagd3aa859?MSPStoreType=image/gif&s=54)

으로 정리가 되고, 이를 asymtotic analysis을 이용하여 O(n^2)이 됨을 알 수 있다.


**insertion sort의 correctness 분석**
-----

Loop variant 방법을 이용한 알고리즘의 correctness분석법으로 설명해보겠다. loop variant 분석방법은 3단계로 이루어져 있다. 
        
    1. Inivializaion : Loop가 시작하기 전에 property가 참임을 보이는 단계
    2. Maintainance : 임의의 i번째에서 property가 참이라면, i+1 번쨰 단계가 참임을 보이는 단계
    3. Termination : Loop의 반복이 끝나도 property가 유지됨을 보이는 단계


1) 첫 번쨰 들어온 원소는 그 자체가 sorted sequence임으로 Initializaion 단계는 참이다.
2) i번쨰까지 sorted sequence의 property를 만족하고, i+1번째가 shifting되면 sorted sequence가 만족되므로 참이다.
3) loop가 끝나면 index 값이 n이 되고, n-1번째까지는 모두 sorted sequence이므로 참이다.

3가지 조건을 모두 만족하므로 correct하다. 즉, sort과정에서 순차적인 접근만 가능하다면 insertion sort는 optimal이다. 다만, 대부분의 경우 random access가 가능하므로 최선의 정렬 알고리즘은 아니다.

**`Quick sort`**
----

    partition으로 구현한 함수 : Quick sort
    inplace partitioning으로 구현한 함수 : inplace quick sort

**worst case time complexity**
-----

임의의 pivot이 매번 최소값 또는 최대값인 경우

![퀵소트](https://www.wolframalpha.com/input/?i=1%2F2+%282+-+3+n+%2B+n%5E2%29&lk=1&assumption=%22ClashPrefs%22%20-%3E%20{%22Math%22})

O(n^2)



**`Merge sort`**
-----
```c++
void mergeSort(Element[] E, int first, int last)
if (first < last)
    int mid = (first + last) / 2;
    mergeSort(E, first, mid);
    mergeSort(E, mid+1, last);
    merge(E, first, mid, last);
return;
```

```c++
merge(A, B, C)
if (A is empty)
    rest of C = rest of B
else if(B is empty)
    rest of C = rest of A
else if(first of A <= first of B)
    first of C = first of A
    merge(rest of A, B, rest of C)
else first of C = first of B
    merge(A, rest of B, C)
return
```


**`Heap sort`**
-----
    fixHeap = O(2nlogn) + O(n)
    fixHeapFast = bubbleUpHeap + fixHeadFast = O(nlogn) + O(nloglogn) + O(n)

fixHeap을 이용한 Heap Sort

```c++
void heapSort(Element[] E, int n)
    constructHeap(E)
    for (i = n; i >= 1; i--)
        curMax = getMax(H)
        deleteMax(H)
        E[i] = curMax
```

```c++
void deleteMax(H)
    H의 맨 끝 노드를 임시변수 K에 저장 후, fixHeap(H, k)를 통해 정렬
```

```c++
void constructHeap(H)
    if(H is not a leaf)
        contructHeap(Left of subtree H)
        contructHeap(right of subtree H)
        Element k = root(H)
        fixHeap(H, k)
    return
```

```c++
void fixHeap(H, k)
    if( H is a leaf)   
        insert k in root(H)
    else 
        if(k.key >= root(largerSubtree.key))
            insert k in root(H)
        else 
            insert root(largerSubtree) in root(H)
            fixHeap(largerSubtree, k)
    return
```

**worst case time complexity**
-----


* constructHeap : perfect binary tree 구조이면서 fixHeap이 매번 leaf까지 발생하는 경우

![contructHeap_수식](https://www4d.wolframalpha.com/Calculate/MSP/MSP23691a65ifid3128gh9i0000644afbf2i0158571?MSPStoreType=image/gif&s=43)

따라서 O(n)에 bounded된다.

* n개에 대한 deleteMax
worst case : fixHeap이 leaf까지 수행되는 경우

| depth | 비교연산 |
|:---:|:---:|
| 0 | 자식간의 대소비교 1회 + 부모와 더 큰 자식간의 대소비교 1회 |
| 1 | 자식간의 대소비교 1회 + 부모와 더 큰 자식간의 대소비교 1회 |
| 2 | 자식간의 대소비교 1회 + 부모와 더 큰 자식간의 대소비교 1회 |
| ... | ... |
| logn | 부모 node에서 자식산의 대소비교 1회 + 부모와 더 큰 자식간의 대소비교 1회 |

stirling's approximation에 의해 O(nlogn)에 bounded된다.

