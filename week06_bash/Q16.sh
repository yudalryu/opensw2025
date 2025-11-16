#!/bin/bash

file_wordcnt() {
    # 파일 존재 여부 확인
    if [ -e "$1" ]; then
        count=$(wc -w < "$1")
        echo "$1 파일의 단어는 $count개 입니다."
        return 0
    else
        echo "$1 파일은 존재하지 않습니다."
        return 1
    fi
}

read -p "Enter a file name: " FILE
file_wordcnt "$FILE"
echo "file_wordcnt 함수의 종료 상태: $?"
