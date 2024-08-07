# 21324번: Mars Message - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->
### 성능 요약
메모리: 2020 KB, 시간: 688 ms
<!-- end -->

## 문제

[문제 링크](https://boj.kr/21324)


<p>In the film <em>The Martian</em>, astronaut Mark Watney is stuck on Mars, and communicates with earth by rotating a camera on an old space prod.</p>

<p>The prod points at a hexidecimal digit, i.e. <code>0-9</code> or <code>a-f</code>, and Mark creates letters and other characters by converting a pair of hexadecimal digits according to ASCII encoding. To determine which digit the prod is pointing at Mark has divided a circle of 360 degrees into 16 parts of 22.5 degrees each.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/41c226d1-f550-4b6e-9fe2-db5a2d78e14f/-/preview/" style="width: 305px; height: 275px;"></p>

<p>For example, the pair of angles $(100*{\circ}, 30^{\circ})$ represents the hexadecimal number 41, which in decimal is $65$. According to <a href="https://en.wikipedia.org/wiki/ASCII\#ASCII\_printable\_characters">ASCII</a>&nbsp;that is the character <code>A</code>.</p>

<p>Mark is getting tired of writing down the digits manually, and he asks you to help him decode the messages he receives. You will be given the sequence of angles the prod points at and you're expected to print the message.</p>



## 입력


<p>The first line consists of an integer $2 \le N \le 50\,000$, the number of angles. $N$ will be even.</p>

<p>The following $N$ lines contain angles, one angle per line. An angle is given in degrees as a float in the range $[0, 360)$. The prod will never point at an angle which is exactly inbetween two hexadecial digits.</p>

<p>When decoding to ASCII only characters with decimal values <code>32-126</code> occurs.</p>



## 출력


<p>Print one line with the decoded message.</p>



## 소스코드

[소스코드 보기](Mars%20Message.cpp)