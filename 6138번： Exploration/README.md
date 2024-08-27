# 6138번: Exploration - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->
### 성능 요약
메모리: 2804 KB, 시간: 20 ms
<!-- end -->

## 문제

[문제 링크](https://boj.kr/6138)


<p>Bessie is traveling on a road teeming with interesting landmarks. The road is labeled just like a number line, and Bessie starts at the "origin" (x = 0). A total of N (1 &lt;= N &lt;= 50,000) landmarks are located at points x_1, x_2, ..., x_N &nbsp;(-100,000 &lt;= x_i &lt;= 100,000). Bessie wants to visit as many landmarks as possible before sundown, which occurs in T (1 &lt;= T &lt;= 1,000,000,000) minutes. She travels 1 distance unit in 1 minute.</p>

<p>Bessie will visit the landmarks in a particular order. Since the landmarks closer to the origin are more important to Farmer John, she always heads for the unvisited landmark closest to the origin. No two landmarks will be the same distance away from the origin.</p>

<p>Help Bessie determine the maximum number of landmarks she can visit before the day ends.</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers: T and N</li>
<li>Lines 2..N+1: Line i+1 contains a single integer that is the location of the ith landmark: x_i</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: The maximum number of landmarks Bessie can visit.</li>
</ul>



## 소스코드

[소스코드 보기](Exploration.cpp)