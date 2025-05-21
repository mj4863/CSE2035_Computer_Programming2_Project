## Computer Programming Ⅱ 팀 프로젝트: Pumpkin

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
