# 6207번: Cow Picnic - <img src="https://static.solved.ac/tier_small/10.svg" style="height:20px" /> Silver I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6207)


<p>The cows are having a picnic! Each of Farmer John's K (1 &lt;= K &lt;= 100) cows is grazing in one of N (1 &lt;= N &lt;= 1,000) pastures, conveniently numbered 1...N. The pastures are connected by M (1 &lt;= M &lt;= 10,000) one-way paths (no path connects a pasture to itself).</p>

<p>The cows want to gather in the same pasture for their picnic, but (because of the one-way paths) some cows may only be able to get to some pastures. Help the cows out by figuring out how many pastures are reachable by all cows, and hence are possible picnic locations.</p>



## 입력


<ul>
<li>Line 1: Three space-separated integers, respectively: K, N, and M</li>
<li>Lines 2..K+1: Line i+1 contains a single integer (1..N) which is the number of the pasture in which cow i is grazing.</li>
<li>Lines K+2..M+K+1: Each line contains two space-separated integers, respectively A and B (both 1..N and A != B), representing a one-way path from pasture A to pasture B.</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: The single integer that is the number of pastures that are reachable by all cows via the one-way paths.</li>
</ul>



## 소스코드

[소스코드 보기](Cow%20Picnic.cpp)