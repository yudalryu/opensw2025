#!/bin/bash

# 현재 디렉토리 내 *.sh 파일 개수 저장
SHCNT=$(find . -maxdepth 1 -name "*.sh" | wc -l)

# 변수 출력
echo "현재 디렉토리 내 *.sh 파일 개수: $SHCNT"