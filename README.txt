# Pumpkin 프로젝트: 이미지 수직 뒤집기

PNG 라이브러리(libpng)를 사용하여 입력 이미지를 수직 반전 처리하는 C++ 프로그램

## 프로젝트 구조

```
pumpkin_flip/
├─ Reverse_Image.cpp   # 메인 소스 코드
├─ Makefile
└─ input.png           # 테스트용 예시 이미지
```

## 주요 기능

* **read\_png\_file**: PNG 이미지 파일 읽기
* **flip\_image**: 이미지의 각 행(row)을 뒤집어 수직 반전 처리
* **write\_png\_file**: 처리된 이미지를 PNG 파일로 출력
* 런타임 오류 발생 시 예외 처리(runtime\_error)

## 빌드 및 실행

```bash
cd pumpkin_flip
make       # 실행 파일 'Result' 생성
./Result   # 실행 시 output.png 생성 (input.png 수직 반전)
```

## 라이선스

MIT License
