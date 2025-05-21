# 프로젝트 모음

이 저장소에는 다음 두 프로젝트의 코드가 포함되어 있다.

---

## 1. Data Structures (CSE3080) 과제 모음

과목: Data Structures (CSE3080)

### 구성

```
cse3080_hw1_학번/  # 과제 1: 문자열 패턴 매칭
  ├── problem1
  │   ├── Makefile
  │   ├── probgen.c
  │   ├── hw1_naive.c
  │   ├── hw1_kmp.c
  └── problem2
      ├── Makefile
      ├── hw1_problem2.c

cse3080_hw2_학번/  # 과제 2: 최소 신장 트리 (MST)
  ├── fp1.c
  ├── Makefile
  └── input_large.txt (예시)
```

### 과제 1: 문자열 패턴 매칭

* **목표**: 두 문자열(str, pat)에서 `pat`의 모든 등장 위치와 횟수 출력
* **구현 파일**:

  * `hw1_naive.c` (O(mn) 나이브)
  * `hw1_kmp.c`   (O(m+n) KMP)
  * `hw1_problem2.c` (최대 제곱 반복 수 계산)
* **빌드 & 실행**:

  ```bash
  cd cse3080_hw1_학번/problem1 && make
  ./hw1_naive < string.txt pattern.txt
  ./hw1_kmp  < string.txt pattern.txt

  cd ../problem2 && make
  ./hw1_problem2 < input.txt
  ```

### 과제 2: 최소 신장 트리 (MST)

* **목표**: 가중 무향 그래프의 최소 신장 트리를 Kruskal로 계산
* **구현 파일**: `fp1.c` (Kruskal + 최소 힙 + Disjoint Set)
* **빌드 & 실행**:

  ```bash
  cd cse3080_hw2_학번 && make
  ./fp1 input.txt
  ```

---

## 2. Computer Programming Ⅱ 팀 프로젝트: Pumpkin

프로젝트명: 이미지 수직 뒤집기 (LET’S FLIP THE IMAGE UPSIDE DOWN)

### 개요

PNG 라이브러리(libpng)를 사용하여 입력 이미지를 수직 방향으로 뒤집어 출력하는 간단한 C++ 프로그램

### 구성

```
pumpkin_flip/
  ├── Reverse_Image.cpp   # 메인 소스 코드
  ├── Makefile
  └── input.png           # 테스트용 예시 이미지
```

### 주요 기능

* `read_png_file`: PNG 이미지 읽기
* `flip_image`: 이미지의 행(row)을 뒤집어 수직 반전 처리
* `write_png_file`: 결과를 PNG 파일로 출력
* 예외 처리(runtime\_error)로 파일 입출력 및 libpng 오류 처리

### 빌드 & 실행

```bash
cd pumpkin_flip
make          # Makefile을 통해 Result 실행 파일 생성
./Result      # 실행 시 output.png 생성 (input.png 수직 반전)
```

### 참고

* Ubuntu 20.04 환경, VS Code 권장
* libpng-dev 설치 필요 (e.g., `sudo apt install libpng-dev`)

---

## 라이선스

모든 코드에 대해 MIT License 적용
